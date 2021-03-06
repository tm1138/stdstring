#include <stdio.h>
#include <string.h>
#include <iostream>

#define INITIAL_SIZE 15

class stdstring
{
    char *istring;
    int icapacity;
    int length;
    static const int npos = -1;

public:
    stdstring(int size = INITIAL_SIZE); //
    stdstring(const stdstring&); //
    stdstring(const char*); //
    stdstring& operator= (const stdstring&); //
    stdstring& operator+ (const stdstring&); //
    ~stdstring();

    int find(const char*); //
    int rfind(const char*);


    char* c_str() const; //
    int size() const; //
    bool empty() const; //
    char* data() const; //

    friend std::ostream& operator<<(std::ostream&, const stdstring&); //
    friend std::istream& operator>>(std::istream&, stdstring&); //
};