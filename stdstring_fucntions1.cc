#include "stdstring.h"

int stdstring::size() const
{
    return strlen(istring);
}

char* stdstring::data() const
{
    return istring;
}

char* stdstring::c_str()
{
    return istring;
}

