#pragma once
#include"string.h"
#include<string>
#include<iostream>

using namespace std;

struct RuleString
{
    MyString old_value;
    MyString new_value;
    RuleString()
    {
        this->old_value = "";
        this->new_value = "";
    }
    RuleString(MyString old_value, MyString new_value)
    {
        this->old_value = old_value;
        this->new_value = new_value;
    }
};

struct Rule
{
    string old_value;
    string new_value;
    Rule()
    {
        this->old_value = "";
        this->new_value = "";
    }
    Rule(string old_value, string new_value)
    {
        this->old_value = old_value;
        this->new_value = new_value;
    }
};


class Markov
{
public:
    friend MyString change_for_rules(MyString text, int size_rules, RuleString* rules)
    {
        for (int i = 0; i < size_rules; i++)
        {
            int index = text.find_shablon(rules[i].old_value);
            while (index != -1)
            {
                text.assing(rules[i].old_value, rules[i].new_value);
                index = text.find_shablon(rules[i].old_value);
            }
        }
        return text;
    }
    
    friend string change_for_rules(string text, int size_rules, Rule* rules)
    {
        for (int i = 0; i < size_rules; i++)
        {
            size_t index = text.find(rules[i].old_value);
            while (index != -1)
            {
                text = text.replace(index, rules[i].old_value.size(), rules[i].new_value);
                index = text.find(rules[i].old_value);
            }
        }
        return text;
    }
};

