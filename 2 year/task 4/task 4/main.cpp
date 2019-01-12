/*
 29. В текстовому файлі задані дані про розміщення букв у тексті: набір буква-список позицій, на яких вона стоїть у тексті.
 - Визначити необхідні типи
 - ввести дані з файлу
 - вивести в файл1 посортований за кількістю перелік букв з вказанням їх кількості.
 - вивести у файл2 текст, утворений цими буквами.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
#include <iterator>
#include <sstream>
#include "Functions.h"

using namespace std;



int main()
{
    //ifstream file("file.txt");
    ifstream file("/Users/Andriana/Desktop/dz_programming/2 year/task 4/task 4/file.txt");
    try
    {
        map <char,list<int>> text=input(file);
        output(text);
        
        //ofstream file("task1.txt");
        ofstream task1("/Users/Andriana/Desktop/dz_programming/2 year/task 4/task 4/task1.txt");
        //output_task1(text);
        //output_task1_in_file(task1,text);
        multiset<pair<char, int>, cmp> symbols = task1_sort_map(text);
        another_output_task1_in_file(task1,symbols);
        
        
        
        //ofstream file("task2.txt");
        ofstream task2("/Users/Andriana/Desktop/dz_programming/2 year/task 4/task 4/task2.txt");
        task2_text_in_file(task2,text);
        
    }
    catch (exception &ex)
    {
        cout << "Error:" << ex.what() << endl;
    }
    
}

