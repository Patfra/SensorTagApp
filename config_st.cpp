//
// Created by patryk on 02.06.18.
//

#include <bluetooth/sdp.h>
#include "config_st.h"



using namespace std;




static uuid_t g_uuid;
long int value_data;

int write2sensor(gatt_connection_t* connection, char * char_name ,bool char_value) {

    char * tmp_uuid;
    char * value;
    uuid_t g_uuid;
    string  char_name_str = char_name;
    tmp_uuid = mergeUuid(&char_name_str);
    gattlib_string_to_uuid(tmp_uuid, strlen(tmp_uuid) + 1, &g_uuid);
    value = conf2write(char_value, 2);
    //cout << char_name << ' ' << char_name_str << ' ' << tmp_uuid << ' ' << value  << endl; //do debugowania
    return gattlib_write_char_by_uuid(connection, &g_uuid, value, sizeof(value));
}
int write2sensor(gatt_connection_t* connection, char * char_name ,int char_value) {

    char * tmp_uuid;
    char value[5];

    string  char_name_str = char_name;
    tmp_uuid = mergeUuid(&char_name_str);
    gattlib_string_to_uuid(tmp_uuid, strlen(tmp_uuid) + 1, &g_uuid);
    period2write(char_value, value);
    //cout << tmp_uuid << ' ' << value  << endl;  //do debugowania
    return gattlib_write_char_by_uuid(connection, &g_uuid, value, sizeof(value));
}
int write2sensor(gatt_connection_t* connection, int char_value, int char_range) {

    char * tmp_uuid;
    char * value;

    string  char_name_str = ST_UUID_MOV_CONFIGURATION;
    tmp_uuid = mergeUuid(&char_name_str);
    gattlib_string_to_uuid(tmp_uuid, strlen(tmp_uuid) + 1, &g_uuid);
    value = mov2write(char_value, char_range);
    //cout << tmp_uuid << ' ' << value  << endl; //do debugowania
    return gattlib_write_char_by_uuid(connection, &g_uuid, value, sizeof(value));
}

//Zamiana milisekund na wartoś w hex
void period2write(int period, char *str_period){
    str_period[0]='0';
    str_period[1]= 'x';
    str_period[2] = HEX_TAB[period/160];
    str_period[3] = HEX_TAB[(period/10)%16];
    str_period[4]= '\0';
}

//Funkcja zwarcające odpowiedni string w zależności od konfiguracji sensora
char *conf2write(bool bit , int size){
    char *value;
    if(size == 2)
        value = bit?(char *)ST_ENABLE_2B:(char *)ST_DISABLE_2B;
    else
        value = bit?(char *)ST_ENABLE_4B:(char *)ST_DISABLE_4B;
    return value;
}

char * mov2write(int mov_conf,int acc_range){
    char *str_mov;
    if(mov_conf == 0)
        str_mov = (char *)"0x0000";
    else {
        if (mov_conf == 1)
            str_mov = (char *)"0x0007";
        else
            switch (acc_range) {
                case 1: {
                    str_mov = (char *)"0x0138";
                    break;
                }
                case 2: {
                    str_mov = (char *)"0x0238";
                    break;
                }
                case 3: {
                    str_mov = (char *)"0x0338";
                    break;
                }
                default:{
                    str_mov = (char *)"0x0038";
                    break;

                }
            }
    }
    return str_mov;
}

//Ta funkcja pobiera jedno z makr zdefiniowanych w config_st.h i zwraca string odpowiadający danemu UUID
char * mergeUuid(string* str2){
    string str1 = ST_UUID_TEMPLATE;
    auto n = (int)str2->length();
    str1.replace(str1.begin()+n,str1.begin()+2*n ,*str2);
    auto str3 = new char [str1.length()+1];
    strcpy (str3, str1.c_str());
    return str3;
}


