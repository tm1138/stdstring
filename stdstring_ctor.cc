#include "stdstring.h"


stdstring::stdstring (int size) : istring(new char[size]), icapacity(size), length(0)
{
    std::cout << "default ctor\n";
    length = 0;
    istring[0] = '\0';
}

stdstring::stdstring (const stdstring &temp) : istring(new char[temp.length + 1]), icapacity(temp.length + 1)
                    , length(temp.length)
{
    std::cout << "copy ctor\n";
    memcpy (istring, temp.data(), temp.size());
    istring[length] = '\0';
}

stdstring::stdstring (const char *temp)
{
    std::cout << "param char* ctor\n";
    length = strlen(temp);
    icapacity = length + 1;
    istring = new char[icapacity];
    memcpy (istring, temp, length);
    istring[length] = '\0';
}

stdstring& stdstring::operator+ (const stdstring &temp)
{
    std::cout << "add operator\n";
    int newCapacity = size() + temp.size() + 1;
    char *newstring = new char[newCapacity];
    snprintf (newstring , newCapacity, "%s%s", data(), temp.data());
    stdstring *result = new stdstring (newstring);
    return *result;
}

stdstring& stdstring::operator= (const stdstring &temp)
{
    std::cout << "copy assign\n";
    icapacity = temp.size() + 1;
    if (istring)
    {
        std::cout << data() << '\n';
        delete istring;
    }
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

stdstring::~stdstring()
{
    std::cout << "dtor called " << data() << '\n';
    delete istring;
}