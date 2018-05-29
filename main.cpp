//
// Created by patryk on 28.05.18.
//

#include <iostream>
#include "conversions.h"
#include "rw.h"
#include "gattlib/include/gattlib.h"// TO DO ogarnąć bibliotekę
using namespace std;



//#include <stdio.h>  /* defines FILENAME_MAX */
//#include <unistd.h>
//#define GetCurrentDir getcwd
//
//string GetCurrentWorkingDir( void ) {
//    char buff[FILENAME_MAX];
//    GetCurrentDir( buff, FILENAME_MAX );
//    string current_working_dir(buff);
//    return current_working_dir;
//}
//
//int main(){
//    cout << endl << GetCurrentWorkingDir() << endl;
//    return 1;
//}









int main(int argc, char *argv[]) {


    float bufor[] = {12.5, 123.34, 67.3, 45.3, 22.0, 45.93, 456.6, 33.67};
    bool flaga = 0;
    int j;
    SensorTag *test;
    int sensor_amount = 0;

    test = read_config(&sensor_amount);

    for (j=0; j<2; j++)
    {
        cout << test[j].IP << " " << test[j].TempConf << " " << test[j].MovPer << endl;
    }
    cout << sensor_amount<< endl;
    for (j=0; j<sensor_amount; j++)
    {
        write(bufor, flaga, j+1, test[j].IP);
    }

    return 0;
}

//    uint8_t buffer[100];
//    int i, ret;
//    size_t len;
//    gatt_connection_t* connection;
//
//    if ((argc != 4) && (argc != 5)) {
//        usage(argv);
//        return 1;
//    }
//
//    if (strcmp(argv[2], "read") == 0) {
//        g_operation = READ;
//    } else if ((strcmp(argv[2], "write") == 0) && (argc == 5)) {
//        g_operation = WRITE;
//
//        if ((strlen(argv[4]) >= 2) && (argv[4][0] == '0') && (argv[4][0] == 'x')) {
//            value_data = strtol(argv[4], NULL, 0);
//        } else {
//            value_data = strtol(argv[4], NULL, 16);
//        }
//        printf("Value to write: 0x%lx\n", value_data);
//    } else {
//        usage(argv);
//        return 1;
//    }
//
//    if (gattlib_string_to_uuid(argv[3], strlen(argv[3]) + 1, &g_uuid) < 0) {
//        usage(argv);
//        return 1;
//    }
//
//    connection = gattlib_connect(NULL, argv[1], BDADDR_LE_PUBLIC, BT_SEC_LOW, 0, 0);
//    if (connection == NULL) {
//        fprintf(stderr, "Fail to connect to the bluetooth device.\n");
//        return 1;
//    }
//
//    if (g_operation == READ) {
//        len = sizeof(buffer);
//        ret = gattlib_read_char_by_uuid(connection, &g_uuid, buffer, &len);
//        if(ret == 0)
//            return 2;
//
//        printf("Read UUID completed: ");
//        for (i = 0; i < len; i++)
//            printf("%02x ", buffer[i]);
//        printf("\n");
//    } else {
//        ret = gattlib_write_char_by_uuid(connection, &g_uuid, buffer, sizeof(buffer));
//        if(ret == 0)
//            return 2;
//    }
//
//    gattlib_disconnect(connection);
//    return 0;
//}





