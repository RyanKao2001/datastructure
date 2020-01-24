/*摘自PTA：扫雷游戏，以下为题目描述*/

/*玩过扫雷游的朋友都知道，该游戏的目标是找出一个nm矩阵内的所有的地雷，
在本题中，你需要为每一个单元格统计出它周围地雷的个数，每个单元格最多有
8个相邻单元格，如下图，44 的格子里，用“*”表示雷，用“^” 表示没有雷。
*^^^
^^^^
^*^^
^^^^
计算后的输出结果为：
*100
2210
1*10
1110

输入格式:

输入包含若干个矩阵，对于每一个矩阵，第一行包含两个数M和N，分别表示该矩
阵的行数和列数（0<N，M<100）,接下来N行包含M个字符，就是该矩阵，用
“*”表示地雷，用“^”表示空白。当N=M=0时，表示结束，不用处理该行。

输出格式:

对于每一个矩阵，首先在单独一行打印出矩阵序号：Field #X: 其中X是矩阵的编号，
从1开始编号，接下来N行中，读入的“^”用该位置周围的地雷数目所代替，地雷处
，仍用“*”表示。输出相邻的两个矩阵之间，空一行。

输入样例:

在这里给出一组输入。例如：
4 4 
*^^^
^^^^
^*^^
^^^^
8 8
*^^^*^^^
*^****^^
^*^^**^^
^^**^**^
^*^^**^^
*^^^*^^^
^^**^**^
^*^^**^^
0 0    
输出样例:

在这里给出相应的输出。例如：
Field #1:
*100
2210
1*10
1110

Field #2:
*324*310
*4****20
2*56**41
23**6**1
2*34**31
*334*531
23**5**1
1*33**31
*/

/*以下代码个人基于C++编写，答案无误，仅供参考*/

#include <iostream>

using namespace std;

int Times = 1;
typedef struct List
{
	char **feild;
	struct List *next;
}LinkList, *pLinkList;
typedef struct mn
{
	int m;
	int n;
}mn;

pLinkList CreateNode(char **data);
pLinkList CreateList();
char **GetArray(int n, int m);
void InputArray(char **p, int n, int m);
void PrintArray(char **p, int n, int m);
void DestroyList(pLinkList pHead);
void PrintList(pLinkList pHead, char **pField[], mn Index[]);
void InsertListTail(pLinkList *pRear, char **p);

int main()
{
	char **pField[1000];
	int i = 0;
	char **p = NULL;
	mn Index[1000];
	//创建头结点
	pLinkList HeadNode = CreateList();
	//定义头尾指针
	pLinkList pHead = HeadNode;
	pLinkList pRear = HeadNode;
	//输入雷阵
	while (1)
	{
		cin >> Index[i].m >> Index[i].n;
		if (Index[i].m == 0 && Index[i].n == 0) break;
		p = GetArray(Index[i].n, Index[i].m);
		pField[i] = p;
		InputArray(p, Index[i].n, Index[i].m);
		InsertListTail(&pRear, p);
		i++;
	}
	//打印雷阵
	PrintList(pHead,pField, Index);
	DestroyList(pHead);
	return 0;
}

void InsertListTail(pLinkList *pRear, char **p)
{
	pLinkList NewNode = CreateNode(p);
	(*pRear)->next = NewNode;
	*pRear = NewNode;
}

pLinkList CreateList()
{
	pLinkList NewList = new  LinkList;
	NewList->next = NULL;
	return NewList;
}

pLinkList CreateNode(char **data)
{
	pLinkList NewNode = new LinkList;
	NewNode->feild = data;
	NewNode->next = NULL;
	return NewNode;
}

char **GetArray(int n, int m)
{
	int i;
	char **p;

	p = new char*[n+2];
	for (i = 0; i < n+2; i++)
		p[i] = new char[m+2];

	return p;
}

void InputArray(char **p, int n, int m)
{
	int i, j;

	for (i = 1; i < n+1; i++)
		for (j = 1; j < m+1; j++)
			cin >> p[i][j];
}

void PrintArray(char **p, int n, int m)
{
	int i, j;
	int num = 0;
	cout << "Field #" << Times<< ":" <<endl;
	Times++;
	for (i = 1; i < n+1; i++)
	{
		for (j = 1; j < m+1; j++)
		{
			if (p[i][j] == '*') cout << "*";
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
				cout << num;
				num = 0;
			}
		}
		cout<<endl;
	}
}

void PrintList(pLinkList pHead, char **pField[], mn Index[])
{
	pHead = pHead->next;
	int i = 0;
	while (pHead)
	{
		PrintArray(pField[i], Index[i].n, Index[i].m);
		cout << endl;
		pHead = pHead->next;
		i++;
	}
}

void DestroyList(pLinkList pHead)
{
	pLinkList p;
	while (pHead)
	{
		p = pHead;
		pHead = pHead->next;
		delete p;
	}
}