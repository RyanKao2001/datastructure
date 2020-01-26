#include <iostream>
#define MAXSIZE 100

using namespace std;

typedef struct Stack
{
	int *top;
	int *base;
	int StackSize;
}SqStack;

void CreateStack(SqStack &S);
void Push(SqStack &S, int data);
int Pop(SqStack &S);
int IsEmpty(SqStack S);
int StackLength(SqStack S);
void ClearStack(SqStack S);
void DestroyStack(SqStack &S);
void Print(SqStack S);

int main()
{
	SqStack S;         //创建栈
	CreateStack(S);
	cout << "入栈中..." << endl;
	Push(S, 1);      //入栈
	Push(S, 2);
	Push(S, 3);
	cout << "出栈中..." << endl;
	Pop(S);
	Print(S);     //打印
	cout << "清空顺序栈..." << endl;
	ClearStack(S);
	cout << "入栈中..." << endl;
	Push(S, 5);
	Push(S, 6);
	Push(S, 7);
	Print(S);
	DestroyStack(S);
	return 0;
}

//创建顺序栈
void CreateStack(SqStack &S)
{
	S.base = new int[MAXSIZE];
	S.top = S.base;
	S.StackSize = MAXSIZE;
}

//入栈
void Push(SqStack &S, int data)
{
	if (S.top - S.base == S.StackSize)
		return;
	else
	{
		*S.top = data;
		S.top++;
	}
}

//出栈
int Pop(SqStack &S)
{
	if (S.base == S.top) 
		return -1;
	else
	{
		--S.top;
		return *S.top;
	}
}

//判断栈空
int IsEmpty(SqStack S)
{
	if (S.base == S.top)
		return 1;
	else
		return 0;
}

//求顺序栈长度
int StackLength(SqStack S)
{
	return S.top - S.base;
}

//清空栈
void ClearStack(SqStack S)
{
	if (S.base)
		S.top = S.base;
	else
		return;
}

//销毁栈
void DestroyStack(SqStack &S)
{
	if (S.base)
	{
		delete[]S.base;
		S.StackSize = 0;
		S.base = S.top = NULL;
	}
}

//打印
void Print(SqStack S)
{
	--S.top;
	while (S.top != S.base - 1)
	{
		cout << *S.top << " -> ";
		S.top--;
	}
	cout << "NULL" << endl;
}