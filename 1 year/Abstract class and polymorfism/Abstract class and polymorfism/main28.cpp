/*Визначити абстрактний тип Живий організм, похідні абстрактні Рослина,Тварина. Та відповідні похідні  Кущі, Дерева, Комахи, Рептилії.  Ввести дані про 10 живих організмів. Вивести дані про окремо про рослини – в алфавітному порядку назв, окремо про тварини – в порядку спадання кількості. Знайти всі рослини, занесені в червону книгу.
*/
#include <iostream>
#include <string>
#include "Classes.h"
using namespace std;
void sort(Animal**arr, Organizm**a, int size)
{
    int c = 0;
    for (int i = 0; i < size; i++)
    {
        if (dynamic_cast<Animal*>(a[i]))
        {
            arr[c] = dynamic_cast<Animal*>(a[i]);
            //dynamic_cast для приведення типу даних
            c++;
        }
    }
    for (int i = 0; i<c-1; i++)
    {
        for (int j = 0; j<c - 1-i; j++)
        {
            if (arr[j]->get_number()<arr[j + 1]->get_number())
            {
                Animal* t;
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}
void sort(Plant**arr, Organizm**a, int size)
{
    int c = 0;
    for (int i = 0; i < size; i++)
    {
        if (dynamic_cast<Plant*>(a[i]))
        {
            arr[c] = dynamic_cast<Plant*>(a[i]);
            c++;
        }
    }
    for (int i = 0; i<c-1; i++)
    {
        for (int j = 0; j<c - 1-i; j++)
        {
            if (arr[j]->get_name()>arr[j + 1]->get_name())
            {
                Plant* t;
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}
int main()
{
    int a=0,b=0;
    Organizm *organ[10];
    for(int i=0;i<10;i++)
    {
        int s;
        cout<<"Enter 1 for Bush ,2-Tree,3-Insect,4-Reptilia"<<endl;
        cin>>s;
        switch(s)
        {
          case 1:
            {
                 organ[i]=new Bush();
                 organ[i]->input();
                 a++;
                 break;
            }
          case 2:
            {
                 organ[i]=new Tree();
                 organ[i]->input();
                 a++;
                 break;
            }
          case 3:
            {
                 organ[i]=new Insect();
                 organ[i]->input();
                 b++;
                 break;
            }
          case 4:
            {
                 organ[i]=new Reptilian();
                 organ[i]->input();
                 b++;
                 break;
            }
          default:
                cout << "Enter 1 ,2 ,3 or 4 :"<<endl;
                continue;
        }
    }
    
    
    cout<<"Organizms"<<endl;
    for(int i=0;i<10;i++)
    {
            organ[i]->print();
    }
    
    Plant **pl=new Plant*[a];
    Animal **an=new Animal*[b];
    sort(pl,organ,10);
    sort(an,organ,10);
    
    cout<<"Plants in alfabetic order"<<endl;
    for(int j=0;j<a;j++)
    {
        pl[j]->print();
    }
    
    cout<<"Animals in order of descending numbers"<<endl;
    for(int j=0;j<b;j++)
    {
        an[j]->print();
    }
    
    cout<<"Plants ,which are in red book"<<endl;
    for(int j=0;j<a;j++)
    {
      if(pl[j]->in_book()==true)
      {
        pl[j]->print();
      }
    }
    return 0;
}





















