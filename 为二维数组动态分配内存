#include <stdio.h>
#include <stdlib.h>

int **GetArray(int n, int m);                   // 创建二位数组
void InputArray(int **p, int n, int m);         // 为二维数组赋值
void PrintArray(int **p, int n, int m);         // 输出二维数组

int main()
{
	int n, m;                          // n为行，m为列
	scanf("%d %d", &n, &m);

	int **p = GetArray(n, m);
	InputArray(p, n, m);
	PrintArray(p, n, m);
	free(p);

	return 0;
}

int **GetArray(int n, int m)
{
	int **p = NULL;

	p = (int **)malloc(sizeof(int *)*n);
	for (int i = 0; i < n; i++)
	{
		p[i] = (int *)malloc(sizeof(int)*m);
	}
	return p;
}

void InputArray(int **p, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			p[i][j] = i + 1;
		}
	}
}

void PrintArray(int **p, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
}
