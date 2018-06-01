//
// Created by patryk on 28.05.18.
//

//Biblioteki zewnętrzne
#include "gattlib/include/gattlib.h"

//Nasze biblioteki
#include "conversions.h"
#include "rw.h"
#include "objects.h"



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

    // Wczytywanie pliku konfiguracyjnego
    test = read_config(&sensor_amount);

    data_buf=new queue <ST_Data>[sensor_amount];

    cout << sensor_amount<< endl<< endl<< endl;

    //Generacja randomowych danych do listy
    for (int i = 0; i < sensor_amount; ++i) {

        random_dane(&(data_buf[i]),rand()%20 +1);
    }

    //TODO %PF Testowanie czasu. Ja to kiedyś usunę, na razie zakomentowane jest
//    using namespace std::chrono;
//    for (int k = 0; k < 10; ++k) {
//        milliseconds ms = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
//        long milis = ms.count();
//        string czas = long2timestamp(milis);
//        std::cout << czas << std::endl;
//        usleep(2000);
//    }



    // Zapisywanie do pliku
//    for(int i = 0 ; i < 9; i++)
//        cout << data_buf.front();
//
//    for (int j=0; j<sensor_amount; j++)
//    {
//        int flag= test[j].MovConf == 2?1:0;
//        write(data_buf.front().get(), flag, j+1, test[j].IP);
//    }

    for (int j=0; j<sensor_amount; j++)
    {
        int flag= test[j].MovConf == 2?1:0;
        while(data_buf[j].empty() != true){
            write(&(data_buf[j]), flag, j+1, test[j].IP);
        }

    }

    delete [] test;
    //delete data_buf;
    return 0;
}






