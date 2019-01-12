#pragma once

class DTO
{
public:
    
    static string input()
    {
        string fileName("/Users/Andriana/Desktop/dz_programming/2 year/andrii_task5/andrii_task5/data.txt");
        int elQuantity;
        
        ifstream ifs;
        ifs.open(fileName);
        if (ifs.fail())
        {
            throw ifstream::failure(fileName);
        }
        
        ifs >> elQuantity;
        istream_iterator<char> isIterator(ifs);
        string sequence(isIterator, istream_iterator<char>());
        
        if (elQuantity != sequence.length())
        {
            throw invalid_argument("check input data : size must be the same as number of elements in the sequence ..\n ");
        }
        
        return sequence;
    }
    
    static void print(string expression)
    {
        ofstream ofs;
        ofs.open("/Users/Andriana/Desktop/dz_programming/2 year/andrii_task5/andrii_task5/result.txt", ios_base::out | ios_base::trunc);
        if (ofs.fail())
        {
            throw ofstream::failure("can not write to file ..\n ");
        }
        
        ostream_iterator<int> osIterator(ofs, "  ");
        
        function<bool(string)>  compareWithAbc = [&](string str) { return str == "abc"; };
        function<bool(string)>  compareWithAba = [&](string str) { return str == "aba"; };
        
        osIterator = countSubstr(expression, compareWithAbc);
        ofs << "quantity of  abc substrings in " << expression<<";\n";
        osIterator = countSubstr(expression, compareWithAba);
        ofs << "quantity of  aba substrings in " << expression << ";\n";
    }
};
