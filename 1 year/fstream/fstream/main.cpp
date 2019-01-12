//#include <fstream>
//#include <iostream>
//using namespace std;
//
//int main(int argc, char* argv[])
//{
//    char buff[50];
//    ifstream fin("/Users/Andriana/Desktop/dz_programming/fstream/fstream/cppstudio.txt");
//    if (!fin.is_open())
//        cout << "Файл не может быть открыт!\n";
//    else
//    {
//        fin >> buff;
//        cout << buff << endl;
//        
//    }
//    system("pause");
//    return 0;
//}

//створити свій власний клас виняток, його використовувати\
//зробити роботу з файлами, для них винятки

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
    
    virtual const char * what()const throw()
    {
       string result = ((string)exception::what() + "file" + name);
       return result.c_str();
       // return "My exception happened";
    }
    
    
};

int main()
{
    string name;
    name = "/Users/Andriana/Desktop/dz_programming/fstream/fstream/cppstudio.txt";
    ifstream file("/Users/Andriana/Desktop/dz_programming/fstream/fstream/cppstudio.txt");
    try
    {
        if (!file.is_open())
        {
            throw myException(name);
        }
        string line;
        getline(file, line);
        if (line.empty())
        {
            throw myException(name);
        }
        string res;
        res = line.substr(0, line.find(" "));
//        if (!tryConvertToint(res,firstNum))
//        {
//            throw "bad_alloc";
//        }
    }
    catch (myException e)
    {
        cout << e.what();
    }
    catch (exception e)
    {
        cout << e.what();
    }
    return 0;
}
