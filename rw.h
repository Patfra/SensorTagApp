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

struct SensorTag{
    std::string IP;
    bool TempConf;
    int TempPer;
    int MovConf;
    int MovRange;
    int MovPer;
    bool HumConf;
    int HumPer;
    bool PressConf;
    int PressPer;
    bool OptConf;
    int OptPer;
};

void write (float buff[], bool flag, int ST_number, std::string ST_IP);

SensorTag* read_config(int * sensor_amount);

#endif //SENSORTAGAPP_RW_H
