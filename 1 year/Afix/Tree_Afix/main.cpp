#include <iostream>
#include "Postfix.h"
#include "Stack.h"
using namespace std;

int main()
{
    OPN test("11 ^ 2 - 400 * 1.2");
    cout<<test.convert()<<endl;
    cout<<test.calculate()<<endl;
    return 0;
}
