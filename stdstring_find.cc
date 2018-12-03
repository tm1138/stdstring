#include "stdstring.h"

int stdstring::find (const char *text)
{
    int temp_lenght = strlen(text);
    
    if (length < temp_lenght)
    {
        return -1;
    }
    for (int current_pos = 0; current_pos < length; current_pos++)
    {
        if ((length - current_pos) < temp_lenght)
        {
            return -1;
        }
        if (istring[current_pos] == text[0])
        {
            int flag = 0;
            for (int temp_pos = 1; temp_pos < temp_lenght; temp_pos++)
            {
                if (istring[current_pos + temp_pos] != text[temp_pos])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                return (current_pos + 1);
            }
        }
    }
    return -1;
}

int stdstring::rfind (const char *text)
{
    int temp_lenght = strlen(text);
    
    if (length < temp_lenght)
    {
        return -1;
    }
    for (int current_pos = length-1; current_pos >= 0; current_pos--)
    {
        if ((current_pos + 1) < temp_lenght)
        {
            std::cout << "first check \n";
            return -1;
        }
        if (istring[current_pos] == text[temp_lenght - 1])
        {
            std::cout << "entry \n";
            int flag = 0;
            for (int temp_pos = (temp_lenght - 2), i = 1; temp_pos >= 0; temp_pos--, i++)
            {
                std::cout << "entry in \n";
                if (istring[current_pos - i] != text[temp_pos])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                return (current_pos - temp_lenght + 1);
            }
        }
    }
    return -1;
}