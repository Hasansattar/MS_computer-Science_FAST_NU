#include <iostream>
#include <vector>

using namespace std;

const int v = 6;
int Mat[v][v];

struct Vertex
{
	char point;
	int cost;
};

struct Point
{
	char point;
	vector<Vertex> vec_list;
};

void addEdge(Point*& point, char src, char dest, int cost)
{
	for (int i = 0; i < v; i++)
	{
		if (point[i].point == src)
		{
			point[i].vec_list.push_back({ dest, cost });
		}
	}
	for (int i = 0; i < v; i++)
	{
		if (point[i].point == dest)
		{
			point[i].vec_list.push_back({ src, cost });
		}
	}
}

void displayGraph(Point* point)
{
	for (int i = 0; i < v; i++)
	{
		cout << point[i].point << " ---> ";
		for (auto j : point[i].vec_list)
			cout << j.point << " ";
		cout << endl;
	}
}

void convertToAdjMat(Point* point)
{
	char* names = new char[v];
	for (int i = 0; i < v; i++)
	{
		names[i] = point[i].point;
	}
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
			Mat[i][j] = 0;
	}

	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			for (auto k : point[i].vec_list)
			{
				if (k.point == names[j])
				{
					Mat[i][j] = 1;
					break;
				}
			}
		}
	}
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			cout << Mat[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	Point* points = new Point[v];
	char names[v] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	for (int i = 0; i < v; i++)
	{
		points[i].point = names[i];
	}

	addEdge(points, 'a', 'b', 7);
	addEdge(points, 'a', 'f', 14);
	addEdge(points, 'a', 'c', 9);
	addEdge(points, 'b', 'c', 10);
	addEdge(points, 'b', 'd', 15);
	addEdge(points, 'c', 'd', 11);
	addEdge(points, 'c', 'f', 2);
	addEdge(points, 'd', 'e', 6);
	addEdge(points, 'e', 'f', 9);
	displayGraph(points);

	convertToAdjMat(points);

	system("PAUSE");
	return 0;
}
