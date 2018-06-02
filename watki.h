//
// Created by noga on 29.05.18.
//

#ifndef SENSORTAGAPP_WATKI_H
#define SENSORTAGAPP_WATKI_H

#include "rw.h"


void *timed_loop(void* args);
void create_threads(int *amount, SensorTag* strukturki);//tworzy wątki i je od razu odpala



#endif //SENSORTAGAPP_WATKI_H
