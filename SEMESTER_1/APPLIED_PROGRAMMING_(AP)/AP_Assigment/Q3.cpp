#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int v = 20;
string names[v] =
	{
		"Arad", "Bucharest", "Craiova", "Dobreta", "Eforie",
		"Fagaras", "Hirsova", "Iasi", "Lugoj", "Oradea",
		"Pitesti", "Rimnicu Vilcea", "Urziceni", "Giurgiu", "Mehadia",
		"Sibiu", "Neamt", "Vaslui", "Timisoara", "Zerind"};

struct Vertex
{
	string point;
	int cost;
};

struct Point
{
	string point;
	vector<Vertex> vec_list;
};

int getIndex(Point *&point, string name)
{
	int index = -1;
	for (int i = 0; i < v; i++)
	{
		if (point[i].point == name)
		{
			index = i;
			break;
		}
	}
	return index;
}

void addEdge(Point *&point, string src, string dest, int cost)
{
	int i = getIndex(point, src);
	if (i == -1)
	{
		cout << "error" << endl;
		return;
	}
	point[i].vec_list.push_back({dest, cost});
	i = getIndex(point, dest);
	if (i == -1)
	{
		cout << "error" << endl;
		return;
	}
	point[i].vec_list.push_back({src, cost});
}

void displayGraph(Point *point)
{
	for (int i = 0; i < v; i++)
	{
		cout << point[i].point << " ---> ";
		for (auto j : point[i].vec_list)
			cout << j.point << " ";
		cout << endl;
	}
}

void applyBFS(Point *point, string src, string dest)
{
	queue<Vertex> q;
	bool *visited = new bool[v];
	for (int i = 0; i < v; i++)
		visited[i] = false;
	int startindex = getIndex(point, src);
	if (startindex == -1)
	{
		cout << "error" << endl;
		return;
	}
	q.push({point[startindex].point, 0});
	visited[startindex] = true;
	bool goal = false;
	while (!q.empty())
	{
		Vertex vert = q.front();
		q.pop();
		if (vert.point == dest)
		{
			goal = true;
			break;
		}
		cout << vert.point << " ---> ";
		for (auto i : point[getIndex(point, vert.point)].vec_list)
		{
			startindex = getIndex(point, i.point);
			if (visited[startindex] == false)
			{
				q.push({i.point, i.cost});
				visited[startindex] = true;
			}
		}
	}
	if (goal == true)
		cout << "goal found...\n";
	else
		cout << "goal not found...\n";
}

void applyDFSUtil(Point *point, string dest, int v, bool *&visited, bool &goal)
{
	visited[v] = true;
	int index;
	for (auto i : point[v].vec_list)
	{
		index = getIndex(point, i.point);
		if (visited[index] == false)
		{
			if (i.point == dest)
			{
				goal = true;
				return;
			}
			cout << i.point << " ---> ";
			applyDFSUtil(point, dest, getIndex(point, i.point), visited, goal);
		}
		if (goal)
		{
			return;
		}
	}
}

void applyDFS(Point *point, string src, string dest)
{
	bool *visited = new bool[v];
	for (int i = 0; i < v; i++)
		visited[i] = false;
	int startindex = getIndex(point, src);
	if (startindex == -1)
	{
		cout << "error" << endl;
		return;
	}

	bool goal = false;
	for (int i = 0; i < v; i++)
	{
		if (visited[i] == false && !goal)
		{
			cout << point[i].point << " ---> ";
			applyDFSUtil(point, dest, i, visited, goal);
		}
	}

	if (goal == true)
		cout << "goal found...\n";
	else
		cout << "goal not found...\n";
}

int main()
{
	Point *point = new Point[v];
	for (int i = 0; i < v; i++)
		point[i].point = names[i];

	addEdge(point, "Arad", "Sibiu", 140);
	addEdge(point, "Arad", "Timisoara", 118);
	addEdge(point, "Arad", "Zerind", 75);
	addEdge(point, "Bucharest", "Fagaras", 211);
	addEdge(point, "Bucharest", "Giurgiu", 90);
	addEdge(point, "Bucharest", "Pitesti", 101);
	addEdge(point, "Bucharest", "Urziceni", 85);
	addEdge(point, "Craiova", "Dobreta", 120);
	addEdge(point, "Craiova", "Pitesti", 138);
	addEdge(point, "Craiova", "Rimnicu Vilcea", 146);
	addEdge(point, "Dobreta", "Mehadia", 75);
	addEdge(point, "Eforie", "Hirsova", 86);
	addEdge(point, "Fagaras", "Sibiu", 99);
	addEdge(point, "Hirsova", "Urziceni", 98);
	addEdge(point, "Iasi", "Neamt", 87);
	addEdge(point, "Iasi", "Vaslui", 92);
	addEdge(point, "Lugoj", "Mehadia", 70);
	addEdge(point, "Lugoj", "Timisoara", 111);
	addEdge(point, "Oradea", "Zerind", 71);
	addEdge(point, "Oradea", "Sibiu", 151);
	addEdge(point, "Pitesti", "Rimnicu Vilcea", 97);
	addEdge(point, "Rimnicu Vilcea", "Sibiu", 80);
	addEdge(point, "Urziceni", "Vaslui", 142);

	// displayGraph(point);
	cout << "BFS \n";
	applyBFS(point, "Arad", "Bucharest");

	cout << endl;
	cout << "DFS \n";
	applyDFS(point, "Arad", "Bucharest");

	system("PAUSE");
	return 0;
}
