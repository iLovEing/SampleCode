//
// Created by iLovEing on 2023/3/16.
//


#include <iostream>
#include "../apis/algo_def.h"


using namespace std;
/*****
*
* INSERTION-SORT(A)
*   for j = 2 to A.length
*       key = A[j]
*       //insert A[j] into the sorted sequence A[1 ... j-1]
*       i = j - 1
*       while i > 0 and A[i] > key
*           A[i + 1] = A[i]
*           i = i - 1
*
*       A[i + 1] = key
*
*****/
class InsertSort {
public:
    static void sort(int arr[], int head, int tail) {
        int temp = 0;
        uint64_t ts = 0;

        ts = algo_get_time_ms();
        KEY_PROCESS("before sort, ts %lld, arr size %d.\n", ts, tail - head + 1);
#ifdef ALGO_DEBUG
        algo_print_arr_int(arr, head, tail, nullptr);
#endif

        for (int i = head + 1, j = 0; i <= tail; i++) {
            temp = arr[i];

            for (j = i; j > head; j--) {
                if (arr[j - 1] > temp) {
                    arr[j] = arr[j - 1];
                } else {
                    break;
                }
            }

            arr[j] = temp;
        }

        ts = algo_get_time_ms();
        KEY_PROCESS("after sort, ts %lld.\n", ts);
#ifdef ALGO_DEBUG
        algo_print_arr_int(arr, head, tail, nullptr);
#endif
    }
};