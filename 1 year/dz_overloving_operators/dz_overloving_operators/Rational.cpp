//
//  Rational.cpp
//  dz_overloving_operators
//
//  Created by Андріана Щербак on 26.03.17.
//  Copyright © 2017 Андріана. All rights reserved.
//

#include "Rational.hpp"

istream&operator >> (istream&is, Rational& r)
{
    cout << "Input a,b" << endl;
    is >> r.up;
    while (true)
    {
        is >> r.down;
        if (r.down == 0)
        {
            cout << "retry" << endl;
        }
        else
        {
            break;
        }
        
    }
    
    return is;
}
ostream& operator<<(ostream&os, Rational& r)
{
    os << "a: " << r.up << "b: " << r.down << endl;
    return os;
}
Rational::Rational(const Rational & r)
{
    up = r.up;
    down = r.down;
}
double Rational::value()
{
    return up / down*1.0;
}
void Rational::input()
{
    cout << "enter rational number "<<endl;
    cin >> up;
    cin >> down;
    if(down == 0)
    {
        cout << "enter another number "<<endl;
    }
    
}
void Rational::print()
{
    cout << "rational humbers"<<endl;
    cout<< up<<"/"<< down<<endl;
}
int Rational:: gcd(int x, int y)
{
    int k;
    if (y == 0)
    {
        return 0;
    }
    
    k = x%y;
    while (k != 0)
    {
        x = y;
        y = k;
        k = x%y;
    }
    return k;
}

void Rational::reduce()
{
    int l;
    l = gcd(up, down);
    if (l != 0)
    {
        up = up / l;
        down = down / l;
    }
}



