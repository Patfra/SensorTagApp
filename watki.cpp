//
// Created by noga on 29.05.18.
//

#include "watki.h"
#include "rw.h"
#include <cstdio>
#include <cstdlib>
#include <pthread.h>
#include <cstring>
#include <ctime>
#include <unistd.h>
#include <vector>
#include <iostream>



using namespace std;

void *timed_loop(void* dane){ //argumentem jest tablica struktur SensorTag
//    clock_t time = clock();
    auto struktura = (Argument*)dane;
    SensorTag* czujnik = struktura->Czujnik;
    queue <ST_Data>* results = struktura->kolejka;
    gatt_connection_t *conn = struktura->polaczenia;
    ST_Data bufor;
    float wyniki[8];
    //Przygotowanie stuffu powyżej, poniżej przygotowanie rzeczy pod funkcje czytające:
//    uint8_t buffer_temp_obj[100];
//    uint8_t buffer_temp_amb[100];
//    uint8_t buffer_temp_accx[100];
//    uint8_t buffer_temp_accy[100];
//    uint8_t buffer_temp_accz[100];
//    uint8_t buffer_temp_gyrox[100];
//    uint8_t buffer_temp_gyroy[100];
//    uint8_t buffer_temp_gyroz[100];
//    uint8_t buffer_temp_hum[100];
//    uint8_t buffer_temp_press[100];
//    uint8_t buffer_temp_opt[100];
//    int ret_temp,ret_amb,ret_accx,ret_accy,ret_accz,ret_gyrox,ret_gyroy,ret_gyroz,ret_hum,ret_press,ret_opt;
//    size_t len;
//    static uuid_t tempobj_u, acc_u, gyro_u, hum_u, press_u, opt_u;
//    make_uuid((char*)ST_UUID_TEMP_DATA, tempobj_u);
//    make_uuid((char*)ST_UUID_HUM_DATA, acc_u);
//    make_uuid((char*)ST_UUID_PRESS_DATA, press_u);
//    make_uuid((char*)ST_UUID_OPT_DATA, opt_u);



    while(!stop_app){
        chrono::milliseconds ms = chrono::duration_cast< chrono::milliseconds >( chrono::system_clock::now().time_since_epoch());
        long milis = ms.count();

        cout << milis << "     "<<  czujnik->IP.c_str()[0]<< endl;

        //TODO do usunięcia - test buforów z wątkami
        random_dane(results,1);

//        if(czujnik->TempConf){
//            len = sizeof(ret_temp);
//            ret_temp = gattlib_read_char_by_uuid(conn, &tempobj_u, buffer_temp_obj, &len);
//            printf("%d", ret_temp);
//            //ret_amb = gattlib_read_char_by_uuid(conn, &tempobj_u, buffer_temp_amb, &len);
//            //wyniki[0] = FUNKCJA DO CZYTANIA TEMPERATURY OBJ;
//            //wyniki[1] = FUNKCJA DO CZYTANIA TEMPERATURY AMBIENT;
//        }
//        else{
//
//            wyniki[0] = 0;
//            wyniki[1] = 0;
//        }
//        //TEMPERATURE READ END-------------
//
//        if(czujnik->MovConf){
//            //wyniki[2] = OŚ X Akcelero/;
//            //wyniki[3] = OŚ Y Akcelero/;
//            //wyniki[4] = OŚ Z Akcelero/;
//        }
//        else if(czujnik->MovConf == 0){
//            wyniki[2] = 0;
//            wyniki[3] = 0;
//            wyniki[4] = 0;
//        }
//        else if(czujnik->MovConf == 2){
//            //wyniki[2] = OŚ X żyro;
//            //wyniki[3] = OŚ Y żyro;
//            //wyniki[4] = OŚ Z żyro
//        }
//        //GYRO/ACCEL READ END---------------
//        if(czujnik->HumConf){
//            //wyniki[5] = FUNKCJA DO CZYTANIA WILGOTNOŚCI;
//        }
//        else{
//            wyniki[5] = 0;
//        }
//        //HUMIDITY READ END-------------
//        if(czujnik->PressConf){
//            //wyniki[6] = FUNKCJA DO CZYTANIA ciśnienia;
//        }
//        else{
//            wyniki[6] = 0;
//        }
//        //PRESSURE READ END-------------
//        if(czujnik->OptConf){
//            //wyniki[7] = FUNKCJA DO CZYTANIA OPTYKI;
//        }
//        else{
//            wyniki[7] = 0;
//        }
//        //OPTICAL READ END-------------
//        bufor.set(wyniki,milis);
//        results->push(bufor);
        usleep((__useconds_t)czujnik->Per*1000);
        //PRZEKAZANIE WARTOŚCI

    }

}

void create_threads(int amount, SensorTag* strukturki, queue <ST_Data> *kju, gatt_connection_t ** conns){

    vector <pthread_t> threadz;
    vector <Argument> argumenty;
    stop_app = false;

    for(int i=0;i< amount;i++){ //stworzenie wektora wątków
        pthread_t threaddy;
        threadz.push_back(threaddy);
    }

    for(int j=0;j< amount;j ++){ //stworzenie struktury, podawanej jako argumenty
        auto struktura = Argument();
        struktura.kolejka = &kju[j];
        struktura.Czujnik = &strukturki[j];
        struktura.polaczenia = conns[j];
        argumenty.push_back(struktura);
    }


    for(int k=0;k<amount;k++){ //odpalenie wątków
        pthread_create(&threadz[k], nullptr,timed_loop,&argumenty[k]);
    }

    //Wątek dla zapisu anych do CSV

    auto wd = Write_data();
    wd.kolejka = kju;
    wd.Czujnik = strukturki;
    wd.size = amount;

    pthread_t threaddy;
    threadz.push_back(threaddy);
    pthread_create(&threadz[threadz.size()-1],nullptr,write, &wd);

    //Zatrzymywanie zbierania danych
    cout << "Press any key to stop gathering data" << endl;
    cin.get();
    stop_app = true;



    for(int l=0;l<amount+1;l++){//join, niezbędny do działania ammount +1 bo wątek dla zapisywania
        pthread_join(threadz[l], nullptr);
    }
}

void make_uuid(char* what_to_read, uuid_t new_uuid){

    char* zmienna = what_to_read;
    string ujd = zmienna;
    char* temp = mergeUuid(&ujd);
    gattlib_string_to_uuid(temp,strlen(temp)+1,&new_uuid);

}