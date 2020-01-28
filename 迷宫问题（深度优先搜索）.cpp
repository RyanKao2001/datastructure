#include <iostream>
#define N 100

using namespace std;

const int dirX[4] = { 0, -1, 1, 0 };        //�ֱ��ʾ�£����ң����ĸ�����
const int dirY[4] = { 1, 0, 0, -1 };

int maze[N][N];

void InputMaze(int m, int n);
void DFS(int x, int y, int endx, int endy, int m, int n);
bool checkDir(int x, int y, int endx, int endy);
void outputPath(int m, int n);

int main()
{
	int m, n;
	cout << "�������Թ���������������" << endl;
	cin >> m >> n;
	InputMaze(m, n);
	cout << "������������꣺" << endl;
	int x, y;
	cin >> x >> y;
	int endx, endy;
	cout << "������������꣺" << endl;
	cin >> endx >> endy;

	maze[x-1][y-1] = 3;
	DFS(x-1, y-1, endx-1, endy-1, m, n);
	return 0;
}

void InputMaze(int m, int n)
{
	cout << "�������Թ����Կո�ָ�����" << endl;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> maze[i][j];
}

//�����������
void DFS(int x, int y, int endx, int endy, int m, int n)
{
	for (int i = 0; i < 4; i++)
	{
		int newx = x + dirX[i];               // ��λ������
		int newy = y + dirY[i];

		if (checkDir(newx, newy, endx, endy))         // �߽���
		{
			maze[newx][newy] = 3;             // ·���߾͸�Ϊ3
			if (newx == endx && newy == endy)
				outputPath(m, n);             // ����������·��
			else
				DFS(newx, newy, endx, endy, m, n);         // ·���߾�һֱ�ߣ��ߵ����������ٷ���
		}
	}
	maze[x][y] = 2;           //  ·�����߷���ʱ��3��Ϊ2
}

//�߽���
bool checkDir(int x, int y, int endx, int endy)
{
	if (x < 0 || x>endx || y < 0 || y>endy || maze[x][y] != 0)
		return false;
	else
		return true;
}

//���·��
void outputPath(int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (maze[i][j] == 3)         // 3��ʾ������·�����Թ�·��
				cout << "+";
			else
				cout << "#";
		}
		cout << endl;
	}
}