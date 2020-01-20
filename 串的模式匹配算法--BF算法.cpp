#include <stdio.h>
#include <string.h>
#define MAXSIZE 100

typedef struct SqList
{
	char ch[MAXSIZE];
	int length;
}String;

int Index_BF(String S, String T);

int main()
{
	String S, T;
	int flag;

	printf("请输入目标串（主串）：\n");
	gets_s(S.ch);
	printf("请输入模式串（字串）：\n");
	gets_s(T.ch);

	S.length = strlen(S.ch);
	T.length = strlen(T.ch);
	
	if (flag = Index_BF(S, T))
		printf("匹配成功！子串的位置：%d\n", flag);
	else
		printf("匹配失败！\n");
	return 0;
}

int Index_BF(String S, String T)
{
	int i = 0, j = 0;
	while (i < S.length && j < T.length)
	{
		if (S.ch[i] == T.ch[j]) { i++; j++; }
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == T.length)
		return i - j + 1;
	else
		return 0;
}