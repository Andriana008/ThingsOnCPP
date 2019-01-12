//1. Створити клас для двозв’язного списку, що містить дані типу char.
//Визначити клас Ітератор для пересування по списку.
//2. Використовуючи список розв’язати поставлену задачу.
//28. Задані: натуральне число n, символи s1...s(n).
//Визначити число входжень в послідовність s1...s(n) груп букв abc;

#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char value;
    Node *prev;
    Node *next;
    Node():value(' '),prev(NULL),next(NULL){};
    Node(char v, Node *p,Node *n):value(v),prev(p),next(n){};
};

class List
{
private:
    Node * tail,*head;
    int size;
public:
    List():tail(NULL),head(NULL),size(0){};
    List(const List&x)
    {
        tail=x.tail;
        head=x.head;
        size=x.size;
    }
    //
    ~List()
    {
        while (head!=NULL)
        {
            tail=head->next;
            delete head;
            head=tail;
        }
    }
    //
    void remove_list()
    {
        Node* temp = this->head;
        while (temp != NULL)
        {
            Node* del = temp;
            temp = temp->next;
            delete del;
        }
        this->head = NULL;
        this->tail = NULL;
    }
    //
    List& operator=(const List & x)
    {
        if(this!=&x)
        {
            this->remove_list();
            Node *temp=x.head;
            while (temp != NULL)
            {
                this->add_last(temp->value);
                temp = temp->next;
            }
        }
        return *this;
    }
    //
    List& operator+(const List &list)
    {
        Node* temp = list.head;
        while (temp != NULL)
        {
            add_last(temp->value);
            temp = temp->next;
        }
        return *this;
    }
    //
    List& operator+(const char el)
    {
        add_last(el);
        return *this;
    }
    //
    int get_size()
    {
        return size;
    }
    int number_of_abc(char a,char b,char c)
    {
        int k=0;
        Node * temp=head;
        while(temp!=NULL)
        {
            if((temp->value==a)&&(temp->next->value==b)&&(temp->next->next->value==c))
            {
                k++;
            }
            temp=temp->next;
        }
        return k;
        
    }
//    void add_first(char val)
//    {
//        Node *node =new Node;
//        node->value=val;
//        if(head==NULL)
//        {
//            head=node;
//            tail=node;
//        }
//        else
//        {
//            head->prev=node;
//        }
//    
//    }
    //
    void add_last(char val)
    {
        Node *node =new Node;
        node->value=val;
        if(head==NULL)
        {
            head=node;
            tail=node;
        }
        else
        {
            tail->next=node;
            tail=node;
        }

    }
    //
    Node* remove(Node *node)
    {
        if(!node)
        {
            node=head;
        }
        Node* temp=head;
        if(temp==node)
        {
            if (head->next)
            {
                head=head->next;
            }
            else
            {
                head=0;
                node->next=0;
                return node;
            }
        }
        Node* prev=temp;
        temp=temp->next;
        while ( temp )
        {
            if (temp==node)
            {
                prev->next=temp->next;
                node->next=0;
                return node;
            }	
            prev=temp;
            temp=temp->next;
        }
        return 0;
    }
    //
    void remove(char val)
    {
        Node *temp=tail;
        Node *current=find(val);
        current=tail;
        temp=tail->next;
        delete current;
        head=temp;
        temp->next=NULL;
    }
    
    //
//
    Node* find(char a)
    {
        Node * temp=head;
        while(temp!=NULL)
        {
            if(temp->value==a)
            {
                return temp;
            }
            temp=temp->next;
        }
        return 0;

    }
    //
    bool empty()
    {
        return head!=NULL;
    }
    //
    void print()
    {
        Node * node=head;
        while(node !=NULL)
        {
            cout<<node->value<<" ";
            node=node->next;
        }
        cout<<endl;
    }
    //
    void input()
    {
        int size;
        cout<<"enter size of list"<<endl;
        cin>>size;
        char el;
        for(int i=0;i<size;i++)
        {
            cout<<"enter element"<<endl;
            cin>>el;
            add_last(el);
        }
    }
};
