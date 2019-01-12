#include<iostream>
#include<set>
#include<fstream>
#include<string>
using namespace std;

//Pool is open from 8 until 19 , else - exception is thrown
//Days: 1-Monday, 2-Tuesday etc.

const int beginOfWork = 8;
const int endOfWork = 19;
const int firstDay = 1;
const int lastDay = 7;

#include"Visit.h"

string getDayByNumber(const int& dayNumber)
{
	switch (dayNumber)
	{
	case 1:
		return "Monday";
	case 2:
		return "Tuesday";
	case 3:
		return "Wednesday";
	case 4:
		return "Thursday";
	case 5:
		return "Friday";
	case 6:
		return "Saturday";
	case 7:
		return "Sunday";
	default:
		throw invalid_argument("bad data");
	}
}

void input(multiset<Visit>& visitsSet)
{
	ifstream file("data.txt");
	if (!file.is_open())
	{
		throw exception("Can't open file");
	}

	Visit visit;
	int countVisitors;

	while (!file.eof())
	{
		file >> visit;
		file >> countVisitors;

		for (int i = 0;i < countVisitors;i++)
		{
			visitsSet.insert(visit);
		}
	}
	file.close();
}

void printWhenNoVisitors(multiset<Visit> visitsSet)
{
	ofstream file("file1.txt", ios_base::out);
	if (!file.good())
	{
		throw exception("can not save data in file");
	}

	file << "On these hours there were no visitors in the pool:" << endl;

	bool ifVisited;
	for (int day = firstDay; day <= lastDay; day++)
	{
		ifVisited = false;
		for (int hour = beginOfWork; hour <= endOfWork; hour++)
		{

			Visit imaginaryVisit(day, hour);

			if (visitsSet.find(imaginaryVisit) == visitsSet.end())// if there is no element with this key in set, find() returns end()
			{
				if (!ifVisited)
				{
					file << "\n" << getDayByNumber(day) << ":" << endl;
					ifVisited = true;
				}
				file << hour << "  ";
			}
		}
	}
	file.close();
}


int thisDayVisits(multiset<Visit> visitsSet, const int& day)
{
	multiset<Visit>::iterator visitsIterator;

	int sumVisits = 0;
	for (visitsIterator = visitsSet.begin(); visitsIterator != visitsSet.end(); visitsIterator++)
	{
		if ((*visitsIterator).isDayEqual(day))
		{
			sumVisits += 1;
		}
	}

	return sumVisits;
}

void printLeastVisitedDay(multiset<Visit> visitsSet)
{
	ofstream file("file2.txt", ios_base::out);
	if (!file.good())
	{
		throw exception("can not save data in file");
	}

	file << "On this day there were the least visitors:" << endl;

	int minVisits = thisDayVisits(visitsSet, firstDay);
	int dayWithMin = firstDay;
	for (int day = firstDay + 1; day <= lastDay;day++)
	{
		int sumThisDay = thisDayVisits(visitsSet, day);
		if (sumThisDay < minVisits)
		{
			minVisits = sumThisDay;
			dayWithMin = day;
		}
	}
	file << getDayByNumber(dayWithMin) << endl;
	file.close();
}

int main()
{
	try
	{
		multiset<Visit> visitsSet;

		input(visitsSet);

		printWhenNoVisitors(visitsSet);

		printLeastVisitedDay(visitsSet);

		cout << "Everything is ok" << endl;
	}
	catch (invalid_argument& ex)
	{
		cout << ex.what() << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}

	system("PAUSE");
	return 0;
}