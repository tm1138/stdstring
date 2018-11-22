#include "stdstring.h"
#define INITIAL_SIZE 15

stdstring::stdstring()
{
    istring = new char(INITIAL_SIZE);
    memset(istring, 0, INITIAL_SIZE);
    icapacity = INITIAL_SIZE;
}

stdstring::stdstring (int size)
{
    istring = new char (size);
    memset(istring, 0, size);
    icapacity = size;
}

stdstring::stdstring (const stdstring &temp)
{
    this->icapacity = temp.size() + 1;
    this->istring = new char[this->icapacity];
    memset(istring, 0, this->icapacity);
    memcpy (this->istring, temp.data(), temp.size());
}

stdstring::stdstring (const char *temp)
{
    this->icapacity = strlen(temp) + 1;
    this->istring = new char[this->icapacity];
    memset(istring, 0, this->icapacity);
    memcpy (this->istring, temp, strlen(temp));
}

stdstring& stdstring::operator+ (const stdstring &temp)
{
    std::cout << this->data() << '\n';
    std::cout << temp.data() << '\n';
    std::cout << '\n';
    int newCapacity = this->size() + temp.size() + 1;
    char *newstring = new char[newCapacity];
    snprintf (newstring , newCapacity, "%s%s", this->data(), temp.data());
    stdstring *result = new stdstring (newstring);
    return *result;
}

stdstring& stdstring::operator= (const stdstring &temp)
{
    this->icapacity = temp.size() + 1;
    this->istring = new char[this->icapacity];
    memset (istring, 0, this->icapacity);
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
    std::cin.get(ch);
    std::cin.putback(ch);
    std::streamsize length = std::cin.rdbuf()->in_avail();
    delete(temp.istring);
    temp.istring = new char[length + 1];
    in >> temp.istring;
    return in;
}

int stdstring::size() const
{
    return strlen(istring);
}

char* stdstring::data() const
{
    return this->istring;
}
