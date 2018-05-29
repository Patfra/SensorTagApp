//
// Created by patryk on 28.05.18.
//

#ifndef SENSORTAGAPP_CONVERSIONS_H
#define SENSORTAGAPP_CONVERSIONS_H


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Accelerometer ranges
#define ACC_RANGE_2G      0
#define ACC_RANGE_4G      1
#define ACC_RANGE_8G      2
#define ACC_RANGE_16G     3

void TempConvert(uint16_t rawAmbTemp, uint16_t rawObjTemp, float *tAmb, float *tObj);

float GyroConvert(int16_t data);

float AccConvert(int16_t rawData, int accRange);

float MagConvert(int16_t data);

void HumidConvert(uint16_t rawTemp, uint16_t rawHum, float *temp, float *hum);

float BaroConvert(uint32_t rawValue);

float OptConvert(uint16_t rawData);

#endif //SENSORTAGAPP_CONVERSIONS_H
