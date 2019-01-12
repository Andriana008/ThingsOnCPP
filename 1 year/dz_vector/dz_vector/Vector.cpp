//
//  Vector.cpp
//  dz_vector
//
//  Created by Андріана Щербак on 26.03.17.
//  Copyright © 2017 Андріана. All rights reserved.
//



#include "Vector.h"


Vector::Vector(const Vector& v)
{
    size = v.size;
    arr = new double[size];
    for (int i = 0; i<size; i++)
        arr[i] = v.arr[i];
}

void Vector::sort(Vector v)
{
    size = v.size;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                double temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Vector::print(Vector v)
{
    size = v.size;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i]<<" ";
    }
    
}
void Vector::input()
{
    cout << "Enter size of vector" << endl;
    cin >> size;
    arr = new double[size];
    for (int i = 0; i<size; i++)
        cin >> arr[i];
};

Vector & Vector::operator=(const Vector& v)
{
    if (this != &v)
    {
        if (arr != 0)
        {
            delete[] arr;
        }
        arr= new double[size = v.size];
        for (int i = 0; i<size; i++)
            arr[i] = v.arr[i];
    }
    return *this;
}
Vector::~Vector()
{
    if (arr != 0) delete[] arr;
}
istream& operator >> (istream& is, Vector &  x)
{
    if (x.arr != 0) delete[] x.arr;
    is >> x.size;
    x.arr = new double[x.size];
    for (int i = 0; i<x.size; i++)
        is >> x.arr[i];
    return is;
}
ostream& operator<<(ostream& os, Vector&  x)
{
    os << "Vector size = " << x.size << endl;
    os << "Vector elements :";
    for (int i = 0; i<x.size; i++)
        os << x.arr[i] << " ";
    return os;
}

