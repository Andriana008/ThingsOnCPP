/*
 Додати генерацію та обробку виняткових ситуації в код попереднього завдання - Двозвязний список або Матриця. Всі введення-виведення в цих завданнях робити з файлів
Створити власний клас винятку, похідний від exception, який міститиме додаткову інформацію про виняток і перевизначає функцію what
В коді при необхідності генеруємо – перехоплюємо винятки цього типу, а також бібліотечних типів, залежно від ситуації.
Зверніть особливу увагу на роботу з файлами (не існує, не вдалося відкрити, нема даних, невірний формат даних і ін.), доступ/видалення  неіснуючих елементів, вихід за межі масиву, виділення пам’яті
 */


#include <iostream>
//#include "exception.h"
#include <exception>
#include <fstream>
#include "list.h"
using namespace std;

int number_of_abc_with_i(LinkedList l, char a, char b, char c)
{
    int k = 0;
    LinkedList::iterator i(l);
    for (i = l.begin(); i != l.end(); i++)
    {
        if (*i == a)
        {
            if (*i++ == b)
            {
                if ((*i++)++ == c)
                {
                    k++;
                }
            }
        }
    }
    return k;
    
    
}

int main()
{
    LinkedList l;
    LinkedList::iterator i(l);
    
    ifstream file("/Users/Andriana/Desktop/dz_programming/double_list_with_exception/double_list_with_exception/file.txt",ios_base::in);
    string name;
    name="file.txt";
    
    try
    {
       if (!file.is_open())
       {
         throw "file cant be opened";
       }
    }
    catch (const char * a)
    {
        cout << a;
    }
    
    try
    {
      if (file.eof())
      {
        throw "file is empty";
      }
      else
      {
        l.input_f(file);
      }
    }
    
    catch (const char * b)
    {
        cout << b;
    }
    
    l.print();
    cout << "Numbers of abc" << endl;
    cout << number_of_abc_with_i(l, 'a', 'b', 'c') << endl;
    
    return 0;
}












