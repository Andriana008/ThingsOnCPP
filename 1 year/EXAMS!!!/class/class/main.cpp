/*
 2. Визначити клас «Дія»(назва, тривалість) – «прогулянка», «навчання», «їжа», «друзі», клас «Розпорядок дня» (дата, список дій) та клас «Розпорядок на тиждень», який міститиме розпорядок на 7 днів та ім’я особи. В текстовому файлі задано дані про Розпорядок тижня 2 осіб.
 Б) Зчитати дані з файлу і видрукувати на консоль ім’я особи та той Розпорядок дня, в якому є найбільше Дій.
 В)Порахувати для кожного особи загальну тривалість всіх дій «прогулянка» протягом тижня Результат вивести в текстовий файл.
 
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Action
{
private:
    string name;
    int time;
public:
    Action():name(""),time(0){};
    void input_a(ifstream & file)
    {
        string x;
        int y;
        file>> x;
        file>>y;
       if(x!="0")
        {
        file>>name;
        }
       if(y!=0)
        {
        file>>time;
        }
       
    }
    string get_name()
    {
        return name;
    }
    int get_time()
    {
        return time;
    }
};
class Day_plan
{
private:
    int data;
    Action * arr1;
    int count;
public:
    Day_plan():data(0){};
    int number(ifstream & file)
    {
        file>>data;
        for(int i=0;i<10;i++)
        {
            count++;
        }
        return count;
    }
    void input_d(ifstream & file)
    {
        file>>data;
        for(int i=0;i<number(file);i++)
        {
            arr1[i].input_a(file);
        }
    }
    int time(string name,ifstream & file)
    {
        int sum=0;
        for(int i=0;i<number(file);i++)
        {
            if(arr1[i].get_name()==name)
            {
                sum+=arr1[i].get_time();
            }
        }
        return sum;
    }
    
};

class Week_plan
{
private:
    string name;
    const static int days=7;
    Day_plan arr2[days];
public:
    void input_w(ifstream & file)
    {
        file>>name;
        for(int i=0;i<days;i++)
        {
            arr2[i].input_d(file);
        }
    }
    string get_name()
    {
        return name;
    }
    int duration(string name,ifstream & file)
    {
        int n=0;
        for(int i=0;i<days;i++)
        {
           n= arr2[i].time(name,file);
        }
        return n;
    }
    
};


int main()
{
    ifstream file("/Users/Andriana/Desktop/dz_programming/EXAMS!!!/class/class/c.txt",ios_base::in);
    ofstream file1("/Users/Andriana/Desktop/dz_programming/EXAMS!!!/class/class/a.txt",ios_base::out);
    
    Week_plan arr[2];
    string x;
    while (!file.eof())
    {
    for(int i=0;i<2;i++)
        {
            if(x!="###")
            {
                arr[i].input_w(file);
            }
        }
    }
    int n=0;
    for(int i=0;i<2;i++)
    {
        arr[i]
    }
    
    for(int i=0;i<2;i++)
    {
        
    }
}


















