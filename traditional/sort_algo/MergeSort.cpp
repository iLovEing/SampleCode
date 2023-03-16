//
// Created by iLovEing on 2023/3/16.
//


#include <iostream>
#include "../apis/algo_def.h"

using namespace std;
/*****
*
* MERGE (A, p, q, r)    //p <= q < r
*   n1 = q - p + 1
*   n2 = r - q
*
*   let L[1 ... n1 + 1] and R[1 ... n2 + 1] be new arrays
*   for i = 1 to n1
*       L[i] = A[p + i - 1]
*   L[n1 + 1] = MAX_NUM
*   for i = j to n2
*       R[j] = A[q + j]
*   R[n2 + 1] = MAX_NUM
*
*   i = 1
*   j = 1
*   for k = p to r
*       if L[i] <= R[j]
*           A[k] = L[i]
*           i = i + 1
*       else
*           A[k] = R[j]
*           j = j + 1
*
* MERGE_SORT (A, p, r)    //p <= q < r
*   if p < r
*       q = (p + r) / 2
*       MERGE_SORT(A, p, q)
*       MERGE_SORT(A, q + 1, r)
*       MERGE(A, p, q, r)
*
*****/
class MergeSort {
private:
    //use max
    static void merge0(int arr[], int p, int q, int r)
    {
        int size1 = q - p + 1, size2 = r - q;
        int *parr1 = nullptr, *parr2 = nullptr;

        parr1 = new int[size1 + 1];
        memcpy(parr1, arr + p, size1 * sizeof(int));
        *(parr1 + size1)= 65535;

        parr2 = new int[size2 + 1];
        memcpy(parr2, arr + q + 1, size2 * sizeof(int));
        *(parr2 + size2)= 65535;

        for (int k = p, i = 0, j = 0; k <= r;) {
            if (*(parr1 + i) < *(parr2 + j)) {
                arr[k++] = *(parr1 + i++);
            } else {
                arr[k++] = *(parr2 + j++);
            }
        }

        delete[] parr1;
        delete[] parr2;
    }

    //use len
    static void merge1(int arr[], int p, int q, int r)
    {
        int size1 = q - p + 1, size2 = r - q;
        int *parr1 = nullptr, *parr2 = nullptr;

        parr1 = new int[size1];
        memcpy(parr1, arr + p, size1 * sizeof(int));

        parr2 = new int[size2];
        memcpy(parr2, arr + q + 1, size2 * sizeof(int));

        for (int k = p, i = 0, j = 0; k <= r;) {
            if (*(parr1 + i) < *(parr2 + j)) {
                arr[k++] = *(parr1 + i++);

                if (i == size1) {
                    for (; k <= r;)
                        arr[k++] = *(parr2 + j++);

                    break;
                }
            } else {
                arr[k++] = *(parr2 + j++);

                if (j == size2) {
                    for (; k <= r;)
                        arr[k++] = *(parr1 + i++);

                    break;
                }
            }
        }

        delete[] parr1;
        delete[] parr2;
    }

public:
    static void sort(int arr[], int head, int tail) {
#ifdef ALGO_DEBUG
        LOGD("before merge: (head, tail)[%d, %d]: ", head, tail);
        algo_print_arr_int(arr, head, tail, nullptr);
#endif // ALGO_DEBUG
        if (head < tail) {
            int q = (head + tail) / 2;
            sort(arr, head, q);
            sort(arr, q + 1, tail);

            merge1(arr, head, q, tail);
        }
#ifdef ALGO_DEBUG
        LOGD("after merge: (head, tail)[%d, %d]: ", head, tail);
        algo_print_arr_int(arr, head, tail, nullptr);
#endif // ALGO_DEBUG
    }
};
