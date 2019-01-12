/*Визначити два типи «Працівник» (ПІП, посада, зарплата) та «Учень» (ПІП, група, спеціальність).
Визначити тип «ПТУ» (назва,адреса, список працівників та список учнів).
В текстовому файлі задано дані про 3 ПТУ міста. 
Зчитати дані у масив і вивести у Файл1 список всіх спеціальностей даного ПТУ (без повторів)
та вказати кількість учнів за кожною спеціальністю. Видрукувати у Файл2 посортованих за зарплатою всіх
працівників того ПТУ, в якому навчаються найбільше студентів.
*/
#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include "Classes.h"

void sort(PTY* arr, int n)
{
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n - 1; j++)
        {
            if(arr[j].getSalary()<arr[j+1].getSalary())
            {
                PTY t = arr[j];
                arr[j] = arr[j + 1];
                arr[j] = t;
            }
        }
    }
}

PTY DTOInput(string name ,PTY* PTY,int size ,int& index )
{
    ifstream file(name , ios_base:: in );
    if (!file.is_open())
    {
        cout << "can not  open  "<<name<< " , try again ...\n";
        return *PTY;
    }
    int n=size;
    if (index == 0)
    {
        n = size / 2;
    }
    for ( ; index< n ; index++)
    {
        int temp;
        file >> temp;
        if (temp == 1)
        {
        PTY[index].input(file);
        }
    }
    
    return *PTY;
    
}


void  DTOOutput (PTY* PTY, int size)
{
    ofstream file("result.txt", ios_base::out | ios_base::trunc);
    if (!file.is_open())
    {
        cout << "can not  open  result.txt , try again ...\n";
    }
    else
    {
        file << " \t\t\t  First  task  \n";
        file << "suma of students of different specializations : \n";
        int suma = 0;
        for (int i = 0; i < size - 1; i++)
        {
            if (PTY[i]->getSpec() != PTY[i + 1]->getSpec())
            {
                file << PTY[i].getSpec() << " : " << suma << " $ \n";
                suma = 0;
            }
            if (i == size - 2 && PTY[i].getSpec() == PTY[i + 1].getSpec())
            {
                suma ++;
                file << PTY[i + 1].getSpec() << " : " << suma << " $ \n";
            }
            if (i == size - 2 && PTY[i].getSpec() != PTY[i + 1].getSpec())
            {
                suma = 0;
                suma ++;
                file << PTY[i + 1].getSpec() << " : " << suma << " $ \n";
            }
            
        }
        file << " \t\t\t  Second task  \n";
        sort(PTY, size);
        file << "All workers sorted by salary  :\n ";
        for (int i = 0; i < size; i++)
        {
            PTY[i].output(file);
        }
    }
}


int main()
{
    int index = 0;
    int const size = 3;
    PTY* pty= new PTY[size];
    
    *pty = DTOInput("file1.txt", pty ,size, index);
    *pty = DTOInput("file2.txt", pty, size, index);
    DTOOutput(pty, size);
    system("pause");
    return 0;

}


