#include<iostream>
using namespace std;
 
class List
{
    class List_iterator//підклас класу ліст
    {
    public:
        Node *current;
 
        friend List;
 
        void past_element()
        {
            current++;
        }
   
     public:
         List_iterator():current(0){}
         List_iterator(const  List_iterator& i):current(i.current){}
         List_iterator(const List& l):current(l.head){}
 
         //operator = ще треба
         int& operator*()
         {
            return current->data;
         }
         void operator*(int d)
         {
             current->data=d;
         }
         Node* current()
         {
             return current;
         }
         List_iterator& operator++();
 
 
    }
 
    typedef List_iterator iterator;
 
 
public:
    iterator begin()
    {
        return iterator(*this);
    }
    iterator end();// write
 
    List iterator operator++()// в класі ліст підклас ітератор і в ньому оператор ++
    {
        if(current->next)
        {
            current=current->next;
        }
        else ++current;
        return *this;
    }
   
    Node* find(int d)
    {
        Node* List::find(int d)
        {
            if(!head)// якщо зайде в нульовий
            {
                return 0;
            }
            iterator itbegin();// вказує на початок списку
            iterator itemp(itbegin);//буде рухатися по ньому
        itemp++;
        while((itemp!=end())&&(*temp!=d))// *temp- розіменований темп
        {
            itbegin=itemp; itemp++;
            if(*itemp=d) return itbegin.current();
            else return 0;
        }
 
        }
    }
 
 
};
 
 
int main()
{
    List list;
    List::iterator i1;
   
    return 0;
}