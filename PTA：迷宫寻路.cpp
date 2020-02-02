/*ժ��PTA--�Թ�Ѱ·*/

/*����һ��M��N�е��Թ�ͼ������ "0"��ʾ��ͨ·��"1"��ʾ�ϰ���޷�ͨ�С�
���Թ���ֻ������ˮƽ�������ĸ������ͨ·�����ߣ��߹���λ�ò����ظ��ߡ�
5��8�е��Թ����£� 
0 1 1 1 0 0 0 0
0 0 0 1 0 0 0 0
0 1 0 0 0 1 0 0
0 1 1 1 0 1 1 0
1 0 0 0 0 0 0 0

������Ͻǣ�1��1�������½ǣ�5��8�������·��Ϊ��
1,1--��2,1--��2,2--��2,3--��3,3--��3,4--��3,5--��4,5--��5,5--��5,6--��5,7--��5,8
��Ŀ��֤ÿ���Թ����ֻ��һ�����·����
������������·��������������κ�ͨ·�������"NO FOUND".
�����ʽ:
��һ�У�����M��Nֵ����ʾ�Թ�������������
��������M����ֵ�����У�0��ʾͨ·��1��ʾ�ϰ��ÿ����ֵ�ÿո�������
������������������Թ����ݡ�
������M��ֵΪ-1ʱ�������롣
�����ʽ:
����˳�����·����ÿ��λ�õ��������������� x,y
����������κ�·���������"NO FOUND".
ÿ���Թ�Ѱ·����û��з������

��������:
���������һ���Թ������磺
8 8	
0 0 1 0 0 0 1 0
0 0 1 0 0 0 1 0
0 0 0 0 1 1 0 0
0 1 1 1 0 0 0 0
0 0 0 1 0 0 0 0
0 1 0 0 0 1 0 0
0 1 1 1 0 1 1 0
1 0 0 0 0 0 0 0
4 4	
0 0 1 0
0 0 0 0
0 0 1 1 
0 1 0 0
-1 -1 

�������:
�����������Ӧ����������磺
1,1
2,1
3,1
4,1
5,1
5,2
5,3
6,3
6,4
6,5
7,5
8,5
8,6
8,7
8,8

NO FOUND
*/

/*����C++��д�������ο�*/
#include <iostream>
#define INF 999
#define MAXSIZE 50

using namespace std;

typedef struct record
{
	int x;
	int y;
}point, record;

int dirx[4] = { -1, 0, 1, 0 };
int diry[4] = { 0, 1, 0, -1 };

int min_step = INF;
int times = 0;
point path[INF];
point shortest_path[INF];
record Index[10];
int **addr[10];
int flag[MAXSIZE][MAXSIZE];

int **InputMaze(int row, int col);
void DFS(int x, int y, int step, int i);
bool Check(int x, int y, int i);

int main()
{
	int row, col;
	while (1)
	{
		cin >> row >> col;
		if (row == -1) break;
		int **maze = InputMaze(row, col);
		addr[times] = maze;
		Index[times].x = row;
		Index[times].y = col;
		times++;
	}
	for (int i = 0; i < times; i++)
	{
		path[0].x = 0;
		path[0].y = 0;
		DFS(0, 0, 1, i);
		if (shortest_path[1].x == 0 && shortest_path[1].y == 0)
		{
			cout << "NO FOUND" << endl;
		}
		else
		{
			for (int j = 0; j < min_step; j++)
			{
				cout << shortest_path[j].x + 1 << "," << shortest_path[j].y + 1 << endl;
			}
			cout << endl;
			for (int k = 0; k < min_step; k++)
			{
				shortest_path[k].x = 0;
				shortest_path[k].y = 0;
			}
		}
	}
	return 0;
}

int **InputMaze(int row, int col)
{
	int **maze;
	maze = new int*[row];
	for (int i = 0; i < row; i++)
		maze[i] = new int[col];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> maze[i][j];
		}
	}
	return maze;
}

void DFS(int x, int y, int step, int p)
{
	if (x == Index[p].x - 1 && y == Index[p].y - 1)
	{
		if (step < min_step)
		{
			min_step = step;
			for (int i = 0; i < step; i++)
			{
				shortest_path[i] = path[i];
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int curx = x + dirx[i];
		int cury = y + diry[i];
		if (Check(curx, cury, p))
		{
			flag[curx][cury] = 1;
			path[step].x = curx;
			path[step].y = cury;
			DFS(curx, cury, step + 1, p);
			flag[curx][cury] = 0;
		}
	}
}

bool Check(int x, int y, int i)
{
	if (x<0 || x>Index[i].x - 1 || y<0 || y>Index[i].y - 1)
		return false;
	if ((addr[i])[x][y] == 1)
		return false;
	if (flag[x][y] == 1)
		return false;
	return true;
}