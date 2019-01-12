//
//  Table.hpp
//  Simple-table
//
//  Created by Андріана Щербак on 19.03.17.
//  Copyright © 2017 Андріана. All rights reserved.
//

#pragma once
#include <iostream>
#include <string>
using namespace std;
//створення рядочку таблиці ключ-значення
struct Line
{
    string key;
    string value;
    Line()
    {
    key=" ";
    value=" ";
    }
    Line(string _key, string _value)
    {
    key=_key;
    value=_value;
    }
};
//створення таблиці
class Table
{

private:
    Line * arr;
    int size;//розмір
    int count;//скільки заповнено

public:
    Table()
    {
        size = 2;
        count = 0;
        arr = new Line[size];
    }
   
    ~Table()
    {
        delete[] arr;
    }
   
    void push(Line new_element)
    {
        arr[count] = new_element;
        count++;
        if(count==size)
        {
            Line *new_arr=new Line[size];
            for(int i=0;i<size;i++)
            {
                new_arr[i]=arr[i];
            }
            size*=2;
            arr=new Line[size];
            for(int i=0;i<size;i++)
            {
                arr[i]=new_arr[i];
            }
            delete[] new_arr;
        }
    }
   
    bool is_empty()
    {
        return count == 0;
    }
   
    Line pop()
    {
        count--;
        return arr[count];
    }
    
    Line get_element(int i)
    {
        return arr[i];
    }
    
    Line & operator [](int i)
    {
        return arr[i];
    };
   
    int find_number_of_full_lines()
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i].key != " ")
            {
                count++;
            }
            
        }
        return count;
    };
   
    string if_key_exist(string k)
    {
        string key;
        for (int i = 0; i < size; i++)
        {
            if (arr[i].key == k)
            {
                key=k;
            }
            else
            {
                key="0";
            }
        }
            return key;
    }
    
    
    void add(Line l)
    {
        if (find_number_of_full_lines()!=size)
        {
            if ((if_key_exist(l.key))!=l.key)
            {
                for (int i = 0; i < size; i++)
                {
                    if (arr[i].key == " ")
                    {
                        push(l);
                        break;
                    }
                }
            }
            
            else
            {
                cout<<"Element with this key already exists"<<endl;
            }
        }
        else
        {
            cout<<"Table is full"<<endl;
        }
        
    };
    
    void change(Line l)
    {
        if (if_key_exist(l.key)=="0")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i].key == l.key)
                {
                    arr[i].value = l.value;
                }
            }
        }
        else
        {
            cout<<"Line with this key doesn't exist"<<endl;
        }
        
    };
    
    string find(string key)
    {
        string found="0";
        if (if_key_exist(key)=="0")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i].key == key)
                {
                    found = arr[i].value;
                }
            }
            return found;
        }
        else
        {
            return found;
        }
    }
    
    void delete_line_by_key(Line l)
    {
        if (find_number_of_full_lines() !=0)
        {
            if (if_key_exist(l.key)=="0")
            {
                for (int i = 0; i < size; i++)
                {
                    if (arr[i].key == l.key)
                    {
                        arr[i].key = " ";
                        arr[i].value = " ";
                    }
                }
            }
            else
            {
                cout<< "Such key doesn't exist"<<endl;
            }
        }
        else
        {
            cout<<"Table is empty"<<endl;
            
        }
        
    };
   
    void iteration(void print(Line l))
    {
        for (int i = 0; i < size; i++)
        {
            print(arr[i]);
        }
    }
   
    void print(Line l)
    {
        cout<<l.key<<l.value<<endl;
    }
};
