//
//  table.h
//  H_table
//
//  Created by Андріана Щербак on 23.03.17.
//  Copyright © 2017 Андріана. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;

int const SIZE= 100;

class Line
{
public:
    string  key;
    string  value;
    Line(string key, string value)
    {
        this->key = key;
        this->value = value;
    }
    Line()
    {
        this->key=" ";
        this->value=" ";
    }
};

class Hash_table
{
private:
    Line **table;
public:
    Hash_table()
    {
        table = new Line * [SIZE];
        for (int i = 0; i< SIZE; i++)
        {
            table[i] = NULL;
        }
    }

    int HashFunc(string key)
    {
        int value = 0;
        for ( int i = 0; i < key.length(); i++ )
            value += key[i];
        return (value ) % SIZE;
    }

    void Add(string key, string value)
    {
        int hash = HashFunc(key);
        while (table[hash] != NULL && table[hash]->key != key)
        {
            hash = HashFunc(key)+1;
        }
        table[hash] = new Line(key, value);
    }
   
    string Search(string key)
    {
        int  hash = HashFunc(key);
        while (table[hash] != NULL && table[hash]->key != key)
        {
            hash = HashFunc(key) + 1;
        }
        if (table[hash] == NULL)
        {
            return "-1";
        }
        else
        {
            return table[hash]->value;
        }
    }
    

    void Remove(string key)
    {
        int hash = HashFunc(key);
        while (table[hash] != NULL)
        {
            if (table[hash]->key == key)
            {
                table[hash]->key=" ";
                table[hash]->value=" ";
                break;
            }
            hash = HashFunc(key) + 1;
        }
        if (table[hash] == NULL)
        {
            cout<<"No Element found at key "<<key<<endl;
            return;
        }
        else
        {
            delete table[hash];
        }
        //cout<<"Element Deleted"<<endl;
    }
    
    void Change(string key, string value)
    {
        int hash = HashFunc(key);
        while (table[hash] != NULL)
        {
            if (table[hash]->key == key)
            {
                table[hash]->value=value;
                break;
            }
            hash = HashFunc(key) + 1;
        }
        if (table[hash] == NULL)
        {
            cout<<"Line with this key doesn't exist"<<endl;
            return;
        }
    }
    ~Hash_table()
    {
        delete[] table;
    }
    void iteration(void print(Line l))
    {
        for (int i = 0; i < SIZE; i++)
        {
            print(*table[i]);
        }
    }
    
    void print(Line l)
    {
        cout<<l.key<<l.value<<endl;
    }
};


