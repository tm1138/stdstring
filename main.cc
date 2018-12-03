#include "stdstring.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    stdstring str1 ("my name is what my name is what");
    std::string temp;
    std::cout << "Enter string: ";
    std::cin >> temp;
    int val = str1.rfind(temp.data());
    std::cout << "Position : " << val << '\n';
    return 0;
}
