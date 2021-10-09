#include <stdlib.h>
#include <time.h>


void sleep_ms(long m){
    struct timespec ts;
    ts.tv_sec = m/1000;
    ts.tv_nsec = (m % 1000) *  1000000;
    nanosleep(&ts, NULL);
}

