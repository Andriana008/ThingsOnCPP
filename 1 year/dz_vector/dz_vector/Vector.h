//
//  Header.h
//  dz_vector
//
//  Created by Андріана Щербак on 26.03.17.
//  Copyright © 2017 Андріана. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;
class Vector {
private:
    double * arr;
    int size;
public:
    Vector() :arr(0), size(0)
    {
    }
    Vector(double* a, int s) :size(s)
    {
        arr = new double[size];
        for (int i = 0; i < size; i++)
            arr[i] = a[i];
    }
    Vector(const Vector &);
    Vector& operator=(const Vector& v);
    void input();
    void sort(Vector v);
    void print( Vector v);
    ~Vector();
    friend istream& operator >> (istream& is, Vector &  x);
    friend ostream& operator<<(ostream& os, Vector &  x);
};
