//
// Created by patryk on 28.05.18.
//

#include <iostream>
#include "conversions.h"

#include "gattlib/include/gattlib.h"// TO DO ogarnąć bibliotekę
using namespace std;
typedef enum { READ, WRITE} operation_t;
operation_t g_operation;

static uuid_t g_uuid;
long int value_data;



static void usage(char *argv[]) {
    cout <<  argv[0] << " <device_address> <read|write> <uuid> [<hex-value-to-write>]\n";
}

int main(int argc, char *argv[]) {

    uint32_t A;
    cin >> A;
    float B = BaroConvert(A);
    cout << B;
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





