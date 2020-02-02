/*
25行，25列
0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1
1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1
1 0 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 0 1
1 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 1
1 0 1 0 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 0 1 0 1
1 0 1 0 1 0 1 0 0 0 0 0 1 0 0 0 0 0 1 0 1 0 1 0 1
1 0 1 0 1 0 1 0 1 1 1 1 1 1 1 1 1 0 1 0 1 0 1 0 1
1 0 1 0 1 0 1 0 1 0 0 0 0 0 0 0 1 0 1 0 1 0 1 0 1
1 0 1 0 1 0 1 0 1 0 1 1 1 1 1 0 1 0 1 0 1 0 0 0 1
1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1
1 1 1 0 1 0 1 1 1 0 1 1 0 1 1 0 1 1 1 0 1 1 1 1 1
1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1
1 0 1 0 0 0 1 0 1 0 1 1 1 1 1 0 1 0 1 0 1 0 1 0 1
1 0 1 0 1 0 1 0 1 0 0 0 1 0 0 0 1 0 1 0 1 0 1 0 1
1 0 1 0 1 1 1 0 1 1 0 1 1 1 0 1 1 0 1 0 1 0 1 0 1
1 0 1 1 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 1 0 1 0 1
1 0 1 0 0 0 1 1 1 1 1 1 1 1 1 1 0 1 1 0 1 0 1 0 1
1 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 1 0 1 0 1
1 0 1 0 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 0 1 0 1 0 1
1 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0
*/

/*左上入口，右下出口*/
#include <iostream>
#define MAXSIZE 100
#define INF 999        //定义“无穷大”

using namespace std;

typedef struct record      //定义point结构体变量
{
	int x;
	int y;
}point;

int total;
int min_step = INF;
int dirx[4] = { 0, 1, 0, -1 };     //定义四个方向
int diry[4] = { -1, 0, 1, 0 };
int maze[MAXSIZE][MAXSIZE];
int flag[MAXSIZE][MAXSIZE] = { 0 };
int row, col;
int step;
point path[INF];           //记录路径坐标
point shortest_path[INF];         //记录最短路径

void InputMaze();
bool Check(int x, int y);
void DFS(int x, int y, int setp);
void outputPath();

int main()
{
	InputMaze();

	path[0].x = 0;         //起点坐标设为(0, 0)
	path[0].y = 0;

	DFS(0, 0, 1);
	outputPath();
	return 0;
}

void InputMaze()
{
	cout << "请输入迷宫的行数和列数" << endl;
	cin >> row >> col;
	cout << "请输入迷宫（左上入口，右下出口，输入以空格分隔）" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> maze[i][j];
		}
	}
}

void DFS(int x, int y, int step)
{
	if (x == row - 1 && y == col -1 )        //到达出口
	{
		cout << "路径" << ++total << ":" << endl;
		for (int i = 0; i < step; i++)
		{
			cout << "(" << path[i].x + 1 << "," << path[i].y + 1 << ")" << " ";
		}
		cout << endl << "Steps:" << step << endl << endl;
		if (step < min_step)               //若当前步数小于最短步数
		{
			min_step = step;
			for (int i = 0; i < step; i++)       //更新最短路径
			{
				shortest_path[i] = path[i];
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int curx = x + dirx[i];         //向四个方向试探
		int cury = y + diry[i];

		if (Check(curx, cury))
		{
			flag[curx][cury] = 1;
			path[step].x = curx;           //将当前坐标记录
			path[step].y = cury;
			DFS(curx, cury, step + 1);
			flag[curx][cury] = 0;         //回溯时将flag重置为0
		}
	}
}

bool Check(int x, int y)
{
	if (x<0 || x>row - 1 || y < 0 || y>col - 1)    //超出边界
		return false;
	if (maze[x][y] == 1)       //墙
		return false;
	if (flag[x][y] == 1)      //已走过
		return false;
	return true;
}

void outputPath()
{
	cout << "最短路径:" << endl;
	for (int i = 0; i < min_step; i++)
	{
		cout << "(" << shortest_path[i].x + 1 << "," << shortest_path[i].y + 1 << ")" << " ";
	}
	cout << endl;
	cout << "Steps:" << min_step << endl << endl;

	cout << "打印最短路径" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			flag[i][j] = maze[i][j];
		}
	}

	for (int i = 0; i < min_step; i++)
	{
		flag[shortest_path[i].x][shortest_path[i].y] = 2;
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (flag[i][j] == 2)
				cout << "◇";
			if(flag[i][j] == 1)
				cout << "█";
			if (flag[i][j] == 0)
				cout << "  ";
		}
		cout << endl;
	}
}