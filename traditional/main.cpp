#include <iostream>
#include "apis/algo_def.h"
#include "sort_algo/BubbleSort.cpp"
#include "sort_algo/MergeSort.cpp"
#include "sort_algo/InsertSort.cpp"

int main() {
    DefaultSortedArr default_data = DefaultSortedArr();
    InsertSort::sort(default_data.data, default_data.head, default_data.tail);
}
