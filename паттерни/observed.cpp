#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>

class IObserver
{
public:
	virtual void Upadate() = 0;
};

class IObservable
{
public:
	virtual void addObserver(IObserver* o) = 0;
	virtual void removeObserver(IObserver* o) = 0;
	virtual void Notify() = 0;
};

class Birga : public IObservable
{
	vector<IObserver*> v;
public:
	void addObserver(IObserver* o)
	{
		v.push_back(0);
	}
	void removeObserver(IObserver* o)
	{
		remove(v.begin(), v.end(), o);
	}

	void Notify()
	{
		for_each(v.begin(), v.end(), [&](IObserver* o) { o->Upadate(); });
	}
};


class Broker : public IObserver
{
	IObservable* b;
public:
	Broker(IObservable* bi)
	{
		b = bi;
		b->addObserver(this);
	}
};

class Bank : IObserver
{
public:
};


int main()
{

	system("pause");
	return 0;
}