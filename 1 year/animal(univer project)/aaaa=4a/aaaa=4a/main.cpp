#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Line
{
private: string line;
    string press_line()
    {
        string rez;
        char a = line[0];
        int k = 0;
        for (int i = 0; i < line.length(); i++)
        {
            if (a == line[i])
            {
                k++;
            }
            if (a != line[i + 1])
            {
                if (k == 1)
                {
                    rez += a;
                }
                else
                {
                    char d[] = { "        " };
                    _itoa_s(k, d, 10);
                    rez += a;
                    rez += '(';
                    rez += d;
                    rez += ')';
                }
                a = line[i + 1];
                k = 0;
            }
        }
        return rez;
    }
    string roz_press_line()
    {
        string rez="";
        char a;
        string z="";								// 0 1 2 3 4 5 6 7 8 9  10  11  12   13  14   15  16  17  18
        int q;										// a y ( 3 ) n d ( 4 )  r    (   1   2    )   i   (   8    )
        for (int i = 0; i < line.length(); i++)    // rez = ayyynd
        {											// i=6
            a = line[i];                           // j=8
            rez += a;								// z= 3
            if (line[i + 1] == '(')                // e= 1
            {										// q= 3
                int j = i+2;						// a= y
                i + 1;
                while (line[j] != ')')
                {
                    z += line[j];
                    j++;
                    i++;
                }
                q = stoi(z);
                for (int p = 0; p < q - 1; p++)
                {
                    rez += a;
                }
                i = i+2;
                z = "";
            }
        }
        return rez;
    }
public:
    Line()
    {
        line = "";
    }
    Line(string a)
    {
        line = a;
    }
    Line(Line &a)
    {
        line = a.line;
    }
    friend istream& operator >> (istream & in, Line &a)
    {
        in >> a.line;
        a.line = a.press_line();
        return in;
    }
    friend ostream& operator << (ostream & out, Line &a)
    {
        out << a.line << "\t\t---\t";
        out << a.roz_press_line() << endl;
        return out;
    }
    int get_press__amount()
    {
        return line.length();
    }
    int get_roz_press__amount()
    {
        return roz_press_line().length();
    }
};

int main()
{
    ifstream in("string.txt");
    int n;
    in >> n;
    Line* arr = new Line[n];	
    for (int i = 0; i < n; i++)
    {
        in >> arr[i];
    }	
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    double r_sum = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum+= arr[i].get_press__amount();
        r_sum += arr[i].get_roz_press__amount();
    }
    cout <<"We can economize "<< (100-(( sum* 100) /r_sum )) <<" %"<< endl;	
    system("pause");
    return 0;
}

