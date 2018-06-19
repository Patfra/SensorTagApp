//
// Created by patryk on 31.05.18.
//

#ifndef SENSORTAGAPP_OBJECTS_H
#define SENSORTAGAPP_OBJECTS_H

#include <iostream>
#include <queue>
#include <unistd.h>
#include <chrono>

//Class containing data of single measurement from all sensors
class ST_Data
{
private:
    float buffer[8];
    long timestamp;
    int size = 8;
public:
    float * get_data(){ return buffer;};
    int     size_buf(){ return size;};
    long    get_timestamp(){return timestamp;};
    void    set(float * buf, long timestamp_new);
    friend  std::ostream & operator<< (std::ostream &wyjscie, const ST_Data &s);
};

//Function for generating random measurements for testing threads nad writing to multiple files at once
void random_dane(std::queue <ST_Data>* kolejka, int n);

#endif //SENSORTAGAPP_OBJECTS_H
