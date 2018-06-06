//
// Created by michal on 5/29/18.
//

#ifndef SENSORTAGAPP_RW_H
#define SENSORTAGAPP_RW_H

#include <iostream>
#include <chrono>
#include <fstream>
#include <istream>
#include <sstream>
#include <ctime>

#include "objects.h"

std::string long2timestamp(long ms);

struct SensorTag{
    std::string IP;
    bool TempConf;
    int MovConf;
    int MovRange;
    bool HumConf;
    bool PressConf;
    bool OptConf;
    int Per;
};

struct Write_data{
    SensorTag* Czujnik;
    int size;
    std::queue <ST_Data> *kolejka;

};

bool write2onefile(std::queue<ST_Data>* buffer, SensorTag* config, int ST_number, std::fstream* file);

void * write(void* args);

SensorTag* read_config(int * sensor_amount);

#endif //SENSORTAGAPP_RW_H
