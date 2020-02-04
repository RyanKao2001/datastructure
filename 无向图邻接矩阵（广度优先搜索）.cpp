#include <iostream>
#include <queue>
#define MAXSIZE 10

using namespace std;

int matrix[MAXSIZE][MAXSIZE] = 
{
	{ 0, 1, 0, 0, 1, 0, 0, 0, 0, 0 },
	{ 1, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 0, 0, 0, 1, 0, 0, 0 },
	{ 0, 1, 0, 0, 1, 1, 0, 0, 0, 0 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 1, 0 },
	{ 0, 0, 0, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 0, 0, 1, 0, 0, 0, 1 },
	{ 0, 0, 0, 0, 0, 1, 0, 0, 1, 1 },
	{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 }
};

int flag[MAXSIZE + 1];
void BFS();

int main()
{
	BFS();
	return 0;
}

void BFS()
{
	flag[ 1 ] = 1;
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int top = q.front();
		cout << top << " ";
		q.pop();
		for (int i = 1; i <= MAXSIZE; i++)
		{
			if (flag[i] == 0 && matrix[top - 1][i - 1] == 1)
			{
				flag[i] = 1;
				q.push(i);
			}
		}
	}
}