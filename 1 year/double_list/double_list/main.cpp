//1. Створити клас для двозв’язного списку, що містить дані типу char. Визначити клас Ітератор для пересування по списку.
//2. Використовуючи список розв’язати поставлену задачу.
//28. Задані: натуральне число n, символи s1...s(n). Визначити число входжень в послідовність s1...s(n) груп букв abc;

#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List l;
    l.input();
    l.print();
    cout<<"number of abc"<<endl;
    cout<<l.number_of_abc('a','b','c')<<endl;
    return 0;
    
}
