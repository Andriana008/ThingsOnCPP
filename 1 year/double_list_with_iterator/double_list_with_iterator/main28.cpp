//1. Створити клас для двозв’язного списку, що містить дані типу char. Визначити клас Ітератор для пересування по списку.
//2. Використовуючи список розв’язати поставлену задачу.
//28. Задані: натуральне число n, символи s1...s(n). Визначити число входжень в послідовність s1...s(n) груп букв abc;

#include <iostream>
#include "list.h"
using namespace std;

int number_of_abc_with_i(LinkedList l,char a,char b,char c)
{
    int k=0;
    LinkedList::iterator i(l);
    for(i=l.begin();i!=l.end();i++)
    {
        if(*i==a)
        {
            if(*i++==b)
            {
                if((*i++)++==c)
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
    l.input();
    cout<<"Numbers of abc"<<endl;
    cout<<number_of_abc_with_i(l,'a', 'b', 'c')<<endl;

    return 0;
}
