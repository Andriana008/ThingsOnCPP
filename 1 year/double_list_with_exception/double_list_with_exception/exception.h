#include <iostream>
#include <exception>
#include<string>
#include<fstream>

using namespace std;


class myException: public exception
{
private:
    string name;
public:
    myException(const exception & ex, string _name) : exception(ex), name(_name) {};
    myException(string _name) : exception(), name(_name) {};
//    virtual const char * what()const throw()
//    {
//        //string result = ((string)exception::what() + "file" + name);
//        //return result.c_str();
//        return "My exception happened";
//    }
    virtual const char* what() const throw()
    {
        return "My exception happened";
    }
};