//Łączenie z  ST i ich konfiguracja
gatt_connection_t ** config_st(SensorTag* sensors, int sensors_amount){

    uint8_t buffer[100];
    int ret;
    size_t len;
    //Tablica połączeń
    auto connection = new gatt_connection_t*[sensors_amount];
//    if (gattlib_string_to_uuid(tmp_uuid, strlen(tmp_uuid) + 1, &g_uuid) < 0) {
//        fprintf(stderr, "Wrong characteristic.\n");
//        return 1;
//    }

    // Konfiguracja
    for (int j = 0; j < sensors_amount; ++j) {
        cout << sensors[j].IP.c_str()<<endl;
        const char * addr = sensors[j].IP.c_str();

        connection[j] = gattlib_connect(nullptr, addr, BDADDR_LE_PUBLIC, BT_SEC_LOW, 0, 0);
        if (connection[j] == nullptr) {
            connection[j] = gattlib_connect(nullptr, addr, BDADDR_LE_RANDOM, BT_SEC_LOW, 0, 0);
            if (connection[j] == nullptr) {
                fprintf(stderr, "Fail to connect to the bluetooth device.\n");
                continue;
                //return connection;
            } else {
                puts("Succeeded to connect to the bluetooth device with random address.");
            }
        } else {
            puts("Succeeded to connect to the bluetooth device.");
        }
        cout << "Connected to " << sensors[0].IP.c_str() << endl;
        //TEMPERATURA


        //ret = write2sensor(connection[j], (char *)ST_UUID_TEMP_CONFIGURATION, sensors[j].TempConf);
        //char *tmp_uuid ="f000aa01-0451-4000-b000-000000000000";
        auto tmp_uuid = (char *)"00002a38-0000-1000-8000-00805f9b34fb";
        gattlib_string_to_uuid(tmp_uuid, strlen(tmp_uuid) + 1, &g_uuid);
        ret =gattlib_read_char_by_uuid(connection[j], &g_uuid, buffer, &len);
        cout << endl << len << endl;
        for (int k = 0; k < len; ++k) {
            cout << (int)buffer[k];
        }
        cout << endl;

        int valueee =300;
        tmp_uuid = (char *)"00002a39-0000-1000-8000-00805f9b34fb";
        gattlib_string_to_uuid(tmp_uuid, strlen(tmp_uuid) + 1, &g_uuid);
        char value[5];
        period2write(valueee, value);
        cout /*<< tmp_uuid*/ << "    " << value << "    " << valueee << endl;  //do debugowania
        gattlib_write_char_by_uuid(connection[j], &g_uuid, value, sizeof(value));
        cout << "zapisane"<< endl;
//        ret = write2sensor(connection[j], (char *)ST_UUID_TEMP_CONFIGURATION, sensors[j].TempConf);
//        assert(ret == 0);
//        //CIŚNIENIE
//        ret = write2sensor(connection[j], (char *)ST_UUID_PRESS_CONFIGURATION, sensors[j].PressConf);
//        assert(ret == 0);
//        //WILGOTNOŚĆ
//        ret = write2sensor(connection[j], (char *)ST_UUID_PRESS_CONFIGURATION, sensors[j].HumConf);
//        assert(ret == 0);
//        //PRZYŚPIESZENIE
//        ret = write2sensor(connection[j], sensors[j].MovConf, sensors[j].MovRange );
//        assert(ret == 0);
//        //OKRESY
//        ret = write2sensor(connection[j], (char *)ST_UUID_TEMP_PERIOD, sensors[j].Per);
//        assert(ret == 0);
//        ret = write2sensor(connection[j], (char *)ST_UUID_PRESS_PERIOD, sensors[j].Per);
//        assert(ret == 0);
//        ret = write2sensor(connection[j], (char *)ST_UUID_HUM_PERIOD, sensors[j].Per);
//        assert(ret == 0);
//        ret = write2sensor(connection[j], (char *)ST_UUID_MOV_PERIOD, sensors[j].Per);
//        assert(ret == 0);
        //Tu się na razie rozłączam ale zrobi się że tablica connected zostanie przekazan do maina i użyta w wątkach.
        //gattlib_disconnect(connection[j]);

    }
    return connection;


}