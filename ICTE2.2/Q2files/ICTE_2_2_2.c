#include "ICTE_2_2_2.h"

void CopyArray(const int * src_arr, int * dst_arr, const int size){
    for (int i=0; i<size; i++){
        *(dst_arr + i) = *(src_arr + i);
    }
} 