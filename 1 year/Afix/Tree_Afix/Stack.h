#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Stack
{
    struct Node
    {
        T input;
        Node* pointer;
        Node(T _input = 0, Node* _pointer = nullptr) :
        input(_input),
        pointer(_pointer)
        {
        }
    };
private:
    Node*  head;
public:
    Stack() :
    head(nullptr)
    {
    }
    
    ~Stack()
    {
        while (!empty())
        {
            pop();
        }
    }
    
    void  push(T element)
    {
        head = new Node(element, head);
    }
    
    T top()
    {
            return head->input;
    }
    
    T pop()
    {
        if (head != nullptr)
        {
            Node* point = head;
            head = head->pointer;
            T result = point->input;
            delete point;
            return result;
        }
        else
        {
            throw "List is Empty!!!";
        }
    }
    
    void print()
    {
        Node* tTop = head;
        while (tTop != nullptr)
        {
            cout << tTop->input << " ";
            tTop = tTop->pointer;
        }
    }
    
    bool empty() const
    {
        return (head == nullptr);
    }
};




