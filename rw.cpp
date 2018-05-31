//
// Created by michal on 5/29/18.
//

using namespace std;
#include "rw.h"


string long2timestamp(long ms){
    std::chrono::milliseconds dur(ms);
    std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds> (dur);
    std::time_t t = s.count();
    std::size_t fractional_seconds = ms% 1000;
    string timestamp = ctime(&t), rest =  ":";
    rest += to_string(fractional_seconds);
    timestamp.insert(19, rest);
    return timestamp;
}


void write(std::queue <Dane>* buffer, bool flag, int ST_number, string ST_IP){
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
        //t.substr(0, t.length()-1)  - uciecie \n na koncu
        file.seekg (0, ios::end);
        end = file.tellg();
        if (end == 0) {
            file << "Data from SensorTag nr " << ST_number << " ., " << ST_IP << "\n";
            if (flag == 0) {
                file << "Timestamp, ObjectTemp, AmbienceTemp, GyroX, GyroY, GyroZ, Humidity, Pressure, Brightness\n";
            } else {
                file << "Timestamp,ObjectTemp, AmbienceTemp, AccX, AccY, AccZ, Humidity, Pressure, Brightness\n";
            }
        }
        //file << t.substr(0, t.length()-1) <<",";
        unsigned long buf_size=buffer->size();
        cout << buf_size;
        for (unsigned long j = 0; j < buf_size; ++j) {
            float *buff=  buffer->front().get();
            time_t ti = (time_t)(int)buff[0];
            string t = ctime(&ti);
            file <<  t.substr(0, t.length()-1) << ",";
            for(i = 1; i < 9 ; i++)  // TODO size of tab (hardcoded) - %PF zminiłme tutaj trochę
            {
                file << buff[i] << ",";
            }
            file << endl;
            buffer->pop();

        }
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
        SensorTag *records = new SensorTag[*sensor_amount];
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
            records[i].MovConf = stoi(token);
            getline(iss, token, ',');
            records[i].MovRange = stoi(token);
            getline(iss, token, ',');
            records[i].HumConf = stoi(token);
            getline(iss, token, ',');
            records[i].PressConf = stoi(token);
            getline(iss, token, ',');
            records[i].OptConf = stoi(token);
            getline(iss, token, ',');
            records[i].Per = stoi(token);
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
