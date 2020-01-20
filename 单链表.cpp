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
void insertlisthead(pLinkList list, int data);
void printlist(pLinkList list);
void deletenode(pLinkList HeadNode, int posdata);
void insertlisttail(pLinkList *rear, int data);
void destroylist(pLinkList pHead);
int listlength(pLinkList pHead);
void clearlist(pLinkList pHead);

int main()
{
	//����ͷ���
	pLinkList HeadNode = CreateList();
	//����ָ��ͷ����ָ�룬��ͷָ��
	pLinkList pHead = HeadNode;
	//����ָ��β����ָ��rear
	pLinkList rear = HeadNode;
	//β�巨
	insertlisttail(&rear, 1);
	insertlisttail(&rear, 2);
	insertlisttail(&rear, 3);
	//ͷ�巨
	insertlisthead(HeadNode, 1);
	insertlisthead(HeadNode, 2);
	insertlisthead(HeadNode, 3);
	//���
	printf("��Ϊ%d\n", listlength(pHead));
    //��ӡ
	printlist(HeadNode);
	//ɾ��ָ��Ԫ��
	deletenode(HeadNode, 2);
	//���
	printf("ɾ�����Ϊ%d\n", listlength(pHead));
	//��ӡ
	printlist(HeadNode);
	//���ٵ�����
	destroylist(pHead);
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
void printlist(pLinkList HeadNode)
{
	if (IsEmpty(HeadNode))        //�����ж��Ƿ�Ϊ�յĺ��������򷵻�1
	{
		printf("����Ϊ�գ��޷���ӡ��\n");
		exit(0);
	}

	//pmoveΪ�ƶ���ָ��
	pLinkList pmove = HeadNode->next;
	while (pmove)
	{
		printf("%d -> ", pmove->data);
		pmove = pmove->next;           //��������
	}
	printf("NULL\n");
}

//��ͷ����
void insertlisthead(pLinkList HeadNode, int data)
{
	//����֮ǰ��������ڲ���Ľڵ�
	pLinkList newnode = CreateNode(data);

	newnode->next = HeadNode->next;    //�½���ָ���� ָ��������Ԫ��
	HeadNode->next = newnode;           //ͷ����ָ���� ָ���½��
}

//ָ������ɾ��
void deletenode(pLinkList HeadNode, int posdata)    //posdataΪĿ������
{
	pLinkList posnode = HeadNode->next;        //posnodeָ��������Ԫ��
	pLinkList posnodefront = HeadNode;           //posnodefrontָ��ͷ���
	if (posnode == NULL)
		printf("�޷�ɾ��������\n");               //����Ԫ��ΪNULL��˵������Ϊ��
	else
	{
		while (posnode->data != posdata)      //ѭ��������δ�ҵ�ָ������
		{
			posnodefront = posnode;
			posnode = posnodefront->next;

			if (posnode == NULL)                //����β��δ�ҵ�Ŀ�����ݣ����������
			{
				printf("δ�ҵ�Ŀ�����ݣ�\n");
				return;
			}
		}

		posnodefront->next = posnode->next;      //Ŀ�����ݽ���ǰһ�����ָ��Ŀ�����ݽ��ĺ�һ�����
		free(posnode);                   //�ͷ�Ŀ�����ݽ����ڴ�
	}
}

//β�巨
void insertlisttail(pLinkList *rear, int data)
{
	pLinkList newnode = CreateNode(data);

	(*rear)->next = newnode;     //tempָ��Ľ���ָ����ָ���½��
	*rear = newnode;        //tempָ���½��
	(*rear)->next = NULL;
}

//���ٵ�����
void destroylist(pLinkList pHead)
{
	pLinkList p=NULL;      //����pָ�������ͷ��ڴ�

	while (pHead)      //ѭ��������pHead != NULL
	{
		p = pHead;
		pHead = pHead->next;
		free(p);    //�ͷ�p���ڴ�
	}
}

//���
int listlength(pLinkList pHead)
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
void clearlist(pLinkList pHead)
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