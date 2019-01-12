//
//  Tovar.hpp
//  dz_class
//
//  Created by Андріана Щербак on 20.02.17.
//  Copyright © 2017 Андріана. All rights reserved.
//

#include <iostream>
using namespace std;
class Tovar
{
private:
    int cod;
    double price;
    int number;
public:
    Tovar(): cod(0), price(0), number(0)
    {
    }
    Tovar(int c, int p, int k) :cod(c), price(p), number(k)
    {
    }
    Tovar(const Tovar&x) :cod(x.cod), price(x.price), number(x.number)
    {
    }
    void input()
    {
        cout << "enter code,price, number" << endl;
        cin >> cod >> price >> number;
    }
    void print()
    {
        cout <<"\t"<<cod << "\t" << (int)price<<" грн "<<price-(int)price<<" коп " << "\t" << number <<endl;
    }
    double getPrice() {
        return price;
    }
};

