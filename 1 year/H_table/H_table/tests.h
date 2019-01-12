//
//  Tests.hpp
//  Simple-table
//
//  Created by Андріана Щербак on 19.03.17.
//  Copyright © 2017 Андріана. All rights reserved.
//


#include <iostream>
#include "table.h"
using namespace std;

bool test1()//додавання
{
    bool b;
    cout << "Test1 is "<<endl;
    Hash_table table;
    table.Add("A", "1");
    if (table.Search("A") == "1")
    {
        b=true;
    }
    else
    {
        b=false;
    }
    return b;
}

bool test2()//пошук
{
    bool b;
    cout << "Test2 is "<<endl;
    Hash_table table;
    table.Add("A", "1");
    table.Add("B", "2");
    if (table.Search("A") == "1")
    {
        b=true;
    }
    else
    {
        b=false;
    }
    return b;
}

bool test3()//заміна
{
    bool b;
    cout << "Test3 is "<<endl;
    Hash_table table;
    table.Add("A", "1");
    table.Change("A", "2");
    if (table.Search("A")=="2")
    {
        b=true;
    }
    else
    {
        b=false;
    }
    return b;
}

bool test4()//видалення
{
    bool b;
    cout << "Test4 is "<<endl;
    Hash_table table;
    table.Add("X", "t");
    table.Remove("X");
    if (table.Search("X") == "t")
    {
        b=false;
    }
    else
    {
        b=true;
    }
    return b;
}
