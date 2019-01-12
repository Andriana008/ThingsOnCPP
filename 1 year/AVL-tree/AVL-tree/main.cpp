#include <iostream>
#include "AVL.h"
using namespace std;

int main()
{
    AVL test;
    test.add(3);
    test.add(5);
    test.add(23);
    cout<<test.get_top()->value<<endl;
    
    
    return 0;
}







//
//int main(int ac, char* av[])
//{
//    testing::InitGoogleTest(&ac, av);
//    RUN_ALL_TESTS();
//    system("pause");
//    return 0;
//}
