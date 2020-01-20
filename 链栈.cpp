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
	//创建首结点
	pLinkStack Head = CreateNode(3);
	//定义top指针指向栈顶
	pLinkStack top = Head;
	//入栈
	Push(&top, 2);
	Push(&top, 1);
	//打印
	PrintStack(top);
	//出栈
	printf("出栈，取出元素：%d\n", Pop(&top));
	//打印
	PrintStack(top);
	//取栈顶元素
	printf("取栈顶元素：%d\n", GetTop(top));
	//销毁链栈
	DestoryStack(top);
	return 0;
}

//创建结点
pLinkStack CreateNode(int data)
{
	//为新结点开辟内存
	pLinkStack NewNode = (pLinkStack)malloc(sizeof(LinkStack));
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}

//入栈
void Push(pLinkStack *top, int data)
{
	pLinkStack NewNode = CreateNode(data);
	pLinkStack p = NewNode;       //定义p指针指向新结点
	p->next = *top;
	*top = NewNode;                   //修改top指针的指向
}

//出栈
int Pop(pLinkStack *top)           //pLinkStack *top即LinkStack **top，指向top指针的指针，用于修改top的指向
{
	if (IsEmpty(*top))
	{
		printf("链栈为空，无法出栈！\n");
		exit(0);
	}
	int e = (*top)->data;        // -> 级别比 * 高，需要加( )
	pLinkStack p = *top;
	*top = (*top)->next;
	free(p);
	return e;
}

//取栈顶元素
int GetTop(pLinkStack top)
{
	return top->data;
}

//判断是否为空栈
int IsEmpty(pLinkStack top)
{
	if (top->next == NULL)
		return 1;
	else
		return 0;
}

//打印链栈
void PrintStack(pLinkStack top)
{
	if (IsEmpty(top))                //打印之前判断链栈是否为空
	{
		printf("链栈为空，无法打印！\n");
		exit(0);
	}
	else
	{
		pLinkStack pmove = top;     //pmove指针用于遍历链栈
		printf("top -> ");
		while (pmove)
		{
			printf("%d -> ", pmove->data);
			pmove = pmove->next;
		}
		printf("NULL\n");
	}
}

//销毁链栈
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