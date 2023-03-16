//
// Created by iLovEing on 2023/3/15.
//

#include "algo_def.h"
#include <cstdio>


void algo_print_arr_int(int arr[], int head, int tail, const char *str)
{
    if (!arr) {
        return;
    }

    if (str) {
        LOGI("%s", str);
        LOGI("(length %d):\n", tail - head + 1);
    }

    for (int i = head; i <= tail; i++)
        LOGI("%d ", arr[i]);

    LOGI("\n");
}

uint64_t algo_get_time_ms()
{
#if defined(BASE_WINDOWS)
    DWORD time_ms;

    time_ms = GetTickCount();
    return time_ms;
#elif defined(BASE_LINUX)
    return 0;
#else
    return 0;
#endif
}

