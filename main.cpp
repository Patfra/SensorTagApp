//
// Created by patryk on 28.05.18.
//

//Biblioteki zewnętrzne


//Nasze biblioteki
#include "conversions.h"
#include "rw.h"
#include "objects.h"
#include "config_st.h"



using namespace std;

int main(int argc, char *argv[]) {

    queue <ST_Data> *data_buf;
//    queue <ST_Data> data_buf;
//    ST_Data buffer;
//    float buf[]={1000.0, 12.5,123.34,67.3,45.3,22,45.93,456.6,33.67};
//    buffer.set(buf);
//    cout<< buffer;
//    data_buf.push(buffer);

    SensorTag *test;                //To jest tablica Sensortagow
    int sensor_amount = 0;          //Ilość urządzeń
    cout << "witam" <<endl;
    // Wczytywanie pliku konfiguracyjnego
    test = read_config(&sensor_amount);

    data_buf=new queue <ST_Data>[sensor_amount];

    cout << sensor_amount<< endl<< endl<< endl;

    //Łączenie z sensorami + konfiguracja ich

    cout << config_st(test,sensor_amount) <<endl;

    //Generacja randomowych danych do listy
    for (int i = 0; i < sensor_amount; ++i) {

        random_dane(&(data_buf[i]),rand()%20 +1);
    }


    // Zapisywanie do pliku

    for (int j=0; j<sensor_amount; j++)
    {
        while(!data_buf[j].empty()){
            write(&(data_buf[j]), test[j], j+1);
        }

    }

    delete [] test;
    //delete data_buf;
    return 0;
}






