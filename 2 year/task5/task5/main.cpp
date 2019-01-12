/*29. Задані натуральне число п, символи s1-sn , серед яких є хоча б одна крапка. Перетворити послідовністьs1-sn ,  видаливши із неї всі коми, передуючі першій крапці, і замінивши знаком + всі цифри 3, які зустрічаються після першої крапки.
*/

#include<iostream>
#include<fstream>
#include<iterator>
#include<string>
#include<algorithm>
#include<functional>
#include<exception>

using namespace std;
//TODO:global constant instand of local one
//DONE
const char POINT='.';

string input()
{
    
    ifstream file("/Users/Andriana/Desktop/dz_programming/2 year/task5/task5/data.txt");
    //ifstream file("data.txt");
    
    if (!file.is_open())
    {
        throw ifstream::failure("can not open file , some problems");
    }
    
    
        int size;
        file >> size;
        
        string line;
        istream_iterator<char> iter(file);
        copy(iter, istream_iterator<char>(), back_inserter(line));
        
        if (size != line.length())
        {
            throw invalid_argument("check size");
        }
        
        copy(line.begin(), line.end(), ostream_iterator<char>(cout));
        cout<<endl;
        return line;
    
}

bool Is_comma(char symbol)
{
    return symbol == ',';
}

bool Is_number(char symbol)
{
    return symbol == '3';
}

//TODO:rename functions
//DONE
string replace_symbols_in(string& line)
{
    auto find_pos=find(line.begin(),line.end(),POINT);
    replace_if(find_pos, line.end(),Is_number , '+');
    return line;
}

string delete_symbols_in(string& line)
{
    auto find_pos=find(line.begin(),line.end(),POINT);
    line.erase(remove_if(line.begin(), find_pos, Is_comma),find_pos);
    return line;
}

//TODO: shorten the function
//DONE
void print(string& line)
{
    
    ofstream file("/Users/Andriana/Desktop/dz_programming/2 year/task5/task5/result.txt", ios_base::out);
    //ofstream file("result.txt");
    
    //TODO use standart exception
    //DONE
    if (!file.is_open())
    {
        throw ostream::failure("can not open file , some problems");
    }
    
    ostream_iterator<char> iter(file);
    
    replace_symbols_in(line);
    delete_symbols_in(line);
    
    copy(line.begin(),line.end(),iter);
    copy(line.begin(),line.end(),ostream_iterator<char>(cout));
    
}
               
int main()
{
    try
    {
        string line =input();
        print(line);
       
    }
    catch (invalid_argument& ex)
    {
        cout << ex.what() << endl;
    }
    catch (const exception& ex)
    {
        cout << ex.what() << endl;
    }
}
