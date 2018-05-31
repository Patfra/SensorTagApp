//
// Created by patryk on 31.05.18.
//

#include "objects.h"

using namespace std;

void Dane::set(float * buf){
    int i = 0;
    while(i <= 9)
    {
        buffer[i] = buf[i];
        i++;
    }
}



void random_dane(queue <Dane>* kolejka, int n){
    Dane new_buf;
    for(int i = 0; i < n; i++) {
        float tmp[] = {(float)(int)(chrono::system_clock::to_time_t (chrono::system_clock::now())),
                       rand()%100,rand()%100,rand()%100,rand()%100,
                       rand()%100,rand()%100,rand()%100,rand()%100};
        new_buf.set(tmp);
        usleep(200000);
        kolejka->push(new_buf);
    }
}

ostream & operator<< (ostream &wyjscie, const Dane &s) {
    int i = 0;
    while(i <= 9)
    {
        wyjscie << s.buffer[i] << ' ';
        i++;
    }
    return wyjscie << endl;
}
