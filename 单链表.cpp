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
	//����ͷ���
	pLinkList HeadNode = CreateList();
	//����ָ��ͷ����ָ�룬��ͷָ��
	pLinkList pHead = HeadNode;
	//����ָ��β����ָ��pRear
	pLinkList pRear = HeadNode;
	//β�巨
	InsertListTail(&pRear, 1);
	InsertListTail(&pRear, 2);
	InsertListTail(&pRear, 3);
	//ͷ�巨
	InsertListHead(HeadNode, 1);
	InsertListHead(HeadNode, 2);
	InsertListHead(HeadNode, 3);
	//���
	printf("��Ϊ%d\n", ListLength(pHead));
    //��ӡ
	PrintList(HeadNode);
	//ɾ��ָ��Ԫ��
	DeleteNode(HeadNode, 2);
	//���
	printf("ɾ�����Ϊ%d\n", ListLength(pHead));
	//��ӡ
	PrintList(HeadNode);
	//���ٵ�����
	DestroyList(pHead);
	return 0;
}

//����ͷ���
pLinkList CreateList()
{
	pLinkList HeadNode = (pLinkList)malloc(sizeof(LinkList));    //Ϊͷ��㿪���ڴ�

	HeadNode->next = NULL;        //ͷ������������Ҫ��ֵ��ֻ��Ҫ��ָ�����ÿռ���
	return HeadNode;
}

//�����½��
//����ָ������
pLinkList CreateNode(int data)
{
	pLinkList Node = (pLinkList)malloc(sizeof(LinkList));    //Ϊ�½�㿪���ڴ�

	Node->data = data;         //Ϊ�½���������ֵ
	Node->next = NULL;       //���½���ָ�����ÿ�
	return Node;
}

//�ж������Ƿ�Ϊ��
//���ж�ͷ�ڵ�ĺ�һ��Ԫ���Ƿ�Ϊ��
int IsEmpty(pLinkList HeadNode)
{
	if (HeadNode->next == NULL)
		return 1;
	else
		return 0;
}

//��ӡ
//������Ԫ�ؿ�ʼ��������
void PrintList(pLinkList HeadNode)
{
	if (IsEmpty(HeadNode))        //�����ж��Ƿ�Ϊ�յĺ��������򷵻�1
	{
		printf("����Ϊ�գ��޷���ӡ��\n");
		exit(0);
	}

	//pMoveΪ�ƶ���ָ��
	pLinkList pMove = HeadNode->next;
	while (pMove)
	{
		printf("%d -> ", pMove->data);
		pMove = pMove->next;           //��������
	}
	printf("NULL\n");
}

//��ͷ����
void InsertListHead(pLinkList HeadNode, int data)
{
	//����֮ǰ��������ڲ���Ľڵ�
	pLinkList NewNode = CreateNode(data);

	NewNode->next = HeadNode->next;    //�½���ָ���� ָ��������Ԫ��
	HeadNode->next = NewNode;           //ͷ����ָ���� ָ���½��
}

//ָ������ɾ��
void DeleteNode(pLinkList HeadNode, int PosData)    //PosDataΪĿ������
{
	pLinkList PosNode = HeadNode->next;        //PosNodeָ��������Ԫ��
	pLinkList PosNodeFront = HeadNode;           //PosNodeFrontָ��ͷ���
	if (PosNode == NULL)
		printf("�޷�ɾ��������\n");               //����Ԫ��ΪNULL��˵������Ϊ��
	else
	{
		while (PosNode->data != PosData)      //ѭ��������δ�ҵ�ָ������
		{
			PosNodeFront = PosNode;
			PosNode = PosNodeFront->next;

			if (PosNode == NULL)                //����β��δ�ҵ�Ŀ�����ݣ����������
			{
				printf("δ�ҵ�Ŀ�����ݣ�\n");
				return;
			}
		}

		PosNodeFront->next = PosNode->next;      //Ŀ�����ݽ���ǰһ�����ָ��Ŀ�����ݽ��ĺ�һ�����
		free(PosNode);                   //�ͷ�Ŀ�����ݽ����ڴ�
	}
}

//β�巨
void InsertListTail(pLinkList *pRear, int data)
{
	pLinkList NewNode = CreateNode(data);

	(*pRear)->next = NewNode;     //pRearָ��Ľ���ָ����ָ���½��
	*pRear = NewNode;        //pRearָ���½��
}

//���ٵ�����
void DestroyList(pLinkList pHead)
{
	pLinkList p;      //����pָ�������ͷ��ڴ�

	while (pHead)      //ѭ��������pHead != NULL
	{
		p = pHead;
		pHead = pHead->next;
		free(p);    //�ͷ�p���ڴ�
	}
}

//���
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

//��յ�����
void ClearList(pLinkList pHead)
{
	pLinkList p, q;
	p = pHead->next;     //��pָ����Ԫ���
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
}