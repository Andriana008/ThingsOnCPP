//
//  Rational.hpp
//  dz_overloving_operators
//
//  Created by Андріана Щербак on 26.03.17.
//  Copyright © 2017 Андріана. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;
class Rational
{
private:
    int up;
    int down;
public:
    Rational() :up(0), down(1) {}
    Rational(int d, int c = 1) :up(d), down(c) {}
    Rational(const Rational &);
    void input();
    void print();
    int gcd(int x,int y);
    void reduce();
    double value();
    friend istream& operator>>(istream&is, Rational& r);
    friend ostream& operator<<(ostream&os, Rational& r);
    Rational & operator +(const Rational&x)
    {
        Rational result ((up *x.down)+(down *x.up), down*x.down);
        result.reduce();
        return *this;
    }
    Rational& operator+=(const Rational& x)
    {
        return *this = *this + x;
    }
    Rational & operator -(const Rational&x)
    {
        Rational result ((up *x.down) - (down *x.up), down*x.down);
        result.reduce();
        return *this;
    }
    Rational &  operator *(const Rational&x)
    {
        Rational result(up *x.up, down *x.down);
        return *this;
    }
    Rational &  operator /(const Rational&x)
    {
        Rational result(up *x.down, down *x.up);
        return *this;
    }
    ~Rational() {};
    
};
