#include <iostream>

using namespace std;

int place[8] = { 0 };
int chess[8][8] = { 0 };
bool flag[8] = { 1,1,1,1,1,1,1,1 };
bool UpperDiagonal[15];            //上对角线
bool LowerDiagonal[15];            //下对角线
int number = 0;

void print();
void fun(int n);

int main()
{
	//初始化
	for (int i = 0; i < 15; i++)
	{
		UpperDiagonal[i] = 1;
		LowerDiagonal[i] = 1;
	}
	fun(0);
	return 0;
}

void fun(int n)
{
	int col;
	for (col = 0; col < 8; col++)
	{
		if (flag[col] && UpperDiagonal[n - col + 7] && LowerDiagonal[n + col])     //如果未被占领
		{
			place[n] = col;                 //占领行
			flag[col] = false;			    //占领列
			UpperDiagonal[n - col + 7] = false;       //占领上对角线
			LowerDiagonal[n + col] = false;             //占领下对角线
			//递归
			if (n == 7) print();
			else
			{
				fun(n + 1);
			}
			//回溯，继续探索下一种情况
			flag[col] = true;
			UpperDiagonal[n - col + 7] = true;
			LowerDiagonal[n + col] = true;
		}
	}
}

void print()
{
	int i, j;
	number++;
	cout << "第" << number << "种情况：" << endl;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (place[i] == j)
				chess[i][j] = 1;
			continue;
		}
	}

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			cout << chess[i][j]<<" ";
		}
		cout << endl;
	}
	//置零
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			chess[i][j] = 0;
		}
	}
}