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


class Component
{
public:
    string name;
    int price;
    int id;
    
    Component():name(""),price(0),id(0){};
    Component(string n,int p,int d):name(n),price(p),id(d){}
    Component(string n):name(n){}
    
    virtual void print_catalog(int level)=0;
    virtual void print_catalog_in_file(ofstream&file,int level)=0;
};

class Product:public Component
{
public:
    Product():Component(){};
    Product(string nam,int pr,int i):Component(nam,pr,i){}
    Product(string nam):Component(nam){}
    
    void print_catalog(int level)
    {
        for(int j=0; j < level; ++j)
        {
            cout << "\t";
        }
        cout << "Product : " <<name << ",prize: " <<price <<",id:"<<id<< "\n";
    }
    
    void print_catalog_in_file(ofstream&file,int level)
    {
        for(int j=0; j < level; ++j)
        {
            file << "\t";
        }
        file << "Product : " <<name << ",prize: " <<price <<",id:"<<id<< "\n";
    }
    void input(ifstream&file)
    {
        file>>name;
        file>>price;
        file>>id;
    }
};

class Department:public Component
{
private:
    vector<Component*> products;
public:
    Department(string nam,int pr,int i):Component(nam,pr,i){}
    Department(string nam):Component(nam){}
    Department():Component(){};
    
    void add(Component *element)
    {
        products.push_back(element);
    }
    
    void input(ifstream&file)
    {
        file>>name;
    }
    
    void print_catalog(int level)
    {
        for(int j=0; j < level; ++j)
        {
            cout << "\t";
        }
        cout << "Department : " <<name << "\n";
        if(!products.empty())
        {
            for(int x=0; x < level; ++x)
            {
                cout << "\t";
            }
            cout << "Products  of " <<name << ":\n";
            
            ++level;
            
            for (int i = 0; i < products.size(); ++i)
            {
                products[i]->print_catalog(level);
            }
        }
    }
    
    void print_catalog_in_file(ofstream&file,int level)
    {
        for(int j=0; j < level; ++j)
        {
            file << "\t";
        }
        file << "Department : " <<name << "\n";
        if(!products.empty())
        {
            for(int x=0; x < level; ++x)
            {
                file << "\t";
            }
            file << "Products  of " <<name << ":\n";
            
            ++level;
            
            for (int i = 0; i < products.size(); ++i)
            {
                products[i]->print_catalog_in_file(file,level);
            }
        }
    }
};



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
