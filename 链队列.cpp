#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
	int data;
	struct Queue *next;
}LinkQueue, *pLinkQueue;

pLinkQueue CreateQueue();
pLinkQueue CreateNode(int data);
void EnQueue(pLinkQueue *pRear, int data);
int DeQueue(pLinkQueue *pHead, pLinkQueue *pRear);
int GetHead(pLinkQueue pHead);
void PrintQueue(pLinkQueue pHead);
int IsEmpty(pLinkQueue pHead);
void DestroyQueue(pLinkQueue pHead);

int main()
{
	//创建头结点
	pLinkQueue HeadNode = CreateQueue();
	//定义pHead指针指向队头，pRear指针指向队尾
	pLinkQueue pHead = HeadNode;
	pLinkQueue pRear = HeadNode;
	//入队
	EnQueue(&pRear, 1);
	EnQueue(&pRear, 2);
	EnQueue(&pRear, 3);
	//打印
	PrintQueue(pHead);
	//出队
	printf("出队，取出元素：%d\n", DeQueue(&pHead, &pRear));
	//打印
	PrintQueue(pHead);
	//取队头元素
	printf("取队头元素：", GetHead(pHead));
	//销毁队列
	DestroyQueue(pHead);
	return 0;
}

//创建头结点
pLinkQueue CreateQueue()
{
	pLinkQueue HeadNode = (pLinkQueue)malloc(sizeof(LinkQueue));
	HeadNode->next = NULL;
	return HeadNode;
}

//创建结点
pLinkQueue CreateNode(int data)
{
	pLinkQueue NewNode = (pLinkQueue)malloc(sizeof(LinkQueue));
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}

//判断队列是否为空
int IsEmpty(pLinkQueue pHead)
{
	if (pHead->next == NULL)
		return 1;
	else
		return 0;
}

//入队
void EnQueue(pLinkQueue *pRear, int data)
{
	pLinkQueue NewNode = CreateNode(data);
	(*pRear)->next = NewNode;       //连接新结点
	*pRear = NewNode;           //将尾指针移到表尾
}

//出队
int DeQueue(pLinkQueue *pHead, pLinkQueue *pRear)
{
	pLinkQueue p = (*pHead)->next;
	int e = p->data;
	(*pHead)->next = p->next;
	//若出队元素在表尾，需要将尾指针指向头结点
	if (*pRear == p)
		*pRear = *pHead;
	free(p);
	return e;
}

//取队头元素
int GetHead(pLinkQueue pHead)
{
	return pHead->data;
}

//打印队列
void PrintQueue(pLinkQueue pHead)
{
	if (IsEmpty(pHead))
	{
		printf("队列为空，无法打印！\n");
		exit(0);
	}
	else
	{
		pLinkQueue pMove = pHead->next;
		printf("Head -> ");
		while (pMove)
		{
			printf("%d -> ", pMove->data);
			pMove = pMove->next;
		}
		printf("Rear\n");
	}
}

void DestroyQueue(pLinkQueue pHead)
{
	pLinkQueue p;
	while (pHead)
	{
		p = pHead;
		pHead = pHead->next;
		free(p);
	}
}