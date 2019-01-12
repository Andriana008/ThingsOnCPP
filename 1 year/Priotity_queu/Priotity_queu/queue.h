#pragma once
#include<iostream>
using namespace std;


class Queue
{
private:
    char* array;
    size_t size;
    size_t in_index;
    size_t out_index;
public:
    void init_memory(size_t _size)
    {
        size = _size;
        array = new char[size];
        in_index = 0;
        out_index = 0;
    }
    Queue()
    {
        init_memory(13);
    }
    
    Queue(size_t size)
    {
        init_memory(size);
    }
    
    ~Queue()
    {
        delete[]array;
    }
    size_t get_quantity()
    {
        return (in_index + size - out_index) % size;
    }
    void add(char element)
    {
        if (get_quantity() + 1 == size)
        {
            resize(size + 10);
        }
        array[in_index] = element;
        in_index = (in_index + 1) % size;
    }
    void resize(size_t new_size)
    {
        if (new_size < 10)
        {
            new_size = 10;
        }
        size_t quantity = get_quantity();
        if (quantity >= new_size)
        {
            throw "size is too small";
        }
        char* new_arr = new char[new_size];
        
        for (int i = 0;i < quantity;i++)
        {
            size_t old_in;
            old_in = (out_index + i) % size;
            new_arr[i] = array[old_in];
        }
        out_index = 0;
        in_index = quantity;
        delete[]array;
        array = new_arr;
        size = new_size;
    }
    
    int remove()
    {
        size_t quantity = get_quantity();
        if (is_empty() == true)
        {
            throw "no elements to remove";
        }
        if (quantity * 3 < size)
        {
            resize(size / 2);
        }
        int removed;
        removed = array[out_index];
        out_index = (out_index + 1) % size;
        return removed;
    }
    
    bool is_empty()
    {
        return get_quantity() == 0 ;
    }
};

class Priority_queue
{
private:
    static const int n = 13;
    Queue que[n];
    int priorities[n];
public:
    Priority_queue()
    {
        for (int i = 0;i < n;i++)
        {
            priorities[i] = i;
        }
    }
    
    void add(int element, int priority)
    {
        que[priority].add(element);
    }
    
    int remove()
    {
        int removed = 0;
        for (int i = n - 1;i >= 0;i--)// delete from end
        {
            if (que[i].is_empty() != true)
            {
                removed = que[i].remove();
                break;
            }
        }
        return removed;
    }
    
    
};
