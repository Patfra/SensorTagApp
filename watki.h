//
// Created by noga on 29.05.18.
//

#ifndef SENSORTAGAPP_WATKI_H
#define SENSORTAGAPP_WATKI_H

#include "rw.h"
#include "config_st.h"
#include "objects.h"
#include <queue>

static bool stop_app;

struct Argument{
    SensorTag* Czujnik;
    //float* result;
    std::queue <ST_Data> *kolejka;
    gatt_connection_t *polaczenia;
};


void *timed_loop(void* args);
void create_threads(int amount, SensorTag* strukturki, std::queue <ST_Data> *kju, gatt_connection_t ** conns);//tworzy wątki i je od razu odpala
void make_uuid(char* what_to_read, uuid_t new_uuid);


#endif //SENSORTAGAPP_WATKI_H
