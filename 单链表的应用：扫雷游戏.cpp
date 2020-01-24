/*ժ��PTA��ɨ����Ϸ������Ϊ��Ŀ����*/

/*���ɨ���ε����Ѷ�֪��������Ϸ��Ŀ�����ҳ�һ��nm�����ڵ����еĵ��ף�
�ڱ����У�����ҪΪÿһ����Ԫ��ͳ�Ƴ�����Χ���׵ĸ�����ÿ����Ԫ�������
8�����ڵ�Ԫ������ͼ��44 �ĸ�����á�*����ʾ�ף��á�^�� ��ʾû���ס�
*^^^
^^^^
^*^^
^^^^
������������Ϊ��
*100
2210
1*10
1110

�����ʽ:

����������ɸ����󣬶���ÿһ�����󣬵�һ�а���������M��N���ֱ��ʾ�þ�
���������������0<N��M<100��,������N�а���M���ַ������Ǹþ�����
��*����ʾ���ף��á�^����ʾ�հס���N=M=0ʱ����ʾ���������ô�����С�

�����ʽ:

����ÿһ�����������ڵ���һ�д�ӡ��������ţ�Field #X: ����X�Ǿ���ı�ţ�
��1��ʼ��ţ�������N���У�����ġ�^���ø�λ����Χ�ĵ�����Ŀ�����棬���״�
�����á�*����ʾ��������ڵ���������֮�䣬��һ�С�

��������:

���������һ�����롣���磺
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
�������:

�����������Ӧ����������磺
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

/*���´�����˻���C++��д�������󣬽����ο�*/

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
	//����ͷ���
	pLinkList HeadNode = CreateList();
	//����ͷβָ��
	pLinkList pHead = HeadNode;
	pLinkList pRear = HeadNode;
	//��������
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
	//��ӡ����
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