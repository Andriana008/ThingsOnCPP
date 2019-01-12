#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<iterator>
#include<map>
#include<set>
using namespace std;


typedef pair<int, int> intP;
typedef pair<string, intP> item;

struct Product
{
    string code;
    int quantity;
    string deliverityType;
    string address;
    string phone;
    int price;
    
    Product() : code(""), quantity(0), price(), deliverityType(""), address(""), phone("") {}
    
    Product(string code, int quantity, string deliverityType, string address, string phone) :
    code(code), quantity(quantity), deliverityType(deliverityType), address(address), phone(phone)
    {}
    
    friend ifstream& operator >>(ifstream& ifs, Product& p)
    {
        ifs >> p.quantity;
        ifs >> p.code;
        ifs >> p.deliverityType;
        ifs >> p.phone;
        ifs >> p.address;
        return ifs;
    }
    
    friend ostream& operator <<(ostream& ofs, Product& p)
    {
        ofs << p.quantity << "\n";
        ofs << p.code << "\n";
        ofs << p.deliverityType << "\n";
        ofs << p.phone << "\n";
        ofs << p.address << "\n";
        ofs << "_____________\n";
        return ofs;
    }
    
    bool isCompleted()
    {
        return code != "" && deliverityType != "" && price != 0 && quantity != 0 && phone != "" && address != "";
    }
    
};


class Deliverity
{
public:
    void deliver(Product& product, string clientAddress)
    {
        switch (product.deliverityType.length())
        {
            case 10:
            {
                product.deliverityType += " by car";
            }
                break;
            case 6:
            {
                product.deliverityType += " by man";
            }
                break;
            case 12:
            {
                product.deliverityType += " by helicopter";
            }
                break;
            default:
                break;
        }
        product.address = clientAddress;
    }
    
    void deliver(Product& product, string ph, string a)
    {
        ofstream ofs;
        ofs.open("res.txt", std::ios::app);
        
        product.address = a;
        product.phone = ph;
        ofs << "completed orders : \n";
        if (product.isCompleted())
        {
            ofs << product;
        }
        else
        {
            ofs << "denied , try another filters \n";
        }
        ofs << "_________________\n";
    }
    
};



class Storage
{
private:
    
    multimap<string, pair<int, int>> availableP;
    
    void GETPRODUCTS()
    {
        ifstream ifs("data.txt");
        if (!ifs.is_open())
        {
            ifstream::failure("");
        }
        /*istream_iterator<string> it(ifs);
         istream_iterator<string> eof;*/
        string code;
        int q, p;
        while (!ifs.eof())
        {
            ifs >> p;
            ifs >> q;
            ifs >> code;
            availableP.insert(item(code, pair<int, int>(q, p)));
        }
        
        ifs.close();
    }
public:
    Storage()
    {
        if (availableP.size() == 0) GETPRODUCTS();
    }
    
    Product getProduct(int p, int q, string c)
    {
        
        auto it = find_if(availableP.begin(), availableP.end(), [&](item el)
                          {
                              return el.first == c && el.second.first == q && el.second.second == p;
                          }
                          );
        Product prod;
        prod.price = it->second.second;
        prod.quantity = it->second.first;
        prod.code = it->first;
        availableP.erase(it);
        return prod;
    }
    
};

class Boxing
{
public:
    void packUp(Product& product)
    {
        switch (atoi(product.code.c_str()) % 3)
        {
            case 0:
            {
                product.deliverityType += "in package";
            }
                break;
            case 1:
            {
                product.deliverityType += "in box";
            }
                break;
            case 2:
            {
                product.deliverityType += "in glass jar";
            }
                break;
            default:
                
                break;
        }
        
    }
};

class Payment
{
public:
    static    int getPrice(Product& product)
    {
        int price = 0;
        if (product.isCompleted())
        {
            price += product.price + 10 + 20;
        }
        return price;
    }
};

class Information
{
public:
    void InformClient(Product product)
    {
        string specialCode = product.code;
        get(specialCode);
        ofstream ofs;
        
        ofs.open("client.txt", std::ios::app);
        
        ofs << "order : \n";
        if (product.isCompleted())
        {
            ofs << Payment::getPrice(product) << "\n";
            ofs << specialCode << "\n";
            ofs << product.code << "\n";
        }
        else
        {
            ofs << "denied\n";
        }
        ofs << "_________________\n";
    }
private:
    void get(string& specialCode)
    {
        for (int i = 0; i < specialCode.length(); ++i)
        {
            specialCode[i] = i + 100;
        }
    }
    
};



class OnlineShop // facade
{
private:
    Storage s;
    Payment p;
    Boxing b;
    Deliverity d;
    Information i;
public:
    Product CallOnlineShop(string code, int price, int quantity, string ph, string a)
    {
        Product product;
        product = s.getProduct(price, quantity, code);
        b.packUp(product);
        d.deliver(product, ph, a);
        i.InformClient(product);
        return product;
    }
};



struct ClientDesire
{
    int price;
    int quantity;
    string code;
    string address;
    string phone;
    ClientDesire(int p, int q, string c, string ph, string a)
    {
        price = p;
        quantity = q;
        code = c;
        phone = ph;
        address = a;
    }
};


vector<Product> v;
vector<ClientDesire*> clDesire;

void taskB()
{
    ifstream ifs("orders.txt");
    string code;
    int price;
    int quantity;
    string phone;
    string address;
    while (!ifs.eof())
    {
        ifs >> price;
        ifs >> quantity;
        ifs >> code;
        ifs >> phone;
        ifs >> address;
        clDesire.push_back(new ClientDesire(price, quantity, code, phone, address));
    }
    
    OnlineShop* shop = new OnlineShop();
    
    for(auto var=clDesire.begin();var!=clDesire.end();var++)
    {
        v.push_back(shop->CallOnlineShop((*var)->code, (*var)->price, (*var)->quantity, (*var)->phone, (*var)->address));
    }
    
}

struct Compare
{
    bool operator () (const Product l ,const Product r) { return l.code < r.code; }
};

void taskC()
{
    sort(v.begin(), v.end(), [&](Product& p1, Product& p2)
         {return p1.code < p2.code; });
    cout << "top orders!!! \n";
    set < Product,Compare > sp;
    for_each(v.begin(), v.end(), [&](Product& p) {sp.insert(p); });
    for_each(sp.begin(), sp.end(), [&](Product p) {cout << p; });
}

int main()
{
    taskB();
    taskC();
    system("pause");
    return 0;
}




