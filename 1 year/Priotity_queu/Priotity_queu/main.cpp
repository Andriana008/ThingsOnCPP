#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Priority_queue q;
    q.add(2, 3);
    q.add(4, 3);
    q.add(5, 2);
    q.add(7, 7);
    q.add(1, 8);
    q.remove();
    q.remove();
    q.remove();
    q.remove();
    q.remove();
  //  cout<<q[i].is_empty;
    
    
    return 0;
//    int main(int ac, char* av[])
//    {
//        testing::InitGoogleTest(&ac, av);
//        return RUN_ALL_TESTS();
//    }

}
