#include <stdio.h>
#include <stdlib.h>

typedef struct LinkBiTree
{
	int data;
	struct LinkBiTree *Lchild;
	struct LinkBiTree *Rchild;
}BiTree, *pBiTree;

pBiTree CreateNode(char data);
void PreOrderTraverse(pBiTree pRoot);
void InOrderTraverse(pBiTree pRoot);
void PostOrderTraverse(pBiTree pRoot);

int main()
{
	//����������
	pBiTree Root = CreateNode('A');
	//����ָ�������ָ��
	
	pBiTree pRoot = Root;
	//�����໥�����Ľ��
	pBiTree Node2 = CreateNode('B');
	pBiTree Node3 = CreateNode('C');
	pBiTree Node5 = CreateNode('D');
	//���ӽ��
	Root->Lchild = Node2;
	Root->Rchild = Node3;
	Node2->Rchild = Node5;
	//�������
	printf("���������\n");
	PreOrderTraverse(pRoot);
	printf("END\n");
	//�������
	printf("���������\n");
	InOrderTraverse(pRoot);
	printf("END\n");
	//�������
	printf("�������:\n");
	PostOrderTraverse(pRoot);
	printf("END\n");
	return 0;
}

//�������
pBiTree CreateNode(char data)
{
	pBiTree NewNode = (pBiTree)malloc(sizeof(BiTree));
	NewNode->data = data;
	NewNode->Lchild = NULL;
	NewNode->Rchild = NULL;
	return NewNode;
}

//�������
void PreOrderTraverse(pBiTree pRoot)
{
	if (pRoot == NULL) return;
	else
	{
		printf("%c -> ", pRoot->data);
		PreOrderTraverse(pRoot->Lchild);
		PreOrderTraverse(pRoot->Rchild);
	}
}

//�������
void InOrderTraverse(pBiTree pRoot)
{
	if (pRoot == NULL) return;
	else
	{
		InOrderTraverse(pRoot->Lchild);
		printf("%c -> ", pRoot->data);
		InOrderTraverse(pRoot->Rchild);
	}
}

//�������
void PostOrderTraverse(pBiTree pRoot)
{
	if (pRoot == NULL) return;
	else
	{
		PostOrderTraverse(pRoot->Lchild);
		PostOrderTraverse(pRoot->Rchild);
		printf("%c -> ",pRoot->data);
	}
}