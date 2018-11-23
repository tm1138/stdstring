#include "stdstring.h"


stdstring::stdstring (int size)
{
    std::cout << "default ctor \n";
    istring = new char (size);
    memset(istring, 0, size);
    icapacity = size;
}

stdstring::stdstring (const stdstring &temp)
{
    icapacity = temp.size() + 1;
    istring = new char[icapacity];
    memset(istring, 0, icapacity);
    memcpy (istring, temp.data(), temp.size());
}

stdstring::stdstring (const char *temp)
{
    icapacity = strlen(temp) + 1;
    istring = new char[icapacity];
    memset(istring, 0, icapacity);
    memcpy (istring, temp, strlen(temp));
}

stdstring& stdstring::operator+ (const stdstring &temp)
{
    std::cout << data() << '\n';
    std::cout << temp.data() << '\n';
    std::cout << '\n';
    int newCapacity = size() + temp.size() + 1;
    char *newstring = new char[newCapacity];
    snprintf (newstring , newCapacity, "%s%s", data(), temp.data());
    stdstring *result = new stdstring (newstring);
    return *result;
}

stdstring& stdstring::operator= (const stdstring &temp)
{
    icapacity = temp.size() + 1;
    istring = new char[icapacity];
    memset (istring, 0, icapacity);
    memcpy (istring, temp.data(), temp.size());
    return *this;
}

std::ostream& operator<< (std::ostream& out, const stdstring& temp)
{
    out << temp.data();
    return out;
}

std::istream& operator>> (std::istream& in, stdstring& temp)
{
    char ch;
    std::cin.sync_with_stdio(false);
    std::cin.get(ch);
    std::cin.putback(ch);
    std::streamsize length = std::cin.rdbuf()->in_avail();
    delete(temp.istring);
    temp.istring = new char[length-1];
    in >> temp.istring;
    return in;
}

int stdstring::size() const
{
    return strlen(istring);
}

char* stdstring::data() const
{
    return istring;
}
