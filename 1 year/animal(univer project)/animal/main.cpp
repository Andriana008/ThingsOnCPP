

#include<iostream>
using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout<<"silence "<<endl;
    }
    virtual void area()=0;// всі тварини десь живуть, але не всі щось говорять, тому цей метод чистий
    
    virtual void breath()=0;
    
    virtual void action()=0;
};

class Fish: public Animal
{
    // говорити ми не визначаємо, бо риба не говорить
    virtual void area()
    {
        cout<<"water"<<endl;
    }
    virtual void breath()//якщо від нього буде ще похідний то треба писати віртуал тут, якщо ні то не обов'язково
    {
        cout<<"gills"<<endl;
    }
    virtual void action()
    {
        cout<<"swim"<<endl;
    }
    
};

class Mammal: public Animal
{
public:
    virtual void speak() = 0;
    virtual void area()
    {
        cout<<"Everywhere";
    }
    void breath()
    {
        cout<<"lungs";
    }
    virtual void limbs()
    {
        cout<<"Has some";
    }
};

class Cat:public Mammal
{
public:
    void speak()
    {
        cout<<"Meow";
    }
    void area()
    {
        cout<<"home";
    }
    void limbs()
    {
        cout<<"four";
    }
    void action()
    {
        cout<<"goes";
    }
};

class Swan: public Mammal, public Fish
{
public:
    void limbs()
    {
        cout<<"two legs, two wings";
    }
    void area()
    {
        cout<<"lake";
    }
    void speak()
    {
        cout<<"shhhhhh";
    }
    void action()
    {
        cout<<"swims";
    }
    /*void breath()
     {
     Mammal::breath();
     }*/
};

int main()
{
    
    Cat murchik;
    murchik.action();
    Mammal *object;
    Swan lebid;
    object = &lebid;
    object->breath();
    
    // або lebid.mammal::breath(); якщо в лебідь визначити void breath !!!!!! в мене в дз так пробувати
    system("PAUSE");
    return 0;
}
