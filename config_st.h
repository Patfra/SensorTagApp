//
// Created by patryk on 02.06.18.
//

#ifndef SENSORTAGAPP_CONFIG_ST_H
#define SENSORTAGAPP_CONFIG_ST_H

#include "rw.h"
#include "gattlib/include/gattlib.h"
#include <cassert>

#define ST_UUID_TEMPLATE        "F000XXXX-0451-4000-B000-000000000000"

#define ST_UUID_TEMP_DATA           "AA01"
#define ST_UUID_TEMP_CONFIGURATION  "AA02"
#define ST_UUID_TEMP_PERIOD         "AA03"

#define ST_UUID_HUM_DATA "AA21"
#define ST_UUID_HUM_CONFIGURATION "AA22"
#define ST_UUID_HUM_PERIOD "AA23"

#define ST_UUID_PRESS_DATA          "AA41"
#define ST_UUID_PRESS_CONFIGURATION "AA42"
#define ST_UUID_PRESS_PERIOD        "AA43"

#define ST_UUID_MOV_DATA            "AA81"
#define ST_UUID_MOV_CONFIGURATION   "AA82"
#define ST_UUID_MOV_PERIOD          "AA83"

#define ST_UUID_OPT_DATA            "AA71"
#define ST_UUID_OPT_CONFIGURATION   "AA72"
#define ST_UUID_OPT_PERIOD          "AA73"

#define ST_ENABLE_2B        "0x01"
#define ST_ENABLE_4B        "0x0001"
#define ST_DISABLE_2B       "0x00"
#define ST_DISABLE_4B       "0x0000"

const char HEX_TAB[]="0123456789ABCDEF";

typedef enum { READ, WRITE} operation_t;
char* mergeUuid(std::string* str2);

//Funkcje zamianiające liczby na tablice z wartościami do zapisu do ST
char *conf2write(bool bit , int size);
char * period2write(int period);
char *mov2write(int mov_conf, int acc_range);

//Dwie funkcjie (bool dla konfiguracji i int dla perioda)
int write2sensor(gatt_connection_t* connection, char * char_name ,bool char_value);
int write2sensor(gatt_connection_t* connection, char * char_name ,int char_value);
//Funkcja do ustawiania czujników przyśpieszenia
int write2sensor(gatt_connection_t* connection, int char_value, int char_range);


gatt_connection_t ** config_st(SensorTag* sensors, int sensors_amount);

#endif //SENSORTAGAPP_CONFIG_ST_H