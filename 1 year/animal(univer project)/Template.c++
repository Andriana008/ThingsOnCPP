#include <iostream>
using namespace std;
template<typename T>
void sort (T*first, T*last)
{
    T* temp=first;
    while(first!= last)
    {
        T* temp2=temp+1;
        while(temp2!=last+1)
        {
            if(*temp<*temp2)
            {
                T buff;
                buff=*temp;
                *temp=*temp2;
                *temp2=buff;
            }
            temp++;
            temp2++;
        }
    last--;
    temp = first;
   
    }
 
 
 
}
 
template <typename T>
void sort1(T* array, int size)
{
    bool swapper = false;
    for(int i=0;i<size-1&&swapper;i++)
    {
        swapper=false;
        for(int j=0;j<size-1-i;j++)
        {
            if(array[j]>array[j+1])
            {
                T temp;
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                swapper=true;
            }
        }
    }
 
}
 
template<typename T>
typedef bool(*compare(T& obj1, T& obj2));
 
template<typename T>
void bubble_sort(T* array, int size, compare g)
{
    bool swapper = false;
    for(int i=0;i<size-1&&swapper;i++)
    {
        swapper=false;
        for(int j=0;j<size-1-i;j++)
        {
            if(g(array[j]>array[j+1]))
            {
                T temp;
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                swapper=true;
            }
        }
    }
}
bool func(int a,int b)
{
    return a>b?true:false;
}
 
template<typename T>
void input(T* array, int size)
{
    for(int i=0;i<size;i++)
    {
        cin>>array[i];
    }
}
 
int main()
{
    int array[10];
for (int i=0;i<10;i++)
{
    array[i]=i;
}
double array2[3];
for (int i=0;i<3;i++)
{
    array2[i]=i+1;
}
sort<int>(array,array+9);
sort1<double>(array2,3);
 
int arr[10];
 
    system("pause");
    return 0;
}