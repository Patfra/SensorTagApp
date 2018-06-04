//
// Created by noga on 29.05.18.
//

#ifndef SENSORTAGAPP_WATKI_H
#define SENSORTAGAPP_WATKI_H

#include "rw.h"
#include "config_st.h"
#include "objects.h"
#include <queue>

using namespace std;

struct Argument{
    SensorTag* Czujnik;
    //float* result;
    queue <ST_Data> *kolejka;
    gatt_connection_t *polaczenia;
};

void *timed_loop(void* args);
void create_threads(int *amount, SensorTag* strukturki, queue <ST_Data> *kju, gatt_connection_t ** conns);//tworzy wątki i je od razu odpala
void make_uuid(char* what_to_read, uuid_t new_uuid);


#endif //SENSORTAGAPP_WATKI_H
