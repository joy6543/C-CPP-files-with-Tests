#include "solutions.h"
#include "gtest/gtest.h"

namespace {

    TEST(Complex, BasicsAdd) {
        Complex a = (Complex) { 2, 3 },
                b = (Complex) { 4, 5 };
        EXPECT_DOUBLE_EQ(add(a,b).real,6);
        EXPECT_DOUBLE_EQ(add(a,b).im,8);
    }

    TEST(Complex, BasicsNegate) {
        Complex a = (Complex) { 2, 3 };
        EXPECT_DOUBLE_EQ(negate(a).real,-2);
        EXPECT_DOUBLE_EQ(negate(a).im,-3);
    }

    TEST(Complex, BasicsMult) {
        Complex a = (Complex) { 2, 3 },
                b = (Complex) { 4, 5 };
        EXPECT_DOUBLE_EQ(multiply(a,b).real,-7);
        EXPECT_DOUBLE_EQ(multiply(a,b).im,22);
    }

    TEST(Complex, BasicsMag) {
        Complex a = (Complex) { 3 , 4};
        EXPECT_DOUBLE_EQ(magnitude(a),5);
    }
}
