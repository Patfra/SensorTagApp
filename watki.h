//
// Created by noga on 29.05.18.
//

#ifndef SENSORTAGAPP_WATKI_H
#define SENSORTAGAPP_WATKI_H

#include "rw.h"
#include "config_st.h"
#include "objects.h"
#include <queue>

//Variable responsible for turning off the app
static bool stop_app;

//Special structure used in passing arguments to threads responsible for reading data
struct Argument{
    SensorTag* Czujnik;
    //float* result;
    std::queue <ST_Data> *kolejka;
    gatt_connection_t *polaczenia;
};

//Special structure used in passing arguments to threads responsible for reading data
void *timed_loop(void* args);

//Creating and enabling threads
void create_threads(int amount, SensorTag* strukturki, std::queue <ST_Data> *kju, gatt_connection_t ** conns);

//Debug function
void make_uuid(char* what_to_read, uuid_t new_uuid);


#endif //SENSORTAGAPP_WATKI_H
