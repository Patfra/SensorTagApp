//
// Created by michal on 5/29/18.
//

using namespace std;
#include "rw.h"

void write (float buff[], bool flag, int ST_number, string ST_IP) {
    fstream file;
    int i;
    int end;
    file.open ("../ST_"+ std::to_string(ST_number) + "_data_out.csv" , ios::app);
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
            file << "Data from SensorTag nr " << ST_number << " ., " << ST_IP << "\n";
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
    else cout << "Unable to open file" << endl;
}

SensorTag* read_config(int * sensor_amount)
{
    ifstream file;
    string data;
    int i=0;
    file.open ("../sensorconfig.csv");
    if (file.is_open())
    {
        getline(file, data);
        istringstream iss(data);
        string token;
        getline(iss, token, ',');
        getline(iss, token, ',');
        *sensor_amount = stoi(token);
        static SensorTag records[2];
        getline(file, data); // ignore second line
        while (getline(file, data))
        {
            istringstream iss(data);
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
        cout << "Unable to open file" << endl;
        return NULL;
    }
}
