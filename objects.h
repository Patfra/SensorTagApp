//
// Created by patryk on 31.05.18.
//

#ifndef SENSORTAGAPP_OBJECTS_H
#define SENSORTAGAPP_OBJECTS_H

#include <iostream>
#include <queue>
#include <unistd.h>
#include <chrono>

class Dane
{
private:
    float buffer[9];
    int size = 9;
public:
    float * get(){ return buffer;};

    void  set(float * buf);
    friend std::ostream & operator<< (std::ostream &wyjscie, const Dane &s);
};

void random_dane(std::queue <Dane>* kolejka, int n);

#endif //SENSORTAGAPP_OBJECTS_H
