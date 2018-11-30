#include "stdstring.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    stdstring str1 ("abcdefghlmnop");
    std::cout << '\n';
    str1 = stdstring("abcd");
    //stdstring str;
    return 0;
}
