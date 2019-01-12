/*29.  (deque)В текстовому файлі знаходяться дані про витрати матеріалів бригад деякої будівельної фірми. Це номер бригади, дані про бригадира, список витрачених матеріалів з зазначенням дати, назви матеріалу, об’єму, вартості. Дані у файлі можуть повторюватися (для однієї бригади – декілька записів
 ----зчитати дані з файлу у контейнер і  відобразити їх на екрані (і записати у відповідні файли) у алфавітному порядку бригадирів. При цьому декілька даних про витрати для кожної бригади об’єднуються в одну
 ----За заданим числом – номером бригади, видрукувати по датах (відсортованих) витрати матеріалів і обчислити загальну суму витрат. відобразити це у файлі
 */

#include<iostream>
#include<deque>
#include<string>
#include<fstream>

using namespace std;

class Material
{
public:
    string name;
    double volume;
    int price;
    string data;
public:
    Material() :name(""), volume(0), price(0), data(" ") {};
    Material(string m, double v, int p, string d) :name(m), volume(v), price(p), data(d) {};
    void input_m(istream& file)
    {
        file >> name;
        file >> volume;
        file >> price;
        file >> data;
    }
    
    int get_price()
    {
        return price;
    }
    string get_name()
    {
        return name;
    }
    double get_volume()
    {
        return volume;
    }
    string get_data()
    {
        return data;
    }
    void output_m()
    {
        cout << "Name:" << name << endl;
        cout << "volume:" << volume << endl;
        cout << "price:" << price << endl;
        cout << "data:" << data << endl;
    }
    void output_m(ostream& file)
    {
        file << "Name:" << name << endl;
        file << "volume:" << volume << endl;
        file << "price:" << price << endl;
        file << "data:" << data << endl;
    }
    
};

class Brugada
{
private:
    int number;
    string brugader_name;
    int size;
    deque<Material> mat;
public:
    int get_number()
    {
        return number;
    }
    int get_size()
    {
        return size;
    }
    string get_brugader_name()
    {
        return brugader_name;
    }
    deque<Material>get_materials()
    {
        return mat;
    }
    void input(istream& file)
    {
        file >> number;
        file >> brugader_name;
        file >> size;
        if (!size)
        {
            throw invalid_argument("error in file \n");
        }
        for (int i = 0; i<size; i++)
        {
            Material m;
            m.input_m(file);
            mat.push_back(m);
        }
    }
    
    void output()
    {
        cout << "number:" << number << endl;
        cout << "brugader_name:" << brugader_name << endl;
        cout << "number of materials:" << size << endl;
        for (deque<Material>::iterator it = mat.begin(); it != mat.end(); it++)
        {
            cout << "Name:" << it->get_name() << endl;;
            cout << "volume:" << it->get_volume() << endl;;
            cout << "price:" << it->get_price() << endl;;
            cout << "data:" << it->get_data() << endl;;
        }
        
    }
    void output(ostream& file)
    {
        file << "number:" << number << endl;
        file << "brugader_name:" << brugader_name << endl;
        file << "number of materials:" << size << endl;
        for (deque<Material>::iterator it = mat.begin(); it != mat.end(); it++)
        {
            file << "Name:" << it->get_name() << endl;;
            file << "volume:" << it->get_volume() << endl;;
            file << "price:" << it->get_price() << endl;;
            file << "data:" << it->get_data() << endl;
        }
        
    }
    
};












