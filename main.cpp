//
// Created by patryk on 28.05.18.
//

#include <iostream>
#include "conversions.h"
#include "rw.h"
#include "gattlib/include/gattlib.h"
#include <queue>

using namespace std;


class Dane
{
private:
    float buffer[9];
    int size = 9;
public:
    float * get(){ return buffer;};

    void  set(float * buf){
        int i = 0;
        while(i <= 9)
        {
            buffer[i] = buf[i];
            i++;
        }
    }
    friend ostream & operator<< (ostream &wyjscie, const Dane &s);
};

ostream & operator<< (ostream &wyjscie, const Dane &s) {
    int i = 0;
    while(i <= 9)
    {
        wyjscie << s.buffer[i] << ' ';
        i++;
    }
    return wyjscie << endl;
}


int main(int argc, char *argv[]) {

    queue <Dane> data_buf;
    Dane buffer;
    float buf[]={1000.0, 12.5,123.34,67.3,45.3,22,45.93,456.6,33.67};
    buffer.set(buf);
    cout<< buffer;
    data_buf.push(buffer);

    SensorTag *test;                //To jest tablica Sensortagow
    int sensor_amount = 0;          //Ilość urządzeń

    // Wczytywanie pliku konfiguracyjnego
    test = read_config(&sensor_amount);


    cout << sensor_amount<< endl;

    //Generacja randomowych danych do listy



    // Zapisywanie do pliku
    for(int i = 0 ; i < 9; i++)
        cout << data_buf.front();

    for (int j=0; j<sensor_amount; j++)
    {
        int flag= test[j].MovConf == 2?1:0;
        write(data_buf.front().get(), flag, j+1, test[j].IP);
    }

    return 0;
}






