#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	int data;
	struct stack *next;
}LinkStack, *pLinkStack;

pLinkStack CreateNode(int data);
void Push(pLinkStack *top, int data);
void PrintStack(pLinkStack top);
int IsEmpty(pLinkStack top);
int Pop(pLinkStack *top);
int GetTop(pLinkStack top);
void DestoryStack(pLinkStack);

int main()
{
	//�����׽��
	pLinkStack Head = CreateNode(3);
	//����topָ��ָ��ջ��
	pLinkStack top = Head;
	//��ջ
	Push(&top, 2);
	Push(&top, 1);
	//��ӡ
	PrintStack(top);
	//��ջ
	printf("��ջ��ȡ��Ԫ�أ�%d\n", Pop(&top));
	//��ӡ
	PrintStack(top);
	//ȡջ��Ԫ��
	printf("ȡջ��Ԫ�أ�%d\n", GetTop(top));
	//������ջ
	DestoryStack(top);
	return 0;
}

//�������
pLinkStack CreateNode(int data)
{
	//Ϊ�½�㿪���ڴ�
	pLinkStack NewNode = (pLinkStack)malloc(sizeof(LinkStack));
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}

//��ջ
void Push(pLinkStack *top, int data)
{
	pLinkStack NewNode = CreateNode(data);
	pLinkStack p = NewNode;       //����pָ��ָ���½��
	p->next = *top;
	*top = NewNode;                   //�޸�topָ���ָ��
}

//��ջ
int Pop(pLinkStack *top)           //pLinkStack *top��LinkStack **top��ָ��topָ���ָ�룬�����޸�top��ָ��
{
	if (IsEmpty(*top))
	{
		printf("��ջΪ�գ��޷���ջ��\n");
		exit(0);
	}
	int e = (*top)->data;        // -> ����� * �ߣ���Ҫ��( )
	pLinkStack p = *top;
	*top = (*top)->next;
	free(p);
	return e;
}

//ȡջ��Ԫ��
int GetTop(pLinkStack top)
{
	return top->data;
}

//�ж��Ƿ�Ϊ��ջ
int IsEmpty(pLinkStack top)
{
	if (top->next == NULL)
		return 1;
	else
		return 0;
}

//��ӡ��ջ
void PrintStack(pLinkStack top)
{
	if (IsEmpty(top))                //��ӡ֮ǰ�ж���ջ�Ƿ�Ϊ��
	{
		printf("��ջΪ�գ��޷���ӡ��\n");
		exit(0);
	}
	else
	{
		pLinkStack pmove = top;     //pmoveָ�����ڱ�����ջ
		printf("top -> ");
		while (pmove)
		{
			printf("%d -> ", pmove->data);
			pmove = pmove->next;
		}
		printf("NULL\n");
	}
}

//������ջ
void DestoryStack(pLinkStack top)
{
	pLinkStack p;
	while (top)
	{
		p = top;
		top = top->next;
		free(p);
	}
}