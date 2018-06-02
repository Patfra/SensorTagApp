//
// Created by noga on 29.05.18.
//

#include "watki.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <vector>

struct Argument{
    SensorTag* Czujnik;
    float* result;
};

using namespace std;

void *timed_loop(void* dane){ //argumentem jest tablica struktur SensorTag
//    clock_t time = clock();
    Argument* struktura = (Argument*)dane;
    SensorTag* czujnik = struktura->Czujnik;
    float* wyniki = struktura->result;

    while(1){
        if(czujnik->TempConf){
            //wyniki[0] = FUNKCJA DO CZYTANIA TEMPERATURY;
        }
        else{
            wyniki[0] = 0;
        }
        //TEMPERATURE READ-------------

        if(czujnik->MovConf){
            //wyniki[1] = OŚ X Akcelero/;
            //wyniki[2] = OŚ Y Akcelero/;
            //wyniki[3] = OŚ Z Akcelero/;
        }
        else if(czujnik->MovConf == 0){
            wyniki[1] = 0;
            wyniki[2] = 0;
            wyniki[3] = 0;
        }
        else if(czujnik->MovConf == 2){
            //wyniki[1] = OŚ X żyro;
            //wyniki[2] = OŚ Y żyro;
            //wyniki[3] = OŚ Z żyro
        }
        //GYRO/ACCEL READ---------------
        if(czujnik->HumConf){
            //wyniki[4] = FUNKCJA DO CZYTANIA WILGOTNOŚCI;
        }
        else{
            wyniki[4] = 0;
        }
        //HUMIDITY READ-------------
        if(czujnik->PressConf){
            //wyniki[5] = FUNKCJA DO CZYTANIA ciśnienia;
        }
        else{
            wyniki[5] = 0;
        }
        //PRESSURE READ-------------
        if(czujnik->OptConf){
            //wyniki[6] = FUNKCJA DO CZYTANIA OPTYKI;
        }
        else{
            wyniki[6] = 0;
        }
        //OPTICAL READ-------------
        sleep(czujnik->Per);

    }

}

void create_threads(int *amount, SensorTag* strukturki){

    vector <pthread_t> threadz;
    vector <Argument*> argumenty;

    for(int i=0;i<*amount;i++){ //stworzenie wektora wątków
        pthread_t threaddy;
        threadz.push_back(threaddy);
    }

    for(int j=0;j<*amount;j ++){ //stworzenie struktury, podawanej jako argumenty
        Argument* struktura;

        float *tab = new float[8];
        struktura->Czujnik = &strukturki[j];
        struktura->result = tab;
        argumenty.push_back(struktura);
    }

    for(int k=0;k<*amount;k++){ //odpalenie wątków
        pthread_create(&threadz[k],NULL,timed_loop,&argumenty[k]);
    }

    for(int l=0;l<*amount;l++){//join, niezbędny do działania
        pthread_join(threadz[l], NULL);
    }

}
