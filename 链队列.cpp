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
	//����ͷ���
	pLinkQueue HeadNode = CreateQueue();
	//����pHeadָ��ָ���ͷ��pRearָ��ָ���β
	pLinkQueue pHead = HeadNode;
	pLinkQueue pRear = HeadNode;
	//���
	EnQueue(&pRear, 1);
	EnQueue(&pRear, 2);
	EnQueue(&pRear, 3);
	//��ӡ
	PrintQueue(pHead);
	//����
	printf("���ӣ�ȡ��Ԫ�أ�%d\n", DeQueue(&pHead, &pRear));
	//��ӡ
	PrintQueue(pHead);
	//ȡ��ͷԪ��
	printf("ȡ��ͷԪ�أ�", GetHead(pHead));
	//���ٶ���
	DestroyQueue(pHead);
	return 0;
}

//����ͷ���
pLinkQueue CreateQueue()
{
	pLinkQueue HeadNode = (pLinkQueue)malloc(sizeof(LinkQueue));
	HeadNode->next = NULL;
	return HeadNode;
}

//�������
pLinkQueue CreateNode(int data)
{
	pLinkQueue NewNode = (pLinkQueue)malloc(sizeof(LinkQueue));
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}

//�ж϶����Ƿ�Ϊ��
int IsEmpty(pLinkQueue pHead)
{
	if (pHead->next == NULL)
		return 1;
	else
		return 0;
}

//���
void EnQueue(pLinkQueue *pRear, int data)
{
	pLinkQueue NewNode = CreateNode(data);
	(*pRear)->next = NewNode;       //�����½��
	*pRear = NewNode;           //��βָ���Ƶ���β
}

//����
int DeQueue(pLinkQueue *pHead, pLinkQueue *pRear)
{
	pLinkQueue p = (*pHead)->next;
	int e = p->data;
	(*pHead)->next = p->next;
	//������Ԫ���ڱ�β����Ҫ��βָ��ָ��ͷ���
	if (*pRear == p)
		*pRear = *pHead;
	free(p);
	return e;
}

//ȡ��ͷԪ��
int GetHead(pLinkQueue pHead)
{
	return pHead->data;
}

//��ӡ����
void PrintQueue(pLinkQueue pHead)
{
	if (IsEmpty(pHead))
	{
		printf("����Ϊ�գ��޷���ӡ��\n");
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