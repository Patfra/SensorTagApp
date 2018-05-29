//#include <iostream>
//
//int main() {
//    std::cout << "Hello, Worlds!" << std::endl;
//    return 0;
//}
//#include <stdio.h>
//#include <unistd.h>
//
//int main(int argc, char **argv)
//{
//    printf("--beginning of program\n");
//    int b;
//    int counter = 0;
//    pid_t pid = fork();
//
//    if (pid == 0)
//    {
//        // child process
//        int i = 0;
//        for (; i < 50; ++i)
//        {
//            printf("child process: counter=%d\n", ++counter);
//            printf("%d\n", b);
//        }
//    }
//    else if (pid > 0)
//    {
//        // parent process
//        int j = 0;
//        for (; j < 50; ++j)
//        {
//            printf("parent process: counter=%d\n", ++counter);
//            b=j;
//        }
//    }
//    else
//    {
//        // fork failed
//        printf("fork() failed!\n");
//        return 1;
//    }
//
//    printf("--end of program--\n");
//
//    return 0;
//}




// #include <iostream>
// #include <thread>
//
// static const int num_threads = 10;
//
// //This function will be called from a thread
//
// void call_from_thread(int tid) {
//    std::cout << "Launched by thread " << tid << std::endl;
// }
//
// int main() {
//    std::thread t[num_threads];
//
//    //Launch a group of threads
//    for (int i = 0; i < num_threads; ++i) {
//        t[i] = std::thread(call_from_thread, i);
//    }
//
//    std::cout << "Launched from the main\n";
//
//    //Join the threads with the main thread
//    for (int i = 0; i < num_threads; ++i) {
//        t[i].join();
//    }
//    return 0;
// }

#include <stdio.h>
#include <stdlib.h>

#include "conversions.h"

#include "gattlib.h"
// TO DO ogarnąć bibliotekę




#define NUM_THREADS 5

//void *PrintHello(void *threadid) {
//    long tid;
//    tid = (long)threadid;
//    cout << "Hello World! Thread ID, " << tid << endl;
//    pthread_exit(NULL);
//}



int main() {
    uint32_t A;
    scanf("%d", &A);
    float B = BaroConvert(A);
    printf("%f", B);
}

//    pthread_t threads[NUM_THREADS];
//    int rc;
//    int i;
//
//    for( i = 0; i < NUM_THREADS; i++ ) {
//        cout << "main() : creating thread, " << i << endl;
//        rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);
//
//
//        if (rc) {
//            cout << "Error:unable to create thread," << rc << endl;
//            exit(-1);
//        }
//    }
//    pthread_exit(NULL);
//}