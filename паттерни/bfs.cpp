#include <iostream>
#include <queue>
#include <vector>
using namespace std;


const int n = 10;
vector<int> graph[n + 1];//for each city, which cities it is connected with
bool visited[n + 1];

void bfs(int vertix)
{
	queue<int> q;
	q.push(vertix);

	visited[vertix] = 1;

	while (!q.empty())
	{
		int currentCity = q.front();
		q.pop();

		for (int i = 0; i < graph[currentCity].size(); i++)
		{
			int adjacentToThis = graph[currentCity][i];
			if (visited[adjacentToThis] == 0)
			{
				visited[adjacentToThis] = 1;
				q.push(adjacentToThis);
			}
		}
	}
}


int main()
{
	cout << "Enter roads" << endl;
	int city1, city2;

	try
	{
		while (cin >> city1 >> city2)
		{
			if (city1 == 0 && city2 == 0)
			{
				break;
			}

			if ((city1 >= city2) || (city1 <= 0) || (city2 <= 0) || (city1 > n) || (city2 > n))
			{
				throw invalid_argument("incorrect data");
			}

			graph[city1].push_back(city2);
			graph[city2].push_back(city1);
		}

		bfs(1);//start bfs from city 1

		if (visited[n] == 0)
		{
			cout << "NO";
		}
		else
		{
			cout << "YES";
		}
	}
	catch (const invalid_argument& ex)
	{
		cout << ex.what() << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	system("PAUSE");
	return 0;
}