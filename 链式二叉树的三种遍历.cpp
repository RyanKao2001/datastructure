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
	//创建二叉树
	pBiTree Root = CreateNode('A');
	//定义指向根结点的指针
	
	pBiTree pRoot = Root;
	//创建相互独立的结点
	pBiTree Node2 = CreateNode('B');
	pBiTree Node3 = CreateNode('C');
	pBiTree Node5 = CreateNode('D');
	//连接结点
	Root->Lchild = Node2;
	Root->Rchild = Node3;
	Node2->Rchild = Node5;
	//先序遍历
	printf("先序遍历：\n");
	PreOrderTraverse(pRoot);
	printf("END\n");
	//中序遍历
	printf("中序遍历：\n");
	InOrderTraverse(pRoot);
	printf("END\n");
	//后序遍历
	printf("后序遍历:\n");
	PostOrderTraverse(pRoot);
	printf("END\n");
	return 0;
}

//创建结点
pBiTree CreateNode(char data)
{
	pBiTree NewNode = (pBiTree)malloc(sizeof(BiTree));
	NewNode->data = data;
	NewNode->Lchild = NULL;
	NewNode->Rchild = NULL;
	return NewNode;
}

//先序遍历
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

//中序遍历
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

//后序遍历
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