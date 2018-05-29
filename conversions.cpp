//
// Created by patryk on 28.05.18.
//

#include "conversions.h"

void TempConvert(uint16_t rawAmbTemp, uint16_t rawObjTemp, float *tAmb, float *tObj)
{
    const float SCALE_LSB = 0.03125;
    float t;
    int it;

    it = (int)((rawObjTemp) >> 2);
    t = ((float)(it)) * SCALE_LSB;
    *tObj = t;

    it = (int)((rawAmbTemp) >> 2);
    t = (float)it;
    *tAmb = t * SCALE_LSB;
}

float GyroConvert(int16_t data)
{
    //-- calculate rotation, unit deg/s, range -250, +250
    return (data * 1.0) / (65536 / 500);
}


float AccConvert(int16_t rawData, int accRange)
{
    float v;

    switch (accRange)
    {
        case ACC_RANGE_2G:
            //-- calculate acceleration, unit G, range -2, +2
            v = (rawData * 1.0) / (32768/2);
            break;

        case ACC_RANGE_4G:
            //-- calculate acceleration, unit G, range -4, +4
            v = (rawData * 1.0) / (32768/4);
            break;

        case ACC_RANGE_8G:
            //-- calculate acceleration, unit G, range -8, +8
            v = (rawData * 1.0) / (32768/8);
            break;

        case ACC_RANGE_16G:
            //-- calculate acceleration, unit G, range -16, +16
            v = (rawData * 1.0) / (32768/16);
            break;
    }

    return v;

}



float MagConvert(int16_t data)
{
    //-- calculate magnetism, unit uT, range +-4900
    return 1.0 * data;
}


void HumidConvert(uint16_t rawTemp, uint16_t rawHum,
                  float *temp, float *hum)
{
    //-- calculate temperature [°C]
    *temp = ((float)(int16_t)rawTemp / 65536)*165 - 40;

    //-- calculate relative humidity [%RH]
    rawHum &= ~0x0003; // remove status bits
    *hum = ((float)rawHum / 65536)*100;
}

float BaroConvert(uint32_t rawValue)
{
    return rawValue / 100.0f;
}


float OptConvert(uint16_t rawData)
{
    uint16_t e, m;

    m = rawData & 0x0FFF;
    e = (rawData & 0xF000) >> 12;

    /** e on 4 bits stored in a 16 bit unsigned => it can store 2 << (e - 1) with e < 16 */
    e = (e == 0) ? 1 : 2 << (e - 1);

    return m * (0.01 * e);
}