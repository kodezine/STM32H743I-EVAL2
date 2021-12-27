#include "ut_blinky_unity.h"
#include "unity.h"
void test_addTwo_allOK(void)
{
    uint32_t a = 1;
    uint32_t b = 2;
    uint32_t c = 0;
    bool uutRetVal = false;
    uutRetVal = addTwo(&a, &b, &c);

    TEST_ASSERT_EQUAL(true, uutRetVal);
    TEST_ASSERT_EQUAL(3, c);
}