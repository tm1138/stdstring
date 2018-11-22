#include "stdstring.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    stdstring str1 ("abcd");
    std::cout << str1 << '\n';
    std::cout << str1.size() << '\n';
    stdstring str2 ("efgh");
    std::cout << str2 << '\n';
    std::cout << str2.size() << '\n';
    stdstring str3;
    std::cout << "Enter some string: ";
    std::cin >> str3;
    std::cout << str3 << '\n';
    std::cout << str3.size() << "\n\n";
    stdstring str = str2 + str3;
    std::cout << str << '\n';
    std::cout << str.size() << '\n';

    return 0;
}
