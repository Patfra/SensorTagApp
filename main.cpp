//
// Created by patryk on 28.05.18.
//


//Includes
#include "conversions.h"
#include "rw.h"
#include "objects.h"
#include "config_st.h"
#include "watki.h"


using namespace std;

int main(int argc, char *argv[]) {

    queue <ST_Data> *data_buf;

    SensorTag *test;                    //SensorTag array
    int sensor_amount = 0;              //Amount of SensorTag
    gatt_connection_t ** connections;   //Connections array

    //Reading configuration file
    test = read_config(&sensor_amount);

    data_buf = new queue <ST_Data>[sensor_amount];

    cout << sensor_amount<< endl<< endl<< endl;

    //Connecting to SensprTags and configuring them

    connections = config_st(test,sensor_amount);

    //Creating and enabling threads

    create_threads(sensor_amount,test,data_buf,connections);

    cout << "---------CLOSING CONNECTIONS---------" <<endl;

    //Closing threads
    for (int i = 0; i < sensor_amount; ++i) {
        if(connections[i]!= nullptr)
            gattlib_disconnect(connections[i]);
    }


    cout << "---------CLOSING APP---------" <<endl;
    //Final cleaning of the memory
    delete [] test;
    delete [] connections;
    delete [] data_buf;
    return 0;
}






