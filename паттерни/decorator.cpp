/*1. Нехай в деякому кафе можна замовити кофейні напитки на основі трьох різних сортів кави (Espresso, DarkRoast, HouseBlend) та трьох різних добавок (Cream, Chocolate, Milk). В текстових файлах orders1.txt та orders2.txt задано списки замовлень на напитки (сорт кави і список добавок із зазначенням їх кількості). Зчитати дані в контейнер напитків.
 а) Вивести в файл bills.txt рахунки за напитки: назва напитку, вартість.
 б) Знайти найдорожчий та найдешевший напитки.
 в) Використовуючи асоціативний контейнер утворити список витрат для кожного продукту: назва – кількість. Вивести його у файл.
 2. Реалізувати завдання на основі патерну «Декоратор».
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
class Beverage
{
public:
    string description = "Unknown Beverage";
    virtual string getDescription()
    {
        return description;
    }
    virtual double cost()=0;
};

class Espresso:public Beverage {
public:
    Espresso()
    {
        description = "Espresso";
    }
    double cost()
    {
        return 10;
    }
};
class HouseBlend:public Beverage {
public:
    HouseBlend()
    {
        description = "HouseBlend";
    }
    double cost()
    {
        return 15;
    }
};
class DarkRoast:public Beverage {
public:
    DarkRoast()
    {
        description = "DarkRoast";
    }
    double cost()
    {
        return 20;
    }
};

class CondimentDecorator:public Beverage {
public:
    virtual string getDescription()=0;
};

class Chocolate:public CondimentDecorator {
public:
    Beverage *beverage;
    Chocolate(Beverage *beverage) {
        this->beverage = beverage;
    }
    string getDescription()
    {
        return beverage->getDescription( ) + ", Chocolate ";
    }
    double cost() {
        return 15 + beverage->cost();
    }
};
class Cream:public CondimentDecorator {
public:
    Beverage *beverage;
    Cream(Beverage *beverage) {
        this->beverage = beverage;
    }
    string getDescription()
    {
        return beverage->getDescription( ) + ", Cream ";
    }
    double cost() {
        return 9 + beverage->cost();
    }
};
class Milk:public CondimentDecorator {
public:
    Beverage *beverage;
    Milk(Beverage *beverage) {
        this->beverage = beverage;
    }
    string getDescription()
    {
        return beverage->getDescription( ) + ", Milk ";
    }
    double cost() {
        return 12 + beverage->cost();
    }
};
void total_cost_of_milk(ofstream& result,int n)
{
    cout<<"milk "<<12*n<<endl;
    result<<"milk "<<12*n<<endl;
}
void total_cost_of_cream(ofstream& result,int n)
{
    cout<<"cream "<<9*n<<endl;
    result<<"cream "<<9*n<<endl;
}
void total_cost_of_chocolate(ofstream& result,int n)
{
    cout<<"chocolate "<<15*n<<endl;
    result<<"chocolate "<<15*n<<endl;
}
void output_topping_and_price(ofstream& result,int m,int c,int h)
{
    total_cost_of_milk(result,m);
    total_cost_of_cream(result,c);
    total_cost_of_chocolate(result,h);
    
}

vector<Beverage*> input(ifstream&file,ofstream& result)
{
    vector<Beverage*> drinks;
    int c=0,h=0,m=0;
    while (!file.eof())
    {
        int size;
        file>>size;
        for(int i=0;i<size;i++)
        {
            int size_of_topping;
            string coffee_name;
            file >> coffee_name;
            file >> size_of_topping;
            Beverage* drink = nullptr;
            if(coffee_name == "Espresso")
            {
                drink = new Espresso();
            }
            else if(coffee_name == "HouseBlend")
            {
                drink = new HouseBlend();
            }
            else if(coffee_name == "DarkRoast")
            {
                drink = new DarkRoast();
            }
            else throw invalid_argument("bad data in file");
            for (int i = 0; i < size_of_topping; i++)
            {
                string topping_name;
                file >> topping_name;
                
                if (topping_name == "Cream")
                {
                    c++;
                    drink = new Cream(drink);
                }
                else if (topping_name == "Chocolate")
                {
                    h++;
                    drink = new Chocolate(drink);
                }
                else if (topping_name == "Milk")
                {
                    m++;
                    drink = new Milk(drink);
                }
                else throw invalid_argument("bad data in file");
            }
            drinks.push_back(drink);
        }
    }
    //vector<pair<string,int>>a;
    //a.push_back(make_pair("Milk",m));
    //a.push_back(make_pair("Chocolate",h));
    //a.push_back(make_pair("Cream",c));
    //output_topping_and_price(a);
    output_topping_and_price(result,m,c,h);
    return drinks;
}

vector<Beverage*> adding(vector<Beverage*> orders1, vector<Beverage*> orders2)
{
    vector<Beverage*> orders;
    for(int i=0;i<orders1.size();i++)
    {
        orders.push_back(orders1[i]);
    }
    for(int i=0;i<orders2.size();i++)
    {
        orders.push_back(orders2[i]);
    }
    return orders;
}
void output_orders(ofstream&file,vector<Beverage*>v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]->getDescription()<<endl;
        cout<<v[i]->cost()<<endl;
        file<<v[i]->getDescription()<<endl;
        file<<v[i]->cost()<<endl;
    }
}
vector<pair<string,int>> vector_in_pairs(vector<Beverage*>v)
{
    vector<pair<string,int>>a;
    for(int i=0;i<v.size();i++)
    {
        pair<string,int>p;
        p.first=v[i]->getDescription();
        p.second=v[i]->cost();
        a.push_back(p);
    }
    return a;
}
struct comp
{
    bool operator() (const pair<string,int>p1, pair<string,int>p2) { return (p1.second>p2.second);}
} cmp;

void find_max(ofstream&file,vector<pair<string,int>>a)
{
    sort (a.begin(), a.end(), cmp);
    auto it =a.begin();
    cout<<"max"<<endl;
    cout<<(*it).first<<(*it).second<<endl;
    file<<"max"<<endl;
    file<<(*it).first<<(*it).second<<endl;
}
void find_min(ofstream&file,vector<pair<string,int>>a)
{
    sort (a.begin(), a.end(), cmp);
    auto it =a.end()-1;
    cout<<"min"<<endl;
    cout<<(*it).first<<(*it).second<<endl;
    file<<"min"<<endl;
    file<<(*it).first<<(*it).second<<endl;
}
void output_max_and_min_in_file(ofstream&file,vector<pair<string,int>>a)
{
    find_max(file,a);
    find_min(file,a);
}


int main()
{
    ifstream file1("/Users/Andriana/Desktop/dz_programming/2 year/Ticket1/Ticket1/orders1.txt");
    ifstream file2("/Users/Andriana/Desktop/dz_programming/2 year/Ticket1/Ticket1/orders2.txt");
    ofstream result("/Users/Andriana/Desktop/dz_programming/2 year/Ticket1/Ticket1/result.txt");
    ofstream bills("/Users/Andriana/Desktop/dz_programming/2 year/Ticket1/Ticket1/bills.txt");
    vector<Beverage*> orders1=input(file1,result);
    vector<Beverage*> orders2=input(file2,result);
    vector<Beverage*> orders=adding(orders1,orders2);
    output_orders(bills,orders);
    vector<pair<string,int>>task1=vector_in_pairs(orders);
    output_max_and_min_in_file(result,task1);
    
}
/*int main()
{
   
    Beverage *beverage = new Espresso();
    cout<<beverage->getDescription()<<beverage->cost()<<endl;
    Beverage *beverage2 = new DarkRoast();
    beverage2 = new Cream(beverage2);
    beverage2 = new Cream(beverage2);
    beverage2 = new Milk(beverage2);
    cout<<beverage2->getDescription()<<beverage2->cost()<<endl;
    
}*/





