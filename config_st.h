//
// Created by patryk on 02.06.18.
//

#ifndef SENSORTAGAPP_CONFIG_ST_H
#define SENSORTAGAPP_CONFIG_ST_H

#include "rw.h"
#include "gattlib/include/gattlib.h"
#include <cassert>
// UUID template
#define ST_UUID_TEMPLATE        "F000XXXX-0451-4000-B000-000000000000"

// Values put in UUID template instead of XXXX to obtain valid UUID address

//Temperature sensor
#define ST_UUID_TEMP_DATA           "AA01"
#define ST_UUID_TEMP_CONFIGURATION  "AA02"
#define ST_UUID_TEMP_PERIOD         "AA03"

//Humidity sensor
#define ST_UUID_HUM_DATA            "AA21"
#define ST_UUID_HUM_CONFIGURATION   "AA22"
#define ST_UUID_HUM_PERIOD          "AA23"

//Pressure sensor
#define ST_UUID_PRESS_DATA          "AA41"
#define ST_UUID_PRESS_CONFIGURATION "AA42"
#define ST_UUID_PRESS_PERIOD        "AA43"

//Optical sensor
#define ST_UUID_OPT_DATA            "AA71"
#define ST_UUID_OPT_CONFIGURATION   "AA72"
#define ST_UUID_OPT_PERIOD          "AA73"

//Movement sensor (Accelerometers, Gyroscopes, Magnetometers)
#define ST_UUID_MOV_DATA            "AA81"
#define ST_UUID_MOV_CONFIGURATION   "AA82"
#define ST_UUID_MOV_PERIOD          "AA83"

//Definitions of valid values which can be writen to sensor
#define ST_ENABLE_2B        "0x01"      // 2 byte data
#define ST_ENABLE_4B        "0x0001"    // 4 byte data
#define ST_DISABLE_2B       "0x00"      // 2 byte data
#define ST_DISABLE_4B       "0x0000"    // 4 byte data


//Table used to convert numbers from decimal to hexagonal
const char HEX_TAB[]="0123456789ABCDEF";

char* mergeUuid(std::string* str2);

//Functions that change numbers to arrays with values which can be write to SensorTag
char *conf2write(bool bit , int size);
void period2write(int period, char * value);
char *mov2write(int mov_conf, int acc_range);

//Function writing configuration to sensor  (ON/OFF)
int write2sensor(gatt_connection_t* connection, char * char_name ,bool char_value);

//Function writing period to sensor
int write2sensor(gatt_connection_t* connection, char * char_name ,int char_value);

//Function for setting acceleration sensors
int write2sensor(gatt_connection_t* connection, int char_value, int char_range);

//Functions for debuging
char * simple_write_read(gatt_connection_t *connection, char *char_name, int char_value);
int simple_write_read(gatt_connection_t *connection, char *char_name, uint8_t *buffer, size_t *len);

//Connecting to SensprTags and configuring them
gatt_connection_t ** config_st(SensorTag* sensors, int sensors_amount);

#endif //SENSORTAGAPP_CONFIG_ST_H
