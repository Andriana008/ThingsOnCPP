//
//  main.cpp
//  dz_vector
//
//  Created by Андріана Щербак on 26.03.17.
//  Copyright © 2017 Андріана. All rights reserved.
//

#include <iostream>
#include "Vector.h"
using namespace std;
int main()
{
    Vector v;
    v.input();
    Vector v1(v);
    v.print(v);
    cout << "First massive"<<endl;
    v1.sort(v1);
    v1.print(v1);
    cout << "Sort massive" << endl;
    
    return 0;
    
}
