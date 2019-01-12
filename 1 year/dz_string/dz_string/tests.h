#pragma once
#include "string.h"

bool test1()
{
    bool b = true;
    
    MyString s1 = "algo";
    MyString s2 = "rutm";
    s1 += s2;
    
    if (s1 != "algorutm")
    {
        b = false;
    }
    
    s1 = s2;
    if (s1 != "rutm")
    {
        b = false;
    }
    
    MyString s3 = "algorutm";
    MyString s4 = "algo";
    s4 += "rutm";
    if (s3 != s4)
    {
        b = false;
    }
    
    return b;
}

bool test2()
{
    bool b = true;
    
    MyString s1 = "michelangelo";
    
    if (s1.find_shablon("michelangelo", "elan") != 4)
    {
        b = false;
    }
    
    if (s1.find_shablon("michelangelo", "land") != -1)
    {
        b = false;
    }
    
    MyString s2 = "chelangel";
    MyString s3 = "cr";
    
    s1.assing(s2, s3);
    if (s1 != "micro")
    {
        b = false;
    }
    
    return b;
}
