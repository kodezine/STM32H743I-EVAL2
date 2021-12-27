#include "blinky_unity.h"

bool
addTwo(uint32_t* a, uint32_t* b, uint32_t* c)
{
    bool retVal = false;
    if((a != NULL) &&
    (b != NULL) &&
    (c != NULL))
    {
        uint64_t tempSum = *a + *b;
        if(tempSum > UINT32_MAX)
        {
            *c = 0;
            retVal = false;
        }
        else
        {
            *c = *a + *b;
            retVal = true;
        }
    }
    return(retVal);
}