#include <iostream>
#include "Set.h"
//#include <gtest/gtest.h>
//#include "google_tests.h"


int main()
{
    Set s;
    s.add('f');
    std::cout<<s.is_in_set('f')<<std::endl;
}
