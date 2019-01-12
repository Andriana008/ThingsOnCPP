//// в файлі дійсні числа /знайти max число /обробити винятки
//
//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//int main()
//{
//    const int n=10;
//    double max;
//    double numbers[n];
//    ifstream file("/Users/Andriana/Desktop/dz_programming/fstream/fstream/cppstudio.txt");
//    
//    if(!file.is_open())
//    {
//        throw "file can't be opened";
//    }
//    else
//    {
//        for(int i=0;i<n;i++)
//        {
//            file>>numbers[i];
//        }
//        
//        max=numbers[0];
//       
//        for(int i=0;i<n;i++)
//        {
//             if(max<numbers[i])
//             {
//                 max=numbers[i];
//             }
//        }
//        
//        for(int i=0;i<n;i++)
//        {
//            cout<<numbers[i]<<" ";
//        }
//        
//        cout<<max;
//    
//    }
//    return 0;
//}
