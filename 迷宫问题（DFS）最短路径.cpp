/*
25�У�25��
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

/*������ڣ����³���*/
#include <iostream>
#define MAXSIZE 100
#define INF 999        //���塰�����

using namespace std;

typedef struct record      //����point�ṹ�����
{
	int x;
	int y;
}point;

int total;
int min_step = INF;
int dirx[4] = { 0, 1, 0, -1 };     //�����ĸ�����
int diry[4] = { -1, 0, 1, 0 };
int maze[MAXSIZE][MAXSIZE];
int flag[MAXSIZE][MAXSIZE] = { 0 };
int row, col;
int step;
point path[INF];           //��¼·������
point shortest_path[INF];         //��¼���·��

void InputMaze();
bool Check(int x, int y);
void DFS(int x, int y, int setp);
void outputPath();

int main()
{
	InputMaze();

	path[0].x = 0;         //���������Ϊ(0, 0)
	path[0].y = 0;

	DFS(0, 0, 1);
	outputPath();
	return 0;
}

void InputMaze()
{
	cout << "�������Թ�������������" << endl;
	cin >> row >> col;
	cout << "�������Թ���������ڣ����³��ڣ������Կո�ָ���" << endl;
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
	if (x == row - 1 && y == col -1 )        //�������
	{
		cout << "·��" << ++total << ":" << endl;
		for (int i = 0; i < step; i++)
		{
			cout << "(" << path[i].x + 1 << "," << path[i].y + 1 << ")" << " ";
		}
		cout << endl << "Steps:" << step << endl << endl;
		if (step < min_step)               //����ǰ����С����̲���
		{
			min_step = step;
			for (int i = 0; i < step; i++)       //�������·��
			{
				shortest_path[i] = path[i];
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int curx = x + dirx[i];         //���ĸ�������̽
		int cury = y + diry[i];

		if (Check(curx, cury))
		{
			flag[curx][cury] = 1;
			path[step].x = curx;           //����ǰ�����¼
			path[step].y = cury;
			DFS(curx, cury, step + 1);
			flag[curx][cury] = 0;         //����ʱ��flag����Ϊ0
		}
	}
}

bool Check(int x, int y)
{
	if (x<0 || x>row - 1 || y < 0 || y>col - 1)    //�����߽�
		return false;
	if (maze[x][y] == 1)       //ǽ
		return false;
	if (flag[x][y] == 1)      //���߹�
		return false;
	return true;
}

void outputPath()
{
	cout << "���·��:" << endl;
	for (int i = 0; i < min_step; i++)
	{
		cout << "(" << shortest_path[i].x + 1 << "," << shortest_path[i].y + 1 << ")" << " ";
	}
	cout << endl;
	cout << "Steps:" << min_step << endl << endl;

	cout << "��ӡ���·��" << endl;
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
				cout << "��";
			if(flag[i][j] == 1)
				cout << "��";
			if (flag[i][j] == 0)
				cout << "  ";
		}
		cout << endl;
	}
}