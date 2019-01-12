/*1. Нехай в деякій їдальні можна замовити комплексні обіди двох брендів:  «Карпатський» та «Львівський».  «Карпатський» обід передбачає грибну юшку, вареники та увар, а «Львівський» – борщ, голубці та сік.  Нехай в текстовому файлі zamovl.txt задано декілька замовлень на обіди. Зчитати дані в контейнер замовлень
а) виконати всі замовлення – вивівши відповідні повідомлення у файл obidy.txt
б) вивести у файл rahunku.txt рахунки за замовлені обіди, окремо для двох брендів
в) збільшити ціну на вказану страву (1, 2 чи 3) та перерахувати всі рахунки
– файл vytraty.txt
2. Реалізувати завдання на основі патерну«Абстрактна фабрика».
*/
#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
int CARPPRICE=20;
int LVIVPRICE=30;
class FirstDish
{
public:
    virtual string eatFirstDish() = 0;
};

class SecondDish
{
public:
    virtual string eatSecondDish() = 0;
};


class ThirdDish
{
public:
    virtual string eatThirdDish() = 0;
};

class MushroomSoup : public FirstDish
{
public:
    string eatFirstDish()
    {
        return "mushroom soup\n";
    }
};

class Borsch : public FirstDish
{
public:
    string eatFirstDish()
    {
        return "borsch\n";
    }
};



class Varenuku : public SecondDish
{
public:
    string eatSecondDish()
    {
        return "varenuk\n";
    }
};

class Golubtsi : public SecondDish
{
public:
    string eatSecondDish()
    {
        return "Golubtsi\n";
    }
};

class Juice : public ThirdDish
{
public:
    string eatThirdDish()
    {
        return "sik\n";
    }
};

class Uzvar : public ThirdDish
{
public:
    string eatThirdDish()
    {
        return "uzvar\n";
    }
};




class DinnerFactory
{
protected:
public:
    virtual FirstDish* addFirstDish() = 0;
    virtual SecondDish* addSecondDish() = 0;
    virtual ThirdDish* addThirdDish() = 0;
};


class CarpDinner : public DinnerFactory
{
public:
    FirstDish* addFirstDish()
    {
        return new MushroomSoup();
    }
    SecondDish* addSecondDish()
    {
        return new Varenuku();
    }
    ThirdDish* addThirdDish()
    {
        return new Uzvar();
    }
};

class LvivDinner : public DinnerFactory
{
    FirstDish* addFirstDish()
    {
        return new Borsch();
    }
    SecondDish* addSecondDish()
    {
        return new Golubtsi();
    }
    ThirdDish* addThirdDish()
    {
        return new Juice();
    }
};



class Dinner
{
private:
    string type;
    FirstDish* first;
    SecondDish* second;
    ThirdDish* third;
public:
    Dinner(DinnerFactory* factory)
    {
        if (dynamic_cast<CarpDinner*>(factory))
        {
            type = "carp";
        }
        else if (dynamic_cast<LvivDinner*>(factory))
        {
            type = "lviv";
        }
        this->first = factory->addFirstDish();
        this->second = factory->addSecondDish();
        this->third = factory->addThirdDish();
    }
    
    friend ostream& operator << (ostream& os, Dinner* dinner)
    {
        os << dinner->first->eatFirstDish();
        os << dinner->second->eatSecondDish();
        os << dinner->third->eatThirdDish();
        os << "_________________\n";
        return os;
    }
    
    string getType()
    {
        return type;
    }
    
   
};



vector<Dinner*> input()
{
    vector<Dinner*> d;
    ifstream ifs("/Users/Andriana/Desktop/dz_programming/2 year/Ticket2/Ticket2/data.txt");
    if (!ifs.is_open())
    {
        throw ifstream::failure("");
    }
    char type;
    Dinner* tmp;
    while (!ifs.eof())
    {
        ifs >> type;
        switch (type)
        {
            case 'L':
            {
                d.push_back(new Dinner(new LvivDinner()));
            }
                break;
            case 'K':
            {
                d.push_back(new Dinner(new CarpDinner()));
            }
                break;
            default:
                throw invalid_argument("");
        }
    }
    
    return d;
}



void taskA(vector<Dinner*>& d,ofstream&ofs)
{
    for (int i =0;i<d.size();i++)
    {
        ofs << d[i];
    }
}

void taskB(vector<Dinner*>& d,ofstream&ofs)
{
    int carpPrice=0;
    int lvivPrice=0;
    for_each(d.begin(), d.end(), [&](Dinner* item)
             {if (item->getType() == "carp")carpPrice += CARPPRICE; else lvivPrice +=LVIVPRICE;});
    
    ofs << "carp dinners total price : " << carpPrice << "\n";
    ofs << "lviv dinners total price : " << lvivPrice << "\n";
}

void TaskC(vector<Dinner*>& d,ofstream&ofs)
{
    //recal here
    taskB(d,ofs);
}

int main()
{
    ofstream ofs("/Users/Andriana/Desktop/dz_programming/2 year/Ticket2/Ticket2/rah.txt");
    vector<Dinner*> dinners = input();
    taskA(dinners,ofs);
    taskB(dinners,ofs);
    return 0;
}
