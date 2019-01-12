//
//  main.cpp
//  dz_overloving_operators
//
//  Created by Андріана Щербак on 26.03.17.
//  Copyright © 2017 Андріана. All rights reserved.
//

#include<iostream>
using namespace std;
#include "Rational.hpp"
int main()
{
    int n;
    cout << "enter size of vector a and b ";
    cin >> n;
    Rational *a=new Rational[n];
    Rational *b=new Rational[n];
    for (int i = 0; i < n; i++)
    {
        a[i].input();
    }
    for ( int i = 0; i < n; i++)
    {
        b[i].input();
    }
    cout << "Your vectors";
    for (int i = 0; i < n; i++)
    {
        a[i].print();
    }
    for (int i = 0; i < n; i++)
    {
        b[i].print();
    }
    int k = 1;
    Rational sum1;
    Rational sum2;
    Rational dob;
    Rational subt;
    for (int i = 0; i < n; i++)
    {
        if ((a[i].value() >= 3) && (a[i].value() <= 7) && (b[i].value() >= 3) && (b[i].value() <= 7))
        {
            sum1 = a[i] + b[i];
            dob = a[i] * b[i];
            subt = a[i] - b[i];
            sum2 += dob;
            cout << k << "Sum:" << endl;
            sum1.print();
            cout << "Subtraction:" << endl;
            subt.print(); 
            cout << "Sum of multiply a*b:" << endl;
            sum2.print();  
            k++;
        }
    }
    return 0;
}
