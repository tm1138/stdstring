#include "stdstring.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    stdstring str1 ("abcdefghlmnop");
    stdstring str2;
    if (str1.empty())
    {
        std::cout << "str1 is empty";
    }
    if (str2.empty())
    {
        std::cout << "str2 is empty";
    }
    return 0;
}
