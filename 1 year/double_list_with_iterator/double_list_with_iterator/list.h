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

class LinkedList
{
private:
    
    class LinkedListIterator
{
    public:
    friend class LinkedList;
   
    Node* curr;

    LinkedListIterator(Node* p) : curr(p) {};
    LinkedListIterator(const LinkedListIterator& other) : curr(other.curr) {};
    LinkedListIterator() :curr(0) {}
    LinkedListIterator(const LinkedList & l) :curr(l.head) {};
    
    void past_element()
    {
        ++curr;
    }
    
    char & operator*()
    {
        return curr->value;
    }
    
    LinkedListIterator& operator=(LinkedListIterator other)
    {
        curr=other.curr;
        return *this;
    }

    LinkedListIterator& operator++(int i)
    {
        if (curr->next)
        {
            curr = curr->next;
        }
        else
        {
            ++curr;
        }
        return *this;
    }
    
    LinkedListIterator& operator--(int i)
    {
        if (curr->prev)
        {
            curr = curr->prev;
        }
        else
        {
            --curr;
        }
        return *this;
    }
    
    bool operator==(LinkedListIterator t)
    {
        return  curr == t.curr;
    }
    
    bool operator!=(LinkedListIterator t)
    {
        return   curr != t.curr ;
    }
    
    LinkedListIterator operator+(int i)
    {
        LinkedListIterator iter = *this;
        while (i-- > 0 && iter.curr)
        {
            iter++;
        }
        return iter;
    }
};
public:
    typedef LinkedListIterator iterator;

    iterator begin()
    {
        iterator i(*this);
        return i;
    }
    
    iterator end()
    {
        iterator it(*this);
        if (empty())
        {
            return it;
        }
        
        Node* tmp = head;
        while (tmp!=NULL)
        {
            if (!tmp->next)
            {
                it.past_element();
            }
            else
            {
                it++;
            }
            tmp = tmp->next;
        }
        
        return it;
    }
private:
    int size;
    Node* head;
    Node* tail;
public:
      
    LinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }
    LinkedList(LinkedList& other)
    {
        size = other.size;
        head = other.head;
        tail = other.tail;
    }
    
    LinkedList& operator=(const LinkedList & x)
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
    bool empty() const
    {
        return !head;
    }
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
   
    void delete_end()
    {
        Node *temp;
        Node *current=tail;
        current=head;
        temp=head->next;
        delete current;
        head=temp;
        temp->prev=NULL;
    }
    
    void remove_list()
    {
        while(head!=tail)
        {
        Node *temp;
        Node *current=tail;
        current=head;
        temp=head->next;
        delete current;
        head=temp;
        temp->prev=NULL;
        }
    }

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
    
    char find_i(char d)
    {
        if(!head)// якщо зайде в нульовий
        {
            return '0';
        }
        iterator it=begin();
        iterator ite=end();
        while(it!=ite)
        {
            if(*it==d)
            {
                return *it;
            }
            it++;
        }
        return '0';
    }
    
   void remove(iterator& removeIter)
    {
        Node *last = head;
        iterator i = begin();
        
        while (i != removeIter)
        {
            last = i.curr;
            i++;
        }
        
        if (i != end())
        {
            last->next = i.curr->next;
            size--;
            delete i.curr;
        }
    }

    void print_i()
        {
            iterator it=begin();
            iterator ite=end();
            while(it!=ite)
            {
               cout<<*it<<" ";
               it++;
            }
            cout<<endl;
        }
    
    const int get_size()
    {
        return size;
    }
    
  };

