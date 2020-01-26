#include <iostream>

using namespace std;

int place[8] = { 0 };
bool chess[8][8] = { 0 };
bool flag[8] = { 1,1,1,1,1,1,1,1 };
bool UpperDiagonal[15];
bool LowerDiagonal[15];
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
	int line;
	for (line = 0; line < 8; line++)
	{
		if (flag[line] && UpperDiagonal[n - line + 7] && LowerDiagonal[n + line])
		{
			place[n] = line;
			flag[line] = false;
			UpperDiagonal[n - line + 7] = false;
			LowerDiagonal[n + line] = false;
			//递归
			if (n == 7) print();
			else
			{
				fun(n + 1);
			}
			//回溯
			flag[line] = true;
			UpperDiagonal[n - line + 7] = true;
			LowerDiagonal[n + line] = true;
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