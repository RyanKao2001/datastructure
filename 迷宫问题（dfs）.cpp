#include <iostream>
#define N 100

using namespace std;

const int dirX[4] = { 0, -1, 1, 0 };        //分别表示下，左，右，上四个方向
const int dirY[4] = { 1, 0, 0, -1 };

int maze[N][N];

void InputMaze(int m, int n);
void DFS(int x, int y, int endx, int endy, int m, int n);
bool checkDir(int x, int y, int endx, int endy);
void outputPath(int m, int n);

int main()
{
	int m, n;
	cout << "请输入迷宫的行数和列数：" << endl;
	cin >> m >> n;
	InputMaze(m, n);
	cout << "请输入入口坐标：" << endl;
	int x, y;
	cin >> x >> y;
	int endx, endy;
	cout << "请输入出口坐标：" << endl;
	cin >> endx >> endy;

	maze[x-1][y-1] = 3;
	DFS(x-1, y-1, endx-1, endy-1, m, n);
	return 0;
}

void InputMaze(int m, int n)
{
	cout << "请输入迷宫（以空格分隔）：" << endl;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> maze[i][j];
}

//深度优先搜索
void DFS(int x, int y, int endx, int endy, int m, int n)
{
	for (int i = 0; i < 4; i++)
	{
		int newx = x + dirX[i];               // 新位置坐标
		int newy = y + dirY[i];

		if (checkDir(newx, newy, endx, endy))         // 边界检查
		{
			maze[newx][newy] = 3;             // 路能走就改为3
			if (newx == endx && newy == endy)
				outputPath(m, n);             // 到达出口输出路径
			else
				DFS(newx, newy, endx, endy, m, n);         // 路能走就一直走，走到不能走在再返回
		}
	}
	maze[x][y] = 2;           //  路不能走返回时将3改为2
}

//边界检查
bool checkDir(int x, int y, int endx, int endy)
{
	if (x < 0 || x>endx || y < 0 || y>endy || maze[x][y] != 0)
		return false;
	else
		return true;
}

//输出路径
void outputPath(int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (maze[i][j] == 3)         // 3表示完整的路，即迷宫路径
				cout << "+";
			else
				cout << "#";
		}
		cout << endl;
	}
}