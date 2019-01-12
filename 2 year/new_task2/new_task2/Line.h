#include<iostream>
#include<stack>
#include<string>
#include<fstream>

using namespace std;


class Line
{
private:
    //ToDo: suggest renaming the variable, for example to "line"
    //Done
    string line;
public:
    ///<summary>
    /// Returns contents of the Line
    ///</summary>
    string get_line()
    {
        return line;
    }
    
    ///<summary>
    /// Checks if opening bracket has match in the end of line
    ///</summary>
    ///<returns>
    /// Returns bool value.
    ///</returns>
    ///<param name= 'first'>
    /// Depicts first bracket in the stack
    ///</param>
    ///<param name= 'end'>
    /// Depicts last bracket in the stack
    ///</param>
    //ToDo: suggest renaming variable "end" to "last"
    //Done
    bool is_pair(char first,char last)
    {
        if(first == '(' && last == ')')
        {
            return true;
        }
        else if(first == '{' && last == '}')
        {
            return true;
        }
        else if(first == '[' && last == ']')
        {
            return true;
        }
        return false;
    }
    ///<summary>
    /// Checks if all opening brackets have coresponding closing ones in the end of the stack
    ///</summary>
    ///<returns>
    ///  Bool value that depicts if all brackets are balanced
    ///</returns>
    //ToDo: use pointer this->l instead of string braket
    //ToDo: no need in passing Line a to the funktion
    //ToDo: rename funktion, so it'll be obwious that it returns bool value
    //Done (3)
    bool is_balance()
    {
        stack<char>  stack;
        
        string braket=this->line;
        for(int i =0; i<this->line.length(); i++)
        {
            if(braket[i] == '(' || braket[i] == '{' || braket[i] == '[')
            {
                stack.push(this->line[i]);
            }
            else if(braket[i] == ')' || braket[i] == '}' || braket[i] == ']')
            {
                if(stack.empty() || !is_pair(stack.top(), braket[i]))
                {
                    return false;
                }
                else
                {
                    stack.pop();
                }
            }
        }
        return stack.empty() ? true:false;
    }
    ///<summary>
    ///  Reads line from file and writes it to Line's string
    ///</summary>
    ///<param name= 'file'>
    /// File, from which line is to be read
    ///</param>
    void input(istream&file)
    {
        file>>line;
    }
};

