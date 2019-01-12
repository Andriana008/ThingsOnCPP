#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
#include <iterator>
#include <sstream>
#include <exception>
#include <set>

using namespace std;


map <char, list<int>> input(ifstream &file)
{
        map <char, list<int>> text;
        list<int> positions;
        //TODO: remove else.
        ////for example:
        if (!file.is_open())
        {
            throw exception();
        }
        //DONE
        else
        {
            //TODO: rename
            char name;
            string data;
            //DONE
            
            //TODO:move to while
            //DONE
            while (!file.eof())
            {
                while (file >> name)
                {
                    int number;
                    // TODO: move to separate method, which parse line
                    getline(file, data);
                    istringstream iss(data);
                    positions.clear();
                    while (iss >> number)
                    {
                        positions.push_back(number);
                    }
                    text.insert(make_pair(name, positions));
                }
                
            }
        }
    
    //TODO: move to main()
    //DONE
    return text;
}

void output(map <char, list<int>> text)
{
    list<int> positions;
    for (auto it = text.begin(); it != text.end(); ++it)
    {
        cout << (*it).first << " ";
        positions = it->second;
        copy(positions.begin(), positions.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    cout << endl;
}

//my option of sorting without using STL
/*
map <char, list<int>> task1_sort_out_in_file(ofstream&file, map <char, list<int>> text)
{
    auto first = text.begin(), last = text.end();
prev:
    auto it_b = first;
    char key;
    list<int>pos;
    for (auto it_a = it_b++; it_b != last; *it_a++, *it_b++)
    {
        if ((it_a->second).size() < (it_b->second).size())
        {
            key = it_a->first;
            //cast to char
            *(char*)&it_a->first = it_b->first;
            *(char*)&it_b->first = key;
            pos = it_a->second;
            it_a->second = it_b->second;
            it_b->second = pos;
            goto prev;
        }
    }
    return text;
    // TODO: move to separate method
    //DONE
    
}

void output_task1(map <char, list<int>> text)
{
    //ofstream file("task1.txt");
    ofstream task1("/Users/Andriana/Desktop/dz_programming/2 year/task 4/task 4/task1.txt");
    text=task1_sort_out_in_file(task1,text);
    list<int> positions;
    for (auto it = text.begin(); it != text.end(); ++it)
    {
        cout << (*it).first << " ";
        positions = it->second;
        cout << positions.size();
        cout << endl;
    }
    cout << endl;
}

void output_task1_in_file(ofstream&file,map <char, list<int>> text)
{
    //ofstream file("task1.txt");
    ofstream task1("/Users/Andriana/Desktop/dz_programming/2 year/task 4/task 4/task1.txt");
    text=task1_sort_out_in_file(task1,text);
    list<int> positions;
    for (auto it = text.begin(); it != text.end(); ++it)
    {
        file << (*it).first << " ";
        positions = it->second;
        file << positions.size();
        file << endl;
    }
    file << endl;
}
*/


//function to the another way of sort
struct cmp
 {
     bool operator()(const pair<char, int> pair1, const pair<char, int> pair2)
     {
     return pair1.second > pair2.second;
     }
 };

//ToDO: according to task you should use STL. So second implementation is better
//another way to sort
//DONE
multiset<pair<char, int>, cmp>  task1_sort_map(map<char, list<int>> text)
{
    multiset<pair<char, int>, cmp> sorted_text;
    for (auto it = text.begin(); it != text.end(); it++)
    {
        sorted_text.insert(pair<char, int>(it->first, it->second.size()));
    }
    
    return sorted_text;
}

void another_output_task1_in_file(ofstream&file,multiset<pair<char, int>, cmp> text)
{
    ofstream task1("/Users/Andriana/Desktop/dz_programming/2 year/task 4/task 4/task1.txt");
    for (auto it = text.begin(); it != text.end(); it++)
    {
        file << it->first << " " << it->second << endl;;
    }
    file.close();
}
//DONE 

void task2_text_in_file(ofstream&file, map <char, list<int>> text)
{
    list<int> positions;
    for (int i = 0; i<=text.size()*2; i++)
    {
        for (auto it = text.begin(); it != text.end(); ++it)
        {
            positions = it->second;
            bool is_found = (find(positions.begin(), positions.end(), i) != positions.end());
            if (is_found)
            {
                cout << (*it).first;
                file << (*it).first;
            }
        }
    }
    cout << endl;
    file << endl;
}

