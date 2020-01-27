#include <iostream>
#define MAXSIZE 100

using namespace std;

int length;
typedef struct Stack
{
	char *top;
	char *base;
	int StackSize;
}SqStack;

void CreateStack(SqStack &S);
void Push(SqStack &S, char data);
char Pop(SqStack &S);
void InputArray(char Input[]);
void fun(char Input[], SqStack &S);

int main()
{
	SqStack S;
	CreateStack(S);
	char Input[MAXSIZE];
	InputArray(Input);
	fun(Input, S);
	return 0;
}

void CreateStack(SqStack &S)
{
	S.base = new char[MAXSIZE];
	S.top = S.base;
	S.StackSize = MAXSIZE;
}

void Push(SqStack &S, char data)
{
	if (S.top - S.base == S.StackSize)
		return;
	else
	{
		*S.top = data;
		S.top++;
	}
}

char Pop(SqStack &S)
{
	if (S.top == S.base)
		return -1;
	else
	{
		--S.top;
		return *S.top;
	}
}

void Print(SqStack S)
{
	--S.top;
	while (S.top != S.base - 1)
	{
		printf("%c -> ", *S.top);
		S.top--;
	}
	printf("NULL\n");
}

void InputArray(char Input[])
{
	int i = 0;
	char ch;
	while (1)
	{
		cin >> ch;
		char t = getchar();
		Input[i] = ch;
		i++;
		if (t == '\n')
			break;
	}
	length = i;
}

void fun(char Input[], SqStack &S)
{
	int i = -1;
	char temp[3];
	int a, b;
	int result;
	while (i != length)
	{
		do
		{
			i++;
			Push(S, Input[length - i - 1]);
		}while (Input[length - i - 1] >= '0' && Input[length - i - 1] <= '9');

		for (int j = 0; j < 3; j++)
		{
			temp[j] = Pop(S);
		}
		a = (int)temp[1] - 48;
		b = (int)temp[2] - 48;
		switch (temp[0])
		{
		case '+':result = a + b; break;
		case '-':result = a - b; break;
		case '*':result = a * b; break;
		case '/':
			if (b == 0)
			{
				cout << "ERROR"; return;
			}
			else
				result = a / b;
			break;
		}
		Push(S, (char)result+48);
	}
	printf("%.1f",(float)Pop(S)-48);
}