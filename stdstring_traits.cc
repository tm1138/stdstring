#include "stdstring.h"

int stdstring::size() const
{
    return length;
}

char* stdstring::data() const
{
    return istring;
}

char* stdstring::c_str() const
{
    return istring;
}

bool stdstring::empty() const
{
    return (length>0) ? 0 : 1;
}