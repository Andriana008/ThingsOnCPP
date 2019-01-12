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
#include "Classes.h"
#include "Function.h"


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





