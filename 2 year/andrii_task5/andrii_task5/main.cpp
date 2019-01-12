/*12. Задані натуральне число п s1...sn, символи . Визначити число входжень в послідовність груп букв:
1-abc;
2-aba.*/

#include<iostream>
#include<fstream>
#include<iterator>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int countSubstr(const string& expression, const function<bool(string)>& predicate);

#include"DTO.h"

int countSubstr(const string& expression, const function<bool(string)>& predicate)
{
    int result;
    result = 0;
    vector<string> container;
    for (auto it = expression.begin(); it != expression.end() - 2; it++)
    {
        container.push_back(string(it, it + 3));
        result += count_if(container.begin(), container.end(), predicate);
        container.pop_back();
    }
    
    return result;
}

int main()
{
    try
    {
        string expresison = DTO::input();
        DTO::print(expresison);
    }
    catch (const ifstream::failure& e)
    {
        cout << "Exception opening/reading file \n" << e.what() << "\n";
    }
    catch (const invalid_argument& e)
    {
        cout << "incorrect data : " << e.what() << "\n";
    }
    catch (const exception& e)
    {
        cout << e.what();
    }
    system("pause");
    return 0;
}

