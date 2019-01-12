#pragma once
#include<iostream>
//#include"gtest/gtest.h"
using namespace std;

class MyString
{
public:
    size_t size;
    char *line;
    
public:
    MyString()
    {
        size = 0;
        line = NULL;
    }
    MyString(const char *c)
    {
        size = my_strlen(c) + 1;
        line = new char[size];
        for (int i = 0; i < size - 1; i++)
        {
            line[i] = c[i];
        }
        line[size - 1] = '\0';
    }
    MyString(const MyString& t)
    {
        size = my_strlen(t.line) + 1;
        line = new char[size];
        for (int i = 0; i < size - 1; i++)
        {
            line[i] = t.line[i];
        }
        line[size - 1] = '\0';
    }
    
    ~MyString(){};
    
    int my_strlen( MyString& x)
    {
        int l = 0;
        while (x.line[l]++!='\0')
        {
            l++;
        }
        return l;
    }
    size_t my_strlen(const char *str)
    {
        size_t l = 0;
        while (*str++ != '\0')
        {
            l++;
        }
        return l;
    }
    char *my_strcpy(char *l, const char *r)
    {
        while (*r)
        {
            *l++ = *r++;
        }
        ++*l = '\0';
        return l;
    }
    int find_shablon(MyString&shablon)
    {
        for (int i = 0; line[i] != '\0'; i++)
        {
            for (int j = 0; line[i + j] == shablon[j] || shablon[j] == '\0'; j++)
            {
                if (shablon[j] == '\0')
                {
                    return i;
                }
            }
        }
        return -1;
    }
    int find_shablon(const char *text, const char *shablon)
    {
        if (*shablon == '\0')
        {
            return 0;
        }
        for (int i = 0; *(text + i) != '\0'; i++)
        {
            for (int j = 0; *(text + i + j) == *(shablon + j) || *(shablon + j) == '\0'; j++)
            {
                if (*(shablon + j) == '\0')
                {
                    return i;
                }
            }
        }
        return -1;
    }
    bool can_be_substitute(const MyString &x)
    {
        return (find_shablon(line, x.line) != -1);
    }
    int my_strcmp(const char *s1, const char *s2)//compare
    {
        while (*s1 && *s1 == *s2)
        {
            ++s1;
            ++s2;
        }
        return (*s1 - *s2);
    }
    char *my_strcat(char *str1, const char *str2)//Ó·∫‰Ì‡ÌÌˇ ˇ‰Í≥‚
    {
        char* begin = str1;
        while (*str1)
        {
            str1++;
        }
        while ((*str1++ = *str2++))
            *str1 = '\0';
        return begin;
    }
    char *getline() {
        
        int i = 0;
        char c;
        char * tmp = new char[1];
        while (cin.get(c) && (c != '\n'))
        {
            i++;
            tmp[i - 1] = c;
            char * new_tmp = new char[i + 1];
            for (int n = 0; n<i; n++)
            {
                new_tmp[n] = tmp[n];
                delete[] tmp;
                tmp = new_tmp;
            }
        }
        tmp[i] = '\0';
        return tmp;
    }
    MyString& operator= (const MyString& t)
    {
        size = my_strlen(t.line) + 1;
        line = new char[size];
        my_strcpy(line, t.line);
        line[size - 1] = '\0';
        return *this;
    }
    
    void assing(MyString& s1, MyString& s2)
    {
        int index = find_shablon(s1);
        size += (my_strlen(s2.line) - my_strlen(s1.line));
        char* new_line = new char[size];
        for (int i = 0; i < size; ++i)
        {
            if (i < index)
            {
                new_line[i] = line[i];
            }
            
            if (i >= index && i < index + my_strlen(s2.line))
            {
                new_line[i] = s2.line[i - index];
            }
            if (i >= index + my_strlen(s2.line))
            {
                new_line[i] = line[i - my_strlen(s2.line) + my_strlen(s1.line)];
            }
        }
        
        delete line;
        line = new char[size];
        
        for (int i = 0; i < size; ++i)
        {
            line[i] = new_line[i];
        }
        
        delete[] new_line;
    }
    void assing(char* s1, char*s2)
    {
        int index = find_shablon(line,s1);
        size += (my_strlen(s2) - my_strlen(s1));
        char* new_line = new char[size];
        for (int i = 0; i < size; ++i)
        {
            if (i < index)
            {
                new_line[i] = line[i];
            }
            
            if (i >= index && i < index + my_strlen(s2))
            {
                new_line[i] = *(s2+i - index);
            }
            
            if (i >= index + my_strlen(s2))
            {
                new_line[i] = line[i - my_strlen(s2) + my_strlen(s1)];
            }
        }
        
        delete line;
        line = new char[size];
        
        for (int i = 0; i < size; ++i)
        {
            line[i] = new_line[i];
        }
        
        delete [ ] new_line;
    }
    
    MyString operator+ (const MyString& t)
    {
        char* new_line = new char[my_strlen(line) + my_strlen(t.line) + 1];
        size = my_strlen(line) + my_strlen(t.line) + 1;
        my_strcpy(new_line, line);
        my_strcat(new_line, t.line);
        new_line[size - 1] = '\0';
        MyString return_obj(new_line);
        delete[]  new_line;
        
        return return_obj;
    }
    
    bool operator== (const MyString& t)
    {
        return (my_strcmp(line, t.line) == 0);
    }
    
    bool operator!= (const MyString& t)
    {
        return (my_strcmp(line, t.line) != 0);
    }
    void operator+= (const MyString& t)
    {
        size = my_strlen(line) + my_strlen(t.line) + 1;
        char *new_line = new char[size];
        my_strcpy(new_line, line);
        my_strcat(new_line, t.line);
        my_strcpy(line, new_line);
        line[size - 1] = '\0';
        delete[] new_line;
    }
    
    char& operator[] (size_t i)
    {
        return line[i];
    }
    void insert(int index, MyString& a)
    {
        char* first_part = new char[index+1];
        char* second_part = new char[size - index - 1];
        int i = 0;
        int k = 0;
        
        for (; i < index; i++)
        {
            first_part[i] = line[i];
        }
        first_part[index] = '\0';
        for (; i < size - 1; i++ && k++)
        {
            second_part[k] = line[i];
        }
        second_part[k] = '\0';
        MyString first(first_part);
        MyString second(second_part);
        MyString new_word;
        new_word = first + a + second;
        line = new_word.line;
        size = new_word.size;
    }
    void insert(int index, char* a)
    {
        char* first_part = new char;
        char* second_part = new char;
        int i = 0;
        for (; i < index; i++)
        {
            first_part[i] = line[i];
        }
        first_part[index] = '\0';
        for (int k= index; i < my_strlen(line); i++ && k++)
        {
            second_part[k] = line[i];
        }
        //secondPart[k] = '\0';
        MyString first(first_part);
        MyString second(second_part);
        MyString new_word;
        new_word = first + a + second;
        line = new_word.line;
        size = new_word.size;
    }
    
    
    friend ostream& operator<< (ostream& os, const MyString& t)
    {
        os << t.line;
        return os;
    }
    friend istream& operator >> (istream& is, MyString& t)
    {
        char* word = new char;
        is >> word;
        t.size = strlen(word) + 1;
        t.line = new char[t.size + 1];
        for (int i = 0; i < t.size; i++)
        {
            t.line[i] = word[i];
        }
        t.line[t.size] = '\0';
        return is;
    }
    
};



