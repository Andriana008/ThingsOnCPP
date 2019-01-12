//
//  Tests.hpp
//  Simple-table
//
//  Created by Андріана Щербак on 19.03.17.
//  Copyright © 2017 Андріана. All rights reserved.
//


#include <iostream>
#include "Table.hpp"
using namespace std;

bool test1()//додавання
{
    bool b;
    cout << "Test1 is "<<endl;
    Table table;
    Line L("X", "t");
    table.add(L);
    if (table.find("X") == "t")
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
    Table table;
    Line L1("A", "1");
    Line L2("B", "2");
    table.add(L1);
    table.add(L2);
    if (table.find("A") == "1")
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
    Table table;
    Line L1("A", "1");
    Line L2("A", "2");
    table.add(L1);
    table.change(L2);
    if (table.find("A")=="2")
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
    Table table;
    Line L("X", "t");
    table.add(L);
    table.delete_line_by_key(L);
    if (table.find("X") == "t")
    {
        b=false;
    }
    else
    {
        b=true;
    }
    return b;
}

