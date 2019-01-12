/*
 1. Визначити шаблонну функцію, яка підраховує кількість елементів, відмінних від вказаного i-го елемента в масиві. Передбачити перехоплення винятків при невірному значенні i.
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class myException: public exception
{
private:
    string name;
public:
    myException(const exception & ex, string _name) : exception(ex), name(_name) {};
    myException(string _name) : exception(), name(_name) {};
    virtual const char* what() const throw()
    {
        return "My exception happened";
    }
};

template <typename t>

void quantity(t* arr, int size, int number)
{
    try
    {
    if(number>size)
    {
        throw "bad value";
    }
    else
    {
    int k=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]!=arr[number])
        {
            k++;
        }
    }
    cout<< k<<endl;
    }
    }
    catch(const char * a)
    {
        cout<<a;
    }
}

int main()
{
    ifstream file("/Users/Andriana/Desktop/dz_programming/EXAMS!!!/shablon/shablon/s.txt",ios_base::in);
    
    try
    {
    if(!file.is_open())
    {
       throw "file cant be opened";
    }
    }
    catch(const char * a)
    {
        cout<<a;
    }
    try
    {
    if(file.eof())
    {
        throw "file is empty";
    }
    else
    {
        int const n=10;
        int a[n];
        int size;
        int number=2;
        cout<<"Size :"<<endl;
        file>>size;
        cout<<size<<endl;
        for(int i=0;i<size;i++)
        {
            cout<<"Element : "<<i<<endl;
            file>>a[i];
            cout<<a[i]<<endl;
        }
        quantity(a,size,number);
    }
    }
    catch(const char * a)
    {
        cout<<a;
    }
  
    
    
}
