/*5.Перевірити баланс всіх дужок (круглих, квадратних, фігурних) в математичному виразі з дужками.
 Приклади: ([{}])-yes, ([)]-no,()()-yes, ())(-no
 */
#include<iostream>
#include<stack>
#include<string>
#include "Line.h"
using namespace std;
///<summary>
/// Checks if in all lines of the file all opening brackets have coresponding closing ones.
///</summary>
//ToDo: correct all contradictions that appeared after all other suggestions were reviewed
//Done
void task(istream & file)
{
    int size;
    file>>size;
    
    Line *expressions=new Line[size];
    
    for(int i=0;i<size;i++)
    {
        expressions[i].input(file);
    }
    
    for(int i=0;i<size;i++)
    {
        
        cout<<expressions[i].get_line()<<endl;
        
        if(expressions->is_balance())
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
}

int main()
{
    //xcode requires to write the way to file
    //visual version
    //ifstream file("file.txt");
    
    
    //ToDo:add exceptions
    //Done
    ifstream file("/Users/Andriana/Desktop/dz_programming/2 year/new_task2/new_task2/file.txt");
    try
    {
        if(!file.is_open())
        {
            throw "Can't open the file";
        }
    }
    catch (const char * a)
    {
        cout<<a<<endl;
    }
    cout<<"If the brakets is balanced in the next expressions : "<<endl;
    
    task(file);
    
    return 0;
}

