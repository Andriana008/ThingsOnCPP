#pragma once
//#include <gtest/gtest.h>
#include <iostream>

class Set
{
private:
    char isCharInSet[4];
public:
    Set()
    {
        for (int i = 0; i < 4; i++)
        {
            isCharInSet[i] = 0;
        }
    }
    
    Set(const Set& set)
    {
        for (int i = 0; i < 4; i++)
        {
            isCharInSet[i] = set.isCharInSet[i];
        }
    }
    
    void add(char symbol)
    {
        int cod = symbol - 'a';
        int shift = cod % 8;//row
        int index = cod / 4;//column
        isCharInSet[index] |= (1 << shift);// |---- bit or  // << bit shift
    }
    
    void remove(char symbol)
    {
        int cod = symbol - 'a';
        int shift = cod % 8;
        int index = cod / 4;
        isCharInSet[index] &= ~(1 << shift);// ~ opposite  //  &----- bit and
    }
    bool is_in_set(char symbol)
    {
        int cod = symbol - 'a';
        int shift = cod % 8;
        int index = cod / 4;
        return isCharInSet[index] & (1 << shift);
    }
    Set union_of_set(Set& set)
    {
        Set res;
        for (int i = 0; i < 4; i++)
        {
            res.isCharInSet[i] = (isCharInSet[i] | set.isCharInSet[i]);
        }
        
        return res;
    }
    Set intersection(Set& set)
    {
        Set res;
        
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                res.isCharInSet[i] = (isCharInSet[i] & set.isCharInSet[i]);
            }
        }
        
        return res;
    }
    
    void division(Set& set1, Set& set2, char symbol)
    {
        int cod = symbol - 'a';
        
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if ((i * 8 + j) < cod)
                {
                    set1.isCharInSet[i] |= isCharInSet[i] &(1 << j);
                }
                else
                {
                    set2.isCharInSet[i] |= isCharInSet[i] &(1 << j);
                }
            }
        }
    }
    
    char find_min()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (isCharInSet[i] & (1 << j))
                {
                    return char(i * 8 + j + 'a');
                }
            }
        }
        
        return '0';
    }
    
};
