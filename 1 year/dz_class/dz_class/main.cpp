/*28.	Визначити тип для представлення товару в магазині. Товар характеризується: унікальним кодом,
 ціною за одиницю товару, кількістю товару в магазині.
 В класі крім необхідних методів визначити конструктор за замовчуванням
 та конструктори з параметрами, функції введення, виведення.
	а) Ввести дані про 12 товарів. Вивести їх у такому форматі:
 code		price		        number
 12		12 грн 30 коп 	10
 78		0 грн 45 коп		25
 …
 б)Знайти  сумарну вартість всіх товарів. Видрукувати 5 найдешевших товарів.
 */

#include "Tovar.hpp"//в xcode hpp в vs р//
#include <iostream>
#include <string>
using namespace std;
void sort(Tovar*arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j =0 ; j < size-1; j++)
        {
            if (arr[j].getPrice() > arr[j + 1].getPrice())
            {
                Tovar t=arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}
double sum(Tovar*arr, int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i].getPrice();
    }
    return sum;
}
int main()
{
    int n;
    cout << "enter kilkist of tovars > 5" << endl;
    cin >> n;
    setlocale(LC_ALL, "Ukrainian");
    Tovar *arr = new Tovar[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].input();
    }
    for (int i = 0; i < n; i++)
    {
        arr[i].print();
    }
    cout << "otsortovano"<<endl;
    sort(arr,n );
    for (int i = 0; i < n; i++)
    {
        arr[i].print();
    }
    cout << "5 minimum prices" << endl;
    for (int i = 0; i < 5; i++)
    {
        arr[i].print();
    }
    
    cout << "sum = "<<sum(arr,n)<<endl;
    system("pause");
}
