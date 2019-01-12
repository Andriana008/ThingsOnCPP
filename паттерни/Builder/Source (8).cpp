#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//class Builder
//{
//protected:
//	ZooShop* zs;
//public:
//	Builder()
//	{
//		zs = new ZooShop();
//	}
//
//	void virtual addAnimal() = 0;
//	void virtual addFood() = 0;
//	void virtual addHouse() = 0;
//	ZooShop* getResult()
//	{
//		return zs;
//	}
//};
//
//class Manager
//{
//public:
//	ZooShop* createOeder(Builder* zooBuilder)
//	{
//		zooBuilder->addAnimal();
//		zooBuilder->addFood();
//		zooBuilder->addHouse();
//		return zooBuilder->getResult();
//	}
//};
//
//class Animal :public  Builder
//{
//
//public:
//	Animal()
//	{
//
//	}
//};
//
//class Food : public Builder
//{
//
//};
//
//class House : public Builder
//{
//
//};
//
//class ZooShop // manager
//{
//private:
//	Animal* animal;
//	Food* food;
//	House* house;
//public:
//
//
//};
//
class Animal
{
protected:
	int price;
public:
	Animal() : price(0) {}
	virtual string getType() = 0;
	int getPrice()
	{
		return price;
	}

	virtual void in(istream& is)
	{
		is >> price;
	}

	virtual void out(ostream& is)
	{
		is << price << "\n";
	}

	/*friend  ofstream& operator <<(ofstream& os, Animal* a)
	{
		os << a->price;
		return os;
	}
*/
};

class Hamster : public Animal
{
private:
	string furType;
public:
	Hamster() :Animal(), furType("") {}
	friend istream& operator >>(istream& is, Hamster* a)
	{
		is >> a->price;
		is >> a->furType;
		return is;
	}

	void in(istream& is)
	{
		Animal::in(is);
		is >> furType;
	}

	virtual void out(ostream& os)
	{
		Animal::out(os);
		os << furType << "\n";
	}

	/*friend ofstream& operator <<(ofstream& os, Hamster* a)
	{

		return os;
	}*/

	string getType()
	{
		return "ham";
	}
};

class Fish : public Animal
{
private:
	string waterType;
public:
	Fish() : Animal(), waterType("") {};
	friend istream& operator >>(istream& is, Fish* a)
	{

		is >> a->waterType;
		return is;
	}
	void in(istream& is)
	{
		Animal::in(is);
		is >> waterType;
	}
	/*friend ostream& operator <<(ostream& os, Fish* a)
	{
		os << a;
		os << a->waterType;
		return os;
	}*/
	virtual void out(ostream& os)
	{
		Animal::out(os);
		os << waterType<<"\n";
	}

	string getType()
	{
		return "fish";
	}
};

class Lizard : public Animal
{
private:
	string poisonType;
public:
	Lizard() :Animal(), poisonType("") {}
	friend istream& operator >>(istream& is, Lizard* a)
	{
		is >> a->price;
		is >> a->poisonType;
		return is;
	}
	/*friend ofstream& operator <<(ofstream& os, Lizard* a)
	{
		os << a;
		os << a->poisonType;
		return os;
	}*/

	virtual void out(ostream& os)
	{
		Animal::out(os);
		os << poisonType << "\n";
	}

	void in(istream& is)
	{
		Animal::in(is);
		is >> poisonType;
	}

	string getType()
	{
		return "liz";
	}
};

class House
{
private:
	int size;
	int pricePerMetr;
public:
	House() {};
	House(int s, int p) : size(s), pricePerMetr(p) {};
	int getSize()
	{
		return size;
	}
	int getPricePerMetr()
	{
		return pricePerMetr;
	}

	int getTotalPrice()
	{
		return size*pricePerMetr;
	}
	friend istream& operator >>(istream& is, House* a)
	{
		is >> a->size;
		is >> a->pricePerMetr;
		return is;
	}

	virtual void out(ostream& os)
	{
		os << size<<"\n";
		os << pricePerMetr<<"\n";
	}


	/*friend ofstream& operator <<(ofstream& os, House* a)
	{
		os << a->size;
		os << a->pricePerMetr;
		return os;
	}*/
};

class Food
{
private:
	string foodType;
	int price;
public:
	Food() {};
	Food(string s, int p) : foodType(s), price(p) {};
	string getFoodType()
	{
		return foodType;
	}
	int getPrice()
	{
		return price;
	}
	friend istream& operator >>(istream& is, Food* a)
	{
		is >> a->foodType;
		is >> a->price;
		return is;
	}


