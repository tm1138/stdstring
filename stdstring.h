#include <stdio.h>
#include <string.h>
#include <iostream>

class stdstring
{
    char *charstart;
    int capacity;
    static const int npos = -1;

public:
    stdstring();
    stdstring(int);
    stdstring(const stdstring&);
    stdstring(const char*);
    stdstring& operator= (const stdstring&);
    stdstring& operator+ (const stdstring&);

    int find(const char*);
    bool empty() const;
    char* data() const;

    friend std::ostream& operator<< (std::ostream&, const stdstring&);
    friend std::istream& operator>> (std::istream&, const stdstring&);
};