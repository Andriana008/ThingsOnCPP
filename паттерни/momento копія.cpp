#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;


class ProductMemento
{
private:
	string name;
	int price;
public:
	ProductMemento(string n, int p) : name(n), price(p) {}
	string getNmae()
	{
		return name;
	}
	int getPrice()
	{
		return price;
	}
};

class Product
{
private:
	string name;
	int price;
public:
	Product(): name(""), price(0){}
	Product(string n , int p): name(n), price(p){}

	ProductMemento* save()
	{
		cout << "saved !\n";
		return new ProductMemento(name , price);
	}
	void restore(ProductMemento* p)
	{
		this->name = p->getNmae();
		price = p->getPrice();
		cout << "restored\n";
	}
};

class History : public stack<ProductMemento*>
{};

int main()
{
	History h;
	Product* p = new Product("and" , 122);
	h.push(p->save());
	p = new Product("ivan", 12234);
	p->restore(h.top());
	system("pause");
	return 0;
}