#include "stdstring.h"
#define INITIAL_SIZE 15

stdstring::stdstring()
{
    charstart = new char(INITIAL_SIZE);
    memset(charstart, 0, INITIAL_SIZE);
    capacity = INITIAL_SIZE;
}