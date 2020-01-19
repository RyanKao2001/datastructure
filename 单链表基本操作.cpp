#include <stdio.h>
#include <stdlib.h>

typedef struct SingleList
{
	int data;
	SingleList *next;
}List, *Lplist;

Lplist CreateList();
Lplist CreateNode(int data);
int IsEmpty(Lplist List);
void insertlisthead(Lplist list, int data);
void printlist(Lplist list);
void deletenode(Lplist HeadNode, int posdata);
void insertlisttail(Lplist *rear, int data);
void destroylist(Lplist pHead);
int listlength(Lplist pHead);
void clearlist(Lplist pHead);

int main()
{
	//生成头结点
	Lplist HeadNode = CreateList();
	//定义指向头结点的指针，即头指针
	Lplist pHead = HeadNode;
	//定义指向尾部的指针rear
	Lplist rear = HeadNode;
	//尾插法
	insertlisttail(&rear, 1);
	insertlisttail(&rear, 2);
	insertlisttail(&rear, 3);
	//头插法
	insertlisthead(HeadNode, 1);
	insertlisthead(HeadNode, 2);
	insertlisthead(HeadNode, 3);
	//求表长
	printf("表长为%d\n", listlength(pHead));
    //打印
	printlist(HeadNode);
	//删除指定元素
	deletenode(HeadNode, 2);
	//求表长
	printf("删除后表长为%d\n", listlength(pHead));
	//打印
	printlist(HeadNode);
	//清空单链表
	clearlist(pHead);
	//销毁单链表
	destroylist(pHead);
	return 0;
}

//创建头结点
Lplist CreateList()
{
	Lplist HeadNode = (Lplist)malloc(sizeof(List));    //为头结点开辟内存

	HeadNode->next = NULL;        //头结点的数据域不需要赋值，只需要将指针域置空即可
	return HeadNode;
}

//创建新结点
//传入指定数据
Lplist CreateNode(int data)
{
	Lplist Node = (Lplist)malloc(sizeof(List));    //为新结点开辟内存

	Node->data = data;         //为新结点的数据域赋值
	Node->next = NULL;       //将新结点的指针域置空
	return Node;
}

//判断链表是否为空
//即判断头节点的后一个元素是否为空
int IsEmpty(Lplist HeadNode)
{
	if (HeadNode->next == NULL)
		return 1;
	else
		return 0;
}

//打印
//即从首元素开始遍历链表
void printlist(Lplist HeadNode)
{
	if (IsEmpty(HeadNode))        //调用判断是否为空的函数，空则返回1
	{
		printf("链表为空，无法打印！\n");
		exit(0);
	}

	//pmove为移动的指针
	Lplist pmove = HeadNode->next;
	while (pmove)
	{
		printf("%d -> ", pmove->data);
		pmove = pmove->next;           //遍历链表
	}
	printf("NULL\n");
}

//表头插入
void insertlisthead(Lplist HeadNode, int data)
{
	//插入之前，必须存在插入的节点
	Lplist newnode = CreateNode(data);

	newnode->next = HeadNode->next;    //新结点的指针域 指向链表首元素
	HeadNode->next = newnode;           //头结点的指针域 指向新结点
}

//指定数据删除
void deletenode(Lplist HeadNode, int posdata)    //posdata为目标数据
{
	Lplist posnode = HeadNode->next;        //posnode指向链表首元素
	Lplist posnodefront = HeadNode;           //posnodefront指向头结点
	if (posnode == NULL)
		printf("无法删除空链表！\n");               //若首元素为NULL，说明链表为空
	else
	{
		while (posnode->data != posdata)      //循环条件：未找到指定数据
		{
			posnodefront = posnode;
			posnode = posnodefront->next;

			if (posnode == NULL)                //到表尾仍未找到目标数据，则结束函数
			{
				printf("未找到目标数据！\n");
				return;
			}
		}

		posnodefront->next = posnode->next;      //目标数据结点的前一个结点指向目标数据结点的后一个结点
		free(posnode);                   //释放目标数据结点的内存
	}
}

//尾插法
void insertlisttail(Lplist *rear, int data)
{
	Lplist newnode = CreateNode(data);

	(*rear)->next = newnode;     //temp指向的结点的指针域指向新结点
	*rear = newnode;        //temp指向新结点
	(*rear)->next = NULL;
}

//销毁单链表
void destroylist(Lplist pHead)
{
	Lplist p=NULL;      //定义p指针用于释放内存

	while (pHead)      //循环条件：pHead != NULL
	{
		p = pHead;      
		pHead = pHead->next;
		free(p);    //释放p的内存
	}
}

//求表长
int listlength(Lplist pHead)
{
	int i = 0;
	Lplist p=NULL;
	p = pHead->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

//清空单链表
void clearlist(Lplist pHead)
{
	Lplist p, q;
	p = pHead->next;     //令p指向首元结点
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
}
