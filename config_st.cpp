//
// Created by patryk on 02.06.18.
//

#include <bluetooth/sdp.h>
#include "config_st.h"



using namespace std;

static uuid_t g_uuid;


int simple_write_read(gatt_connection_t *connection, char *char_name, uint8_t *buffer, size_t *len) {
    gattlib_string_to_uuid(char_name, strlen(char_name) + 1, &g_uuid);
    return gattlib_read_char_by_uuid(connection, &g_uuid, buffer, len);
}
char * simple_write_read(gatt_connection_t *connection, char *char_name, int char_value){
    gattlib_string_to_uuid(char_name, strlen(char_name) + 1, &g_uuid);
    char value[5];
    period2write(char_value, value);
    printf("%d\n%s\n", g_uuid, g_uuid);
    cout << value <<endl;
    int ret=gattlib_write_char_by_uuid(connection, &g_uuid, value, sizeof(value));
    return value;
}



int write2sensor(gatt_connection_t* connection, char * char_name ,bool char_value) {

    char * tmp_uuid;
    char * value;
    uuid_t g_uuid;
    string  char_name_str = char_name;
    tmp_uuid = mergeUuid(&char_name_str);
    gattlib_string_to_uuid(tmp_uuid, strlen(tmp_uuid) + 1, &g_uuid);
    value = conf2write(char_value, 2);
    cout << char_name << ' ' << char_name_str << ' ' << tmp_uuid << ' ' << value  << endl; //do debugowania
    return gattlib_write_char_by_uuid(connection, &g_uuid, value, sizeof(value));
}
int write2sensor(gatt_connection_t* connection, char * char_name ,int char_value) {

    char * tmp_uuid;
    char value[5];

    string  char_name_str = char_name;
    tmp_uuid = mergeUuid(&char_name_str);
    gattlib_string_to_uuid(tmp_uuid, strlen(tmp_uuid) + 1, &g_uuid);
    period2write(char_value, value);
    cout << tmp_uuid << ' ' << value  << endl;  //do debugowania
    return gattlib_write_char_by_uuid(connection, &g_uuid, value, sizeof(value));
}
int write2sensor(gatt_connection_t* connection, int char_value, int char_range) {

    char * tmp_uuid;
    char * value;

    string  char_name_str = ST_UUID_MOV_CONFIGURATION;
    tmp_uuid = mergeUuid(&char_name_str);
    gattlib_string_to_uuid(tmp_uuid, strlen(tmp_uuid) + 1, &g_uuid);
    value = mov2write(char_value, char_range);
    cout << tmp_uuid << ' ' << value << "   " << char_range << endl; //do debugowania
    return gattlib_write_char_by_uuid(connection, &g_uuid, value, sizeof(value));
}

//Convert milliseconds to hex
void period2write(int period, char *str_period){
    str_period[0]='0';
    str_period[1]= 'x';
    str_period[2] = HEX_TAB[period/160];
    str_period[3] = HEX_TAB[(period/10)%16];
    str_period[4]= '\0';
}

//Returning the appropriate string depending on the sensor configuration
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

//Returning the valid UUID address base on makros from config_st.h
char * mergeUuid(string* str2){
    string str1 = ST_UUID_TEMPLATE;
    auto n = (int)str2->length();
    str1.replace(str1.begin()+n,str1.begin()+2*n ,*str2);
    auto str3 = new char [str1.length()+1];
    strcpy (str3, str1.c_str());
    return str3;
}


