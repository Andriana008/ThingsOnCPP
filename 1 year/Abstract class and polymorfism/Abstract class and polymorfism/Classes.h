/*Визначити абстрактний тип Живий організм, похідні абстрактні Рослина,Тварина.
 Та відповідні похідні  Кущі, Дерева, Комахи, Рептилії. 
 Ввести дані про 10 живих організмів. Вивести дані про окремо про рослини – в алфавітному порядку назв,
 окремо про тварини – в порядку спадання кількості. Знайти всі рослини, занесені в червону книгу.
 */

#include <iostream>
#include <string>
using namespace std;

class Organizm
{
protected:
    string species;
public:
    Organizm():species(" "){};
    virtual ~Organizm()
    {
        this->species.clear();
    };
    virtual void print()=0;
    virtual void input()=0;
};

class Animal:public Organizm
{
protected:
    string name;
    int number;
public:
    Animal():Organizm(),name(" "),number(0){};
    Animal(Organizm n,string na,int num):Organizm(n),name(na),number(num){};
    virtual ~Animal()
    {
        this->name.clear();
    };
    virtual void print()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"Number :"<<number<<endl;
    }
    virtual void input()
    {
        cout<<"Enter name and number :"<<endl;
        cin>>name>>number;
    }
    virtual bool can_fly()=0;
    int get_number()
    {
        return number;
    }
    string get_name()
    {
        return name;
    }
};

class Plant:public Organizm
{
protected:
    string name;
    bool red_book;
public:
    Plant():Organizm(),name(" "),red_book(0){};
    Plant(Organizm n,string na,bool num):Organizm(n),name(na),red_book(num){};
    virtual ~Plant()
    {
        this->name.clear();
    };
    virtual void print()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"Red book(1-yes,2-no) :"<<red_book<<endl;
    }
    virtual void input()
    {
        cout<<"Enter name and availibility of red book (1-yes,2-no):"<<endl;
        cin>>name>>red_book;
    }
    virtual bool is_green()=0;
    string get_name()
    {
        return name;
    }
    bool in_book()
    {
        return red_book;
    }
};

class Bush:public Plant
{
protected:
    string place;
public:
    Bush():Plant(), place(" "){};
    Bush(Plant n,string na):Plant(n), place(na){};
    virtual ~Bush()
    {
        this->place.clear();
    };
    virtual void print()
    {
        Plant::print();
        cout<<"Place of living :"<<place<<endl;
    };
    virtual void input()
    {
        Plant::input();
        cout<<"Place of living :"<<endl;
        cin>>place;
    };
    bool is_green()
    {
        return true;
    }

};

class Tree:public Plant
{
protected:
    string place;
public:
    Tree():Plant(), place(" "){};
    Tree(Plant n,string na):Plant(n), place(na){};
    virtual ~Tree()
    {
        this->place.clear();
    };
    virtual void print()
    {
        Plant::print();
        cout<<"Place of living :"<<place<<endl;
    };
    virtual void input()
    {
        Plant::input();
        cout<<"Place of living :"<<endl;
        cin>>place;
    };
    bool is_green()
    {
        return true;
    }
  
};

class Insect:public Animal
{
protected:
    string place;
public:
    Insect():Animal(), place(" "){};
    Insect(Animal n,string na):Animal(n), place(na){};
    virtual ~Insect()
    {
        this->place.clear();
    }
    virtual void print()
    {
        Animal::print();
        cout<<"Place of living :"<<place<<endl;
    }
    virtual void input()
    {
        Animal::input();
        cout<<"Place of living :"<<endl;
        cin>>place;
    };
    bool can_fly()
    {
        return true;
    }
};

class Reptilian:public Animal
{
protected:
    string place;
public:
    Reptilian():Animal(), place(" "){};
    Reptilian(Animal n,string na,bool num):Animal(n), place(na){};
    virtual ~Reptilian()
    {
        this->place.clear();
    };
    virtual void print()
    {
        Animal::print();
        cout<<"Place of living :"<<place<<endl;

    };
    virtual void input()
    {
        Animal::input();
        cout<<"Place of living :"<<endl;
        cin>>place;
    };
    bool can_fly()
    {
        return false;
    }
};