	virtual void out(ostream& os)
	{
		os << foodType << "\n";
		os << price << "\n";
	}
	/*friend ofstream& operator >>(ofstream& os, Food* a)
	{
		os << a->foodType;
		os << a->price;
		return os;
	}*/
};

class Order
{
public:
	int price = 0;
	House* house = new House();
	Food* food = new Food();
	Animal* animal = nullptr;
public:
	Order() {};
	Order(House* h, Food* f, Animal* a, int price) : house(h), food(f), animal(a), price(price) {};
	int getPrice()
	{
		return price;
	}
	friend istream& operator >>(istream& is, Order* o)
	{
		o->animal->in(is);
		is >> o->food;
		is >> o->house;
		return is;
	}
	friend ostream& operator <<(ostream& os, Order* o)
	{
		o->animal->out(os);
		o->food->out(os);
		o->house->out(os);
		os << o->price;
		os << "\n_______\n";
		return os;
	}
};

class ZooShop
{
private:
	vector<House*> houses;
	vector<Food*> food;
	vector<Animal*> animals;
	Order* order = nullptr;
public:
	//ZooShop()
	void check(House* h, Food* f, Animal* a)
	{
		order = nullptr;
		INITIALIZE();
		auto animalIt = find_if(animals.begin(), animals.end(), [&](Animal* an)
		{
			return an->getType() == a->getType() && an->getPrice() == an->getPrice();
		}
		);
		auto houseIt = find_if(houses.begin(), houses.end(), [&](House* ho)
		{
			return ho->getPricePerMetr() == h->getPricePerMetr() && ho->getSize() == h->getSize();
		}
		);
		auto foodIt = find_if(food.begin(), food.end(), [&](Food* fo)
		{
			return f->getFoodType() == fo->getFoodType();
		}
		);
		if (animalIt == animals.end() || foodIt == food.end(), houseIt == houses.end())
		{
			cout << "could not be found\n";
		}

		order = new Order(*houseIt, *foodIt, *animalIt, (*houseIt)->getTotalPrice() + (*animalIt)->getPrice());
	}

	Order* getResult()
	{
		return order;
	}
private:
	void getAvailableHouses()
	{
		ifstream ifs("2.txt");
		House* tmp = new House();
		while (!ifs.eof())
		{
			ifs >> tmp;
			houses.push_back(tmp);
		}
	}
	void getAvailableAnimals()
	{
		ifstream ifs("1.txt");
		Animal* tmp = nullptr;
		string type;
		while (!ifs.eof())
		{
			ifs >> type;
			if (type == "ham")
			{
				tmp = new Hamster();
			}
			else if (type == "fish")
			{
				tmp = new Fish();
			}
			else if (type == "liz")
			{
				tmp = new Lizard();
			}
			tmp->in(ifs);
			animals.push_back(tmp);
		}

	}
	void getAvailableFood()
	{
		ifstream ifs("3.txt");
		Food* tmp = new Food();
		while (!ifs.eof())
		{
			ifs >> tmp;
			food.push_back(tmp);
		}
	}

	void INITIALIZE()
	{
		getAvailableAnimals();
		getAvailableFood();
		getAvailableHouses();
	}
};

vector<Order*> completedOrders;

void taskB()
{
	ifstream ifs("ClientOrders.txt");
	Order* tmp = new Order();
	ZooShop zs;
	string type;
	while (!ifs.eof())
	{
		ifs >> type;
		if (type == "ham")
		{
			tmp->animal = new Hamster();
		}
		else if (type == "fish")
		{
			tmp->animal = new Fish();
		}
		else if (type == "liz")
		{
			tmp->animal = new Lizard();
		}
		ifs >> tmp;
		zs.check(tmp->house, tmp->food, tmp->animal);
		auto newOrder = zs.getResult();
		completedOrders.push_back(newOrder);
	}

	ofstream ofs("res.txt", ios_base::in | ios_base::trunc);

	for each (auto var in completedOrders)
	{
		ofs << var;

	}

}

void taskC()
{
	int sum = 0;
	for_each(completedOrders.begin(), completedOrders.end(), [&](Order* o) {if (o != nullptr) sum += o->getPrice(); });
	ofstream ofs("sum.txt", ios_base::in | ios_base::trunc);
	ofs << sum;
}

int main()
{
	taskB();
	taskC();
	system("pause");
	return 0;
}