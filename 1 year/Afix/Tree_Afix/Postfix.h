#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "Stack.h"
using namespace std;

class OPN
{
public:
    string input;
    
    int priority(string oper)
    {
        int priority = 0;
        
        if (oper == "+" || oper == "-")
        {
            priority = 1;
        }
        else if (oper == "*" || oper == "/")
        {
            priority = 2;
        }
        else if (oper == "^")
        {
            priority = 3;
        }
        else if (oper == "cos" || oper == "log" || oper == "sin")
        {
            priority = 4;
        }
        
        return priority;
    }
    
    bool is_operation(string oper)
    {
        return oper == "+" || oper == "-" || oper == "cos" || oper == "log" || oper == "sin" || oper == "^" || oper == "*" || oper == "/";
    }
    
    OPN(string in) :input(in) {};
    
    string convert()
    {
        string out;
        Stack<string> stack;
        
        istringstream stream(input);
        string in;
        
        while (!stream.eof())
        {
            stream >> in;
            if (in != "(" && in != ")" && in != "+" && in != "-" && in != "*" && in != "/" && in != "^" && in != "log" && in != "cos")
            {
                out += in;
                
                if (!out.empty())
                {
                    out += " ";
                }
            }
            else if (in == "(")
            {
                stack.push(in);
            }
            else if (in == ")")
            {
                while (stack.top() != "(")
                {
                    out += " ";
                    out += stack.pop();
                }
                stack.pop();
            }
            else if (is_operation(in)==true)
            {
                out += " ";
                while (!stack.empty() && priority(in) <= priority(stack.top()))
                {
                    out += stack.pop();
                    out += " ";
                }
                stack.push(in);
            }
        }
        while (!stack.empty())
        {
            out += " ";
            out += stack.pop();
        }
        
        input = out;
        return input;
    }
    
    double calculate()
    {
        Stack<double> stack;
        double res;
        
        istringstream stream(input);
        string in;
        
        while (!stream.eof())
        {
            stream >> in;
            if (is_operation(in) != true)
            {
                stack.push(stod(in));
            }
            else if (is_operation(in) == true)
            {
                double result;
                if (in == "+")
                {
                    result = stack.pop() + stack.pop();
                }
                else if (in == "-")
                {
                    double secondValue = stack.pop();
                    result = stack.pop() - secondValue;
                }
                else if (in == "*")
                {
                    result = stack.pop() * stack.pop();
                }
                else if (in == "/")
                {
                    double secondValue = stack.pop();
                    result = stack.pop() / secondValue;
                }
                else if (in == "^")
                {
                    double secondValue = stack.pop();
                    result = pow(stack.pop(), secondValue);
                }
                else if (in == "cos")
                {
                    stack.push(cos(stack.pop()));
                }
                else if (in == "sin")
                {
                    stack.push(sin(stack.pop()));
                }
                else if (in == "log")
                {
                    result = log(stack.pop()) / log(stack.pop());
                }
                stack.push(result);
            }
        }
        res = stack.pop();
        return res;
    }
};
