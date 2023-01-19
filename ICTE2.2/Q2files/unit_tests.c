#include "ICTE_2_2_2.h"
#include "gtest/gtest.h"

namespace { 

    TEST(ICTE_2_2_2, CopyArray) {
        int src_arr[] = {1, 200, 15, 60, 34};
        int dst_arr[5];
        CopyArray(src_arr, dst_arr, 5);
        for (int i=0; i<5; i++){
            ASSERT_EQ(src_arr[i], dst_arr[i]);
        }
    }

}
