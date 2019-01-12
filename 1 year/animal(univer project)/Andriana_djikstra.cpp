
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
#define INF INT_MAX // 1 

const int sz = 10001; // 2
vector<pair<int, int> > a[sz]; // 3
int dis[sz]; //4
bool vis[sz] = { 0 }; //5

void Dijkstra(int source, int n) 
{
	for (int i = 0; i < sz; i++)
	{
		dis[i] = INF;//6
	}
	class prioritize
	{ 
		public:
			bool operator ()(pair<int, int>&p1, pair<int, int>&p2) { return p1.second>p2.second; } //7
	};
	priority_queue<pair<int, int>, vector<pair<int, int> >, prioritize> pq; //8
	pq.push(make_pair(source, dis[source] = 0)); //9
	while (!pq.empty())
	{
		pair<int, int> curr = pq.top(); //10
		pq.pop();
		int cv = curr.first, cw = curr.second; //11
		if (vis[cv]) //12
			continue;
		vis[cv] = true;
		for (int i = 0; i<a[cv].size(); i++) //13
			if (!vis[a[cv][i].first] && a[cv][i].second + cw<dis[a[cv][i].first]) //14
				pq.push(make_pair(a[cv][i].first, (dis[a[cv][i].first] = a[cv][i].second + cw))); //15
	}
}

void main() 
{
	int n, m, x, y, w;//16
	cout<<"Enter number of vertices and edges in the graph\n";
	cin >> n >> m;
	for (int i = 0; i<m; i++) //17
	{
		cin >> x >> y >> w; //18
		a[x].push_back(make_pair(y, w));
		a[y].push_back(make_pair(x, w));
	}
	cout<<"Enter starting vertex\n";
	int source;
	cin >> source;
	Dijkstra(source, n);
	cout << "Source is: " << source << ". The shortest distance to every other vertex from here is: \n";
	for (int i = 1; i <= n; i++)
	{
		cout << "Vertex: " << i << " , Distance: ";
		dis[i] != INF ? cout << dis[i] << "\n" : cout << "-1\n";
	}
}