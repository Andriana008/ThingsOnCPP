#pragma once

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


