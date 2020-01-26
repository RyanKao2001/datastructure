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
	SqStack S;         //����ջ
	CreateStack(S);
	cout << "��ջ��..." << endl;
	Push(S, 1);      //��ջ
	Push(S, 2);
	Push(S, 3);
	cout << "��ջ��..." << endl;
	Pop(S);
	Print(S);     //��ӡ
	cout << "���˳��ջ..." << endl;
	ClearStack(S);
	cout << "��ջ��..." << endl;
	Push(S, 5);
	Push(S, 6);
	Push(S, 7);
	Print(S);
	DestroyStack(S);
	return 0;
}

//����˳��ջ
void CreateStack(SqStack &S)
{
	S.base = new int[MAXSIZE];
	S.top = S.base;
	S.StackSize = MAXSIZE;
}

//��ջ
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

//��ջ
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

//�ж�ջ��
int IsEmpty(SqStack S)
{
	if (S.base == S.top)
		return 1;
	else
		return 0;
}

//��˳��ջ����
int StackLength(SqStack S)
{
	return S.top - S.base;
}

//���ջ
void ClearStack(SqStack S)
{
	if (S.base)
		S.top = S.base;
	else
		return;
}

//����ջ
void DestroyStack(SqStack &S)
{
	if (S.base)
	{
		delete[]S.base;
		S.StackSize = 0;
		S.base = S.top = NULL;
	}
}

//��ӡ
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