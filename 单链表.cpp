#include <stdio.h>
#include <stdlib.h>

typedef struct SingleList
{
	int data;
	SingleList *next;
}LinkList, *pLinkList;

pLinkList CreateList();
pLinkList CreateNode(int data);
int IsEmpty(pLinkList List);
void InsertListHead(pLinkList list, int data);
void PrintList(pLinkList list);
void DeleteNode(pLinkList HeadNode, int PosData);
void InsertListTail(pLinkList *pRear, int data);
void DestroyList(pLinkList pHead);
int ListLength(pLinkList pHead);
void ClearList(pLinkList pHead);

int main()
{
	//生成头结点
	pLinkList HeadNode = CreateList();
	//定义指向头结点的指针，即头指针
	pLinkList pHead = HeadNode;
	//定义指向尾部的指针pRear
	pLinkList pRear = HeadNode;
	//尾插法
	InsertListTail(&pRear, 1);
	InsertListTail(&pRear, 2);
	InsertListTail(&pRear, 3);
	//头插法
	InsertListHead(HeadNode, 1);
	InsertListHead(HeadNode, 2);
	InsertListHead(HeadNode, 3);
	//求表长
	printf("表长为%d\n", ListLength(pHead));
    //打印
	PrintList(HeadNode);
	//删除指定元素
	DeleteNode(HeadNode, 2);
	//求表长
	printf("删除后表长为%d\n", ListLength(pHead));
	//打印
	PrintList(HeadNode);
	//销毁单链表
	DestroyList(pHead);
	return 0;
}

//创建头结点
pLinkList CreateList()
{
	pLinkList HeadNode = (pLinkList)malloc(sizeof(LinkList));    //为头结点开辟内存

	HeadNode->next = NULL;        //头结点的数据域不需要赋值，只需要将指针域置空即可
	return HeadNode;
}

//创建新结点
//传入指定数据
pLinkList CreateNode(int data)
{
	pLinkList Node = (pLinkList)malloc(sizeof(LinkList));    //为新结点开辟内存

	Node->data = data;         //为新结点的数据域赋值
	Node->next = NULL;       //将新结点的指针域置空
	return Node;
}

//判断链表是否为空
//即判断头节点的后一个元素是否为空
int IsEmpty(pLinkList HeadNode)
{
	if (HeadNode->next == NULL)
		return 1;
	else
		return 0;
}

//打印
//即从首元素开始遍历链表
void PrintList(pLinkList HeadNode)
{
	if (IsEmpty(HeadNode))        //调用判断是否为空的函数，空则返回1
	{
		printf("链表为空，无法打印！\n");
		exit(0);
	}

	//pMove为移动的指针
	pLinkList pMove = HeadNode->next;
	while (pMove)
	{
		printf("%d -> ", pMove->data);
		pMove = pMove->next;           //遍历链表
	}
	printf("NULL\n");
}

//表头插入
void InsertListHead(pLinkList HeadNode, int data)
{
	//插入之前，必须存在插入的节点
	pLinkList NewNode = CreateNode(data);

	NewNode->next = HeadNode->next;    //新结点的指针域 指向链表首元素
	HeadNode->next = NewNode;           //头结点的指针域 指向新结点
}

//指定数据删除
void DeleteNode(pLinkList HeadNode, int PosData)    //PosData为目标数据
{
	pLinkList PosNode = HeadNode->next;        //PosNode指向链表首元素
	pLinkList PosNodeFront = HeadNode;           //PosNodeFront指向头结点
	if (PosNode == NULL)
		printf("无法删除空链表！\n");               //若首元素为NULL，说明链表为空
	else
	{
		while (PosNode->data != PosData)      //循环条件：未找到指定数据
		{
			PosNodeFront = PosNode;
			PosNode = PosNodeFront->next;

			if (PosNode == NULL)                //到表尾仍未找到目标数据，则结束函数
			{
				printf("未找到目标数据！\n");
				return;
			}
		}

		PosNodeFront->next = PosNode->next;      //目标数据结点的前一个结点指向目标数据结点的后一个结点
		free(PosNode);                   //释放目标数据结点的内存
	}
}

//尾插法
void InsertListTail(pLinkList *pRear, int data)
{
	pLinkList NewNode = CreateNode(data);

	(*pRear)->next = NewNode;     //pRear指向的结点的指针域指向新结点
	*pRear = NewNode;        //pRear指向新结点
}

//销毁单链表
void DestroyList(pLinkList pHead)
{
	pLinkList p;      //定义p指针用于释放内存

	while (pHead)      //循环条件：pHead != NULL
	{
		p = pHead;
		pHead = pHead->next;
		free(p);    //释放p的内存
	}
}

//求表长
int ListLength(pLinkList pHead)
{
	int i = 0;
	pLinkList p=NULL;
	p = pHead->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

//清空单链表
void ClearList(pLinkList pHead)
{
	pLinkList p, q;
	p = pHead->next;     //令p指向首元结点
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
}