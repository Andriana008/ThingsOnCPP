/*1. Патерн Composite. Розробити структуру класів для представлення каталогу товарів деякого супермаркету. Передбачається, що каталог може мати деревовидну структуру із довільною глибиною вкладеності категорій товарів. Кінцевий товар містить ціну та ІD. Програма повинна зчитати дані про категорії та товари, а також видрукувати каталог у файл у розгорнутому вигляді.
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>

using namespace std;

//TODO move classes to separate file
//DONE

#include "Classes.h"

//TODO change the way of entering information to more understandable one and rename variables
//DONE

Department input(ifstream&file)
{
    string name_of_shop;
    file >> name_of_shop;
    
    Department shop(name_of_shop);
    
    int size_of_departments;
    file >> size_of_departments;
    
    for (int i = 0; i<size_of_departments; i++)
    {
        Department* pro = new Department();
        pro->input(file);
        
        int size_of_products_of_department;
        file >> size_of_products_of_department;
        
        for (int j = 0; j<size_of_products_of_department; j++)
        {
            Product* pr= new Product();
            pr->input(file);
            pro->add(pr);
        }
        
        shop.add(pro);
    }
    return shop;
}

int main()
{
    ifstream file("/Users/Andriana/Desktop/dz_programming/2 year/task7/task7/data.txt");
    
    ofstream result("/Users/Andriana/Desktop/dz_programming/2 year/task7/task7/result.txt");
    
    try
    {
        if (!file.is_open())
        {
            throw ifstream::failure("can not open file");
        }
        Department shop = input(file);
        shop.print_catalog(0);
        shop.print_catalog_in_file(result, 0);
    }
    catch (exception & ex)
    {
        cout << ex.what() << endl;
    }
    
    return 0;
}
