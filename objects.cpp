//
// Created by patryk on 31.05.18.
//

#include "objects.h"

using namespace std;

void ST_Data::set(float * buf, long timestamp_new){
    int i = 0;
    while(i <= 9)
    {
        buffer[i] = buf[i];
        i++;
    }
    timestamp=timestamp_new;
}



void random_dane(queue <ST_Data>* kolejka, int n){
    ST_Data new_buf;
    for(int i = 0; i < n; i++) {
        float tmp[] = {rand()%100,rand()%100,rand()%100,rand()%100,
                       rand()%100,rand()%100,rand()%100,rand()%100};
        chrono::milliseconds ms = chrono::duration_cast< chrono::milliseconds >( chrono::system_clock::now().time_since_epoch());
        long milis = ms.count();
        new_buf.set(tmp,milis);
        //usleep(200000);
        kolejka->push(new_buf);
    }
}

ostream & operator<< (ostream &wyjscie, const ST_Data &s) {
    int i = 0;
    wyjscie << s.timestamp << ' ';
    while(i <= s.size)
    {
        wyjscie << s.buffer[i] << ' ';
        i++;
    }
    return wyjscie << endl;
}
