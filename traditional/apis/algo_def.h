//
// Created by iLovEing on 2023/3/15.
//
#ifndef ALGORITHMS_ALGO_DEF_H
#define ALGORITHMS_ALGO_DEF_H

//#define ALGO_USE_DEFAULT_VAL
#define DEFAULT_DATA_ARR_LEN 20
class DefaultSortedArr {
public:
    int data[DEFAULT_DATA_ARR_LEN] = {10, 20, 0, 50, 99, 36, 25, 56, 18, 75,
                                     39, 45, 12, 78, 31, 15, 100, 65, 56, 78};
    int head = 0;
    int tail = DEFAULT_DATA_ARR_LEN - 1;

    DefaultSortedArr() = default;

};

/********* defines *********/
#define UNUSED_VAR(x) ((void)x)


/********* print *********/
#define LOGI printf
#define LOGE(str, ...) printf("!!!ERROR!!!: " str, ##__VA_ARGS__)
#define KEY_PROCESS(str, ...) printf("->->->->-> " str, ##__VA_ARGS__)

#define ALGO_DEBUG
#ifdef ALGO_DEBUG
#define LOGD printf
#else
#define LOGD
#endif


/********* format *********/
//typedef signed char     int8_t;
typedef short           int16_t;
typedef int             int32_t;
typedef long long       int64_t;

//typedef unsigned char   uint8_t;
typedef unsigned short  uint16_t;
typedef unsigned int    uint32_t;
typedef unsigned long long  uint64_t;


/********* algo apis *********/
//common io
void algo_print_arr_int(int arr[], int head, int tail, const char *str);


//timestamp
#define BASE_WINDOWS
//#define BASE_LINUX
#if defined(BASE_WINDOWS)
#include <windows.h>
#elif defined(BASE_LINUX)
#else
#endif

uint64_t algo_get_time_ms();

#endif //ALGORITHMS_ALGO_DEF_H
