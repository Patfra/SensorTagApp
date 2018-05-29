//
// Created by michal on 5/29/18.
//

using namespace std;
#include "rw.h"

void write (float buff[], bool flag) {
    fstream file;
    int i;
    int end;
    int numer = 2;      // TODO skad to bedzie brane?
    char ajpi[] = "192.168.123.45"; // i to
    file.open ("/home/michal/SensorTagApp/ST_"+ std::to_string(numer) + "_data_out.csv" , ios::app); // TODO jest na sztywno bo CLion jest zjebany
    if (file.is_open())
    {
        chrono::system_clock::time_point now = chrono::system_clock::now();
        time_t tt;
        tt = chrono::system_clock::to_time_t ( now);
        string t = ctime(&tt);
        file.seekg (0, ios::end);
        end = file.tellg();
        if (end == 0)
        {
            file << "Data from SensorTag nr " << numer << " ., " << ajpi << "\n";
            if (flag == 0)
            {
                file << "Timestamp, ObjectTemp, AmbienceTemp, GyroX, GyroY, GyroZ, Humidity, Pressure, Brightness\n";
            }
            else
            {
                file << "Timestamp,ObjectTemp, AmbienceTemp, AccX, AccY, AccZ, Humidity, Pressure, Brightness\n";
            }
        }
        file << t.substr(0, t.length()-1) <<",";
        for(i = 0; i < 8 ; i++)  // TODO size of tab (hardcoded)
        {
            file << buff[i] << ",";
        }
        file << endl;
        file.close();
    }
    else cout << "Unable to open file";
}

SensorTag* read_config()
{
    ifstream file;
    string data;
    static SensorTag records[2]; // TODO na sztywno ilosc
    int i=0;
    file.open ("/home/michal/SensorTagApp/sensorconfig.csv"); // TODO jest na sztywno bo CLion jest zjebany
    if (file.is_open())
    {
        getline(file, data); // ignore first two lines
        getline(file, data);
        while (getline(file, data))
        {
            istringstream iss(data);
            string token;
            getline(iss, token, ',');
            getline(iss, token, ',');
            records[i].IP = token;
            getline(iss, token, ',');
            records[i].TempConf = stoi(token);
            getline(iss, token, ',');
            records[i].TempPer = stoi(token);
            getline(iss, token, ',');
            records[i].MovConf = stoi(token);
            getline(iss, token, ',');
            records[i].MovRange = stoi(token);
            getline(iss, token, ',');
            records[i].MovPer = stoi(token);
            getline(iss, token, ',');
            records[i].HumConf = stoi(token);
            getline(iss, token, ',');
            records[i].HumPer = stoi(token);
            getline(iss, token, ',');
            records[i].PressConf = stoi(token);
            getline(iss, token, ',');
            records[i].PressPer = stoi(token);
            getline(iss, token, ',');
            records[i].OptConf = stoi(token);
            getline(iss, token, ',');
            records[i].OptPer = stoi(token);
            i++;
        }
        return records;
    }
    else
    {
        cout << "Unable to open file";
        return NULL;
    }
}


//int main() {
//    float bufor[] = {12.5, 123.34, 67.3, 45.3, 22.0, 45.93, 456.6, 33.67};
//    bool flaga = 0;
//    int j;
//    SensorTag *test;
//    for (j=0; j<10; j++)
//    {
//        write(bufor, flaga);
//    }
//    test = read_config();
//    for (j=0; j<2; j++)
//    {
//        cout << test[j].IP << " " << test[j].TempConf << " " << test[j].MovPer << endl;
//    }
//}