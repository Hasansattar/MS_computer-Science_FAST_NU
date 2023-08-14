#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

struct Point
{
	int x, y;
};
int start[2] = {0, 0}, goal[2] = {0, 0};

void updatedMatric(int **arr, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] == 9)
			{
				cout << "* ";
			}
			else
			{
				cout << arr[i][j] << " ";
			}
		}
		cout << endl;
	}
}

void copyArray(int **to, int **from, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			to[i][j] = from[i][j];
		}
	}
}

void applyBFS(int **arr, int r, int c)
{
	int **new_arr;
	new_arr = new int *[r];
	for (int i = 0; i < r; i++)
	{
		new_arr[i] = new int[c];
	}
	copyArray(new_arr, arr, r, c);
	queue<Point> q;
	Point p;
	int cost = 0;
	q.push({start[0], start[1]});
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		if (p.x == goal[0] && p.y == goal[1])
		{
			cout << "goal is found !!!" << endl;
			break;
		}

		if (p.x - 1 >= 0 && !new_arr[p.x - 1][p.y])
		{
			new_arr[p.x - 1][p.y] = 9;
			q.push({p.x - 1, p.y});
			cost += 2;
		}

		if ((p.x - 1) >= 0 && (p.y + 1) < c)
		{
			if (!new_arr[p.x - 1][p.y + 1])
			{
				new_arr[p.x - 1][p.y + 1] = 9;
				q.push({p.x - 1, p.y + 1});
				cost += 2;
			}
		}

		if ((p.y + 1) < c && !new_arr[p.x][p.y + 1])
		{
			new_arr[p.x][p.y + 1] = 9;
			q.push({p.x, p.y + 1});
			cost += 2;
		}
	}
	cout << "cost: " << cost << endl;
	updatedMatric(new_arr, r, c);
}

void applyDFS(int **arr, int r, int c)
{
	int **new_arr;
	new_arr = new int *[r];
	for (int i = 0; i < r; i++)
	{
		new_arr[i] = new int[c];
	}
	copyArray(new_arr, arr, r, c);
	stack<Point> s;
	Point p;
	int cost = 0;
	s.push({start[0], start[1]});
	while (!s.empty())
	{
		p = s.top();
		s.pop();
		if (p.x == goal[0] && p.y == goal[1])
		{
			cout << "goal is found !!!" << endl;
			break;
		}

		if (p.x - 1 >= 0 && !new_arr[p.x - 1][p.y])
		{
			new_arr[p.x - 1][p.y] = 9;
			s.push({p.x - 1, p.y});
			cost += 2;
		}

		if ((p.x - 1) >= 0 && (p.y + 1) < c)
		{
			if (!new_arr[p.x - 1][p.y + 1])
			{
				new_arr[p.x - 1][p.y + 1] = 9;
				s.push({p.x - 1, p.y + 1});
				cost += 2;
			}
		}

		if ((p.y + 1) < c && !new_arr[p.x][p.y + 1])
		{
			new_arr[p.x][p.y + 1] = 9;
			s.push({p.x, p.y + 1});
			cost += 2;
		}
	}
	cout << "cost: " << cost << endl;
	updatedMatric(new_arr, r, c);
}

bool fillArray(int **arr, int r, int c);

int main()
{
	int r = 15, c = 15;
	int **arr;
	arr = new int *[r];
	for (int i = 0; i < r; i++)
	{
		arr[i] = new int[c];
	}
	if (!fillArray(arr, r, c))
	{
		return 0;
	}

	cout << "starting: ";
	cin >> start[0] >> start[1];
	cout << "goal: ";
	cin >> goal[0] >> goal[1];

	start[0] = 15 - start[0];
	start[1]--;
	goal[0] = 15 - goal[0];
	goal[1] = 15;

	cout << "BFS " << endl;
	applyBFS(arr, r, c);
	cout << endl;
	cout << endl;

	cout << "DFS " << endl;
	applyDFS(arr, r, c);

	system("PAUSE");
	return 0;
}

bool fillArray(int **arr, int r, int c)
{
	fstream fs;
	fs.open("robot.txt");
	if (!fs.is_open())
	{
		cout << "file not exist...\n"
			 << endl;
		return false;
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			fs >> arr[i][j];
		}
	}
	fs.close();
	return true;
}
