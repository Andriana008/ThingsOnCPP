#include<iostream>
#include<list>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class House
{
private:
	string type;
	double square;
	int x;
	int y;
	int finalPrice;
public:
	House() :type(""), square(0.0), x(0), y(0), finalPrice(0) {}
	House(string t, double s, int x, int y, int f) :type(t), square(s), x(x), y(y), finalPrice(f) {}
	int getFinalPrice()
	{
		return finalPrice;
	}
	friend istream& operator >>(istream& is, House& h)
	{
		is >> h.type;
		is >> h.square;
		is >> h.x;
		is >> h.y;
		return is;
	}

	friend ostream& operator <<(ostream& is, House& h)
	{
		is << h.type << "\n";
		is << h.square << "\n";
		is << h.x << "\n";
		is << h.y << "\n";
		is << "___________\n";
		return is;
	}

	bool isEqaul(string t, double s, int x, int y)
	{
		return type == type && square == s && this->x == x && this->y == y;
	}

};

class IBuild
{
public:
	virtual House* build(string type, double square, int x, int y) = 0;
};

class IRent
{
public:
	virtual House* rent(string type, double square, int x, int y) = 0;
};


class FirmB : public IBuild
{
private:
	const  int MINPRICE = 100;
	vector<House*> DATAPULL;

	void INITIALIZE()
	{
		ifstream ifs("data.txt");
		House* house = new House();
		while (!ifs.eof())
		{
			ifs >> *house;
			DATAPULL.push_back(house);
			house = new House();
		}
		delete house;
		ifs.close();
	}

	bool isAvailable(string type, double square, int x, int y)
	{
		bool result = false;
		auto it = find_if(DATAPULL.begin(), DATAPULL.end(), [&](House* h) {return h->isEqaul(type, square, x, y); });
		if (it != DATAPULL.end())
		{
			result = true;
		}
		return result;
	}

public:
	FirmB()
	{
		INITIALIZE();
	}

	House* build(string type, double square, int x, int y)
	{
		House* house = nullptr;
		if (y > MINPRICE && isAvailable(type, square, x, y))
		{
			house = new House(type, square, x, y, (MINPRICE + y) / 2);
		}

		return house;
	}
};

class FirmA : public IRent
{
private:
	int income;
	FirmB* b;
public:
	FirmA() :income(0) { b = new FirmB(); }
	House* rent(string type, double square, int x, int y)
	{
		int margin = 0;
		House* house = b->build(type, square, x, y);
		if (house != nullptr)
		{
			margin = y - house->getFinalPrice();
		}
		income += margin;
		return house;
	}

	int getIncome()
	{
		return income;
	}

};


class Adapter : public IBuild
{
	FirmA* firmA;
public:
	Adapter(FirmA* a)
	{
		firmA = a;
	}

	House* build(string type, double square, int x, int y)
	{
		return	firmA->rent(type, square, x, y);
	}
	int getIncome()
	{
		return firmA->getIncome();
	}
};


class Client
{
private:
public:
	House* getHouse(IBuild* b, string type, double square, int x, int y)
	{
		return b->build(type, square, x, y);
	}
};

struct Params
{
	string type = "";
	double square = 0;
	int x = 0;
	int y = 0;
	Params()
	{
		type = "";
		square = 0;
		x = 0;
		y = 0;
	}

	Params(string t, double s, int x1, int y1)
	{
		type = type;
		square = s;
		x = x1;
		y = y1;
	}
	friend istream& operator >>(istream& is, Params& p)
	{
		is >> p.type;
		is >> p.square;
		is >> p.x;
		is >> p.y;
		return is;
	}
};

vector<House*> completed;

void taskB()
{
	vector<Params*> v;
	ifstream ifs("clientOrders.txt");
	Params* tmp = new Params();
	while (!ifs.eof())
	{
		ifs >> *tmp;
		v.push_back(tmp);
		tmp = new Params();
	}
	delete tmp;
	Client* cl = new Client();
	IBuild* adapt = new Adapter(new FirmA());

	House* h;
	for (auto var : v)
	{
		h = cl->getHouse(adapt, var->type, var->square, var->x, var->y);
		if (h != nullptr)
		{
			completed.push_back(h);
		}
	}

	ofstream ofs("res.txt", ios_base::in | ios_base::trunc);

	for each (auto var in completed)
	{
		ofs << *var;
	}

	ofs << "\n\n income of rirm A  = " << dynamic_cast<Adapter*>(adapt)->getIncome();

}



int main()
{
	taskB();

	system("pause");
	return 0;
}