//
//  main.cpp
//  dunamic_stack
//
//  Created by Андріана Щербак on 21.02.17.
//  Copyright © 2017 Андріана. All rights reserved.
//

#include <iostream>
using namespace std;
class stack
{
private:
    int * arr;
    int size=3;
    int count;
public:
    stack()
    {
        count = 0;
        arr=new int [size];
    }
    ~stack()
    {
        delete[] arr;
    }
    void push(int new_element)
    {
        arr[count] = new_element;
        count++;
        //arr[count - 1] = new_element;
        if(count==size)
        {
            int *new_arr=new int[size];
            for(int i=0;i<size;i++)
            {
                new_arr[i]=arr[i];
            }
            size*=3;
            arr=new int[size];
            for(int i=0;i<size;i++)
            {
                arr[i]=new_arr[i];
            }
            delete[] new_arr;
        }
    }
    bool is_empty()
    {
        return count == 0;
    }
    int pop()
    {
        count--;
        return arr[count];
    }
    
};
bool test_is_empty()
{
    bool test_result = true;
    stack st;
    test_result &= st.is_empty();
    st.push(1);
    test_result &= !st.is_empty();
    st.pop();
    test_result &= st.is_empty();
    return test_result;
}
bool test_push_pop()
{
    stack st;
    for (int i = 1; i <= 20; i++)
    {
        st.push(i);
    }
    bool test_result = true;
    test_result &= st.pop() == 20;
    return test_result; 
}
int main()
{ 
    cout <<"Stack is working good "<< test_is_empty() << test_push_pop() << endl;
}