gatt_connection_t ** config_st(SensorTag* sensors, int sensors_amount){

    uint8_t buffer[100];
    int ret;
    size_t len;
    //Table with connections
    auto connection = new gatt_connection_t*[sensors_amount];

    // Sensor configuration
    for (int j = 0; j < sensors_amount; ++j) {
        cout <<"Attempt to connect to SensorTag with address: " << sensors[j].IP.c_str()<<endl;
        const char * addr = sensors[j].IP.c_str();
        //3 attempts
        for (int i = 0; i < 3; ++i) {


            //BDADDR_LE_RANDOM - for connecting with nRF app on the phone, BDADDR_LE_PUBLIC for SensorTag


            connection[j] = gattlib_connect(nullptr, addr, BDADDR_LE_PUBLIC, BT_SEC_LOW, 0, 0);
            usleep((__useconds_t)500000);
            if (connection[j] != nullptr){
                cout << "Connected to " << sensors[0].IP.c_str() << endl;
                break;
            }
        }
        if (connection[j] == nullptr){
            fprintf(stderr, "Fail to connect to the bluetooth device.\n");
            continue;
        }
//---------------------------------------------------------------------------------------------------------------------
        //DEBUGGING
//        long int value_data;
//        auto tmp_uuid = (char *)"F000AA02-0451-4000-B000-000000000000";
//        gattlib_string_to_uuid(tmp_uuid, strlen(tmp_uuid) + 1, &g_uuid);
//        char value[5] = "0x01";
//        printf("%d\n\n", g_uuid);
//        if ((strlen(value) >= 2) && (value[0] == '0') && (value[0] == 'x')) {
//            value_data = strtol(value, NULL, 0);
//        } else {
//            value_data = strtol(value, NULL, 16);
//        }
//        printf("Value to write: 0x%lx\n", value_data);
//        uint16_t hnd = 0x0027;
//        uint16_t data = 0x01;
//        size_t data_len = sizeof(data);
//        //int ret=gattlib_write_char_by_uuid(connection[j], &g_uuid, buffer, sizeof(buffer));
//        int ret=gattlib_write_char_by_handle(connection[j], hnd , &data, data_len);
//        cout << endl << len << endl<< ret << endl;
//        for (int k = 0; k < len; ++k) {
//            cout << (int)buffer[k];
//        }
//        cout << endl;
//
//        int valueee =300;
//        tmp_uuid = (char *)"00002a39-0000-1000-8000-00805f9b34fb";
//        char * value = simple_write_read(connection[j], tmp_uuid, valueee);
//        cout /*<< tmp_uuid*/ << "    " << value << "    " << valueee << endl;  //do debugowania
//        cout << "zapisane"<< endl;
// ret =simple_write_read(connection[j] , "F000AA02-0451-4000-B000-000000000000", buffer, &len);
//        printf("Read UUID completed: ");
//        for (int i = 0; i < len; i++)
//            printf("%02x ", buffer[i]);
//        printf("\n");
//---------------------------------------------------------------------------------------------------------------------



        //Temperature sensor
        ret = write2sensor(connection[j], (char *)ST_UUID_TEMP_CONFIGURATION, sensors[j].TempConf);
        ret =simple_write_read(connection[j] , "F000AA02-0451-4000-B000-000000000000", buffer, &len);
        printf("Read UUID completed: ");
        for (int i = 0; i < len; i++)
            printf("%02x ", buffer[i]);
        printf("\n");
        assert(ret == 0);

        //Humidity sensor
        ret = write2sensor(connection[j], (char *)ST_UUID_HUM_CONFIGURATION, sensors[j].HumConf);
        ret =simple_write_read(connection[j] , "F000AA22-0451-4000-B000-000000000000", buffer, &len);
        printf("Read UUID completed: ");
        for (int i = 0; i < len; i++)
            printf("%02x ", buffer[i]);
        printf("\n");
        assert(ret == 0);

        //Pressure sensor
        ret = write2sensor(connection[j], (char *)ST_UUID_PRESS_CONFIGURATION, sensors[j].PressConf);
        ret =simple_write_read(connection[j] , "F000AA42-0451-4000-B000-000000000000", buffer, &len);
        printf("Read UUID completed: ");
        for (int i = 0; i < len; i++)
            printf("%02x ", buffer[i]);
        printf("\n");
        assert(ret == 0);


        //Optical sensor
        ret = write2sensor(connection[j], (char *)ST_UUID_OPT_CONFIGURATION, sensors[j].OptConf);
        ret =simple_write_read(connection[j] , "F000AA72-0451-4000-B000-000000000000", buffer, &len);
        printf("Read UUID completed: ");
        for (int i = 0; i < len; i++)
            printf("%02x ", buffer[i]);
        printf("\n");
        assert(ret == 0);

        //Movement sensor (Accelerometers, Gyroscopes, Magnetometers)
        ret = write2sensor(connection[j], sensors[j].MovConf, sensors[j].MovRange );
        ret =simple_write_read(connection[j] , "F000AA82-0451-4000-B000-000000000000", buffer, &len);
        printf("Read UUID completed: ");
        for (int i = 0; i < len; i++)
            printf("%02x ", buffer[i]);
        printf("\n");
        assert(ret == 0);

        //PERIODS
        ret = write2sensor(connection[j], (char *)ST_UUID_TEMP_PERIOD, sensors[j].Per);
        ret =simple_write_read(connection[j] , "F000AA03-0451-4000-B000-000000000000", buffer, &len);
        printf("Read UUID completed: ");
        for (int i = 0; i < len; i++)
            printf("%02x ", buffer[i]);
        printf("\n");
        assert(ret == 0);
        ret = write2sensor(connection[j], (char *)ST_UUID_PRESS_PERIOD, sensors[j].Per);
        assert(ret == 0);
        ret = write2sensor(connection[j], (char *)ST_UUID_HUM_PERIOD, sensors[j].Per);
        assert(ret == 0);
        ret = write2sensor(connection[j], (char *)ST_UUID_OPT_PERIOD, sensors[j].Per);
        assert(ret == 0);
        ret = write2sensor(connection[j], (char *)ST_UUID_MOV_PERIOD, sensors[j].Per);
        assert(ret == 0);

    }
    return connection;


}