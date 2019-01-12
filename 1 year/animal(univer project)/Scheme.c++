#pragma once
#include <iostream>
#include <string>
using namespace std;
/*
class A
{
private:
    int a;
public:
    A(int) {}
    void input()
    {
        cin >> a;
    }
    int get()
    {
        return a;
    }
};
class B
{
private:
    char b;
public:
    B(char) {}
    void input()
    {
        cin >> b;
    }
    int get()
    {
        return b;
    }
};
 
class C: public A, public B
{
private:
    string c;
public:
    C() :A(0), B('0'), c("") {}// якщо нема за замовчуванням, беремо з параметрами
    C(string _c, int a, char b) :A(a), B(b), c(_c) {}
    void input()
    {
        A::input();
        B::input();
        cin >> c;
    }
    friend ostream& operator<<(ostream& os, C& c1)
    {
        os << A::get();
        os << B::get();
        os << c1.c;
        return os;
    }
 
};
/*
void main()
{
    /*C* mas[3];
    mas[0] = new A();//не було конструктора без параметрів
    mas[1] = new B('a');
    mas[2] = new C;
    for (int i = 0; i < 3; i++)
    {
        mas[i]->input();
        cout << mas[i];
    }*/
    /*C* mas[3];
    mas[0] = new A(5);//не було конструктора без параметрів, + не можемо створювати об'єкт А
    mas[1] = new B('a');// це все погано
    mas[2] = new C;
    for (int i = 0; i < 3; i++)
    {
        mas[i]->input();
        cout << mas[i];
    }
 
}
*/
 
//next
/*
class D
{
private:
    int d;
public:
    D(int) {}
    virtual void input()
    {
        cin >> d;
    }
    int get()
    {
        return d;
    }
 
};
 
class A: virtual public D
{
private:
    int a;
public:
    A(int b):D(0), a(b) {}
     void input()//якщо тут не віртуал, то віртуальність все одно зберігається, бо вона є в головному
    {
        D::input();
        cin >> a;
    }
    int get()// не віртуал, і завжди буде викликатись з базового
    {
        return a;
 
    }
};
 
class B: virtual public D
{
private:
    char b;
public:
    B(char c): D(0), b(c) {}
     void input()//якщо тут не віртуал, то віртуальність все одно зберігається, бо вона є в головному, з кожного класу свій викликається
    {
        D::input();//це можна забрати, а в мейні одразу з Д
        cin >> b;
    }
    int get()// не віртуал, і завжди буде викликатись з базового
    {
        return b;
 
    }
};
 
class C: public A, public B
{
private:
    string c;
public:
    C(string c1) :D(0),A(0), B('0'), c(c1) {}// тут викликати з Д теж, бо ми написали наслідування віртуал
    void input()
    {
        A::input();// перепишуться дані
        B::input();
        cin >> c;
    }
    string get()
    {
        cout << D::get() << A::get() << B::get() << c;
    }
};
*/
 
 
class A
{
private:
    int a;
    public:
    A(int) {}
    virtual void input();
    int get();
};
class B
{
private:
    int b;
public:
    B(int) {}
    virtual void input();
     int get();
 
};
class C: public A, public B
{
    string c;
public:
    C(string _c, int _a, int _b) :A(_a), B(_b), c(_c) {}
    void input()
    {
        A::input();
        B::input();
        cin >> c;
    }
    string get()
    {
        return c;
    }
};
class D: public C
{
    int d;
public:
    D(int _d, string _c, int _a, int _b) : C(_c, _a, _b), d(_d) {}// клас Д знає тільки про клас С
    void input()
    {
        C::input();
        cin >> d;
    }
    void print()
    {
        cout << A::get();
        cout << B::get();
        cout << C::get();
        cout << d;
 
    }
};