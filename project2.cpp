#include <stdio.h>
#include <stdlib.h>

char **GetArray(int n, int m);
void InputArray(char **p, int n, int m);
void PrintArray(char **p, int n, int m);

int main()
{
	int n, m;       //n为行，m为列
	scanf("%d%d", &n, &m);

	char **p = GetArray(n, m);
	InputArray(p, n, m);
	PrintArray(p, n, m);
	free(p);

	return 0;
}

char **GetArray(int n, int m)
{
	int i;
	char **p;

	p = (char **)malloc(sizeof(char *)*n);
	for (i = 0; i < n; i++)
	{
		p[i] = (char *)malloc(sizeof(char)*m);
	}

	return p;
}

void InputArray(char **p, int n, int m)
{
	int i, j; char ch;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%c", &p[i][j]);
		}
		if (i == n - 1) return;
		ch = getchar();
	}
}

void PrintArray(char **p, int n, int m)
{
	int i, j;
	int num = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (p[i][j] == '*') printf("* ");
			else
			{
				if (p[i + 1][j] == '*') num += 1;
				if (p[i - 1][j] == '*') num += 1;
				if (p[i][j - 1] == '*') num += 1;
				if (p[i][j + 1] == '*') num += 1;
				if (p[i - 1][j - 1] == '*') num += 1;
				if (p[i - 1][j + 1] == '*') num += 1;
				if (p[i + 1][j - 1] == '*') num += 1;
				if (p[i + 1][j + 1] == '*') num += 1;
				printf("%d ", num);
				num = 0;
			}
		}
		printf("\n");
	}
}