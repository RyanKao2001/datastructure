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
void CopyTree(pBiTree pRoot, pBiTree &Root);
int Depth(pBiTree pRoot2);
int NodeCount(pBiTree pRoot2);
int LeafCount(pBiTree pRoot2);

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
	//复制二叉树
	printf("-----------------------\n");
	printf("  正在复制二叉树......\n");
	printf("-----------------------\n");
	pBiTree Root2 = NULL;
	CopyTree(pRoot, Root2);
	//定义指针指向新树根
	pBiTree pRoot2 = Root2;
	//先序遍历新树
	printf("先序遍历新树：\n");
	PreOrderTraverse(pRoot2);
	printf("END\n");
	//求树深
	printf("树的深度为：%d\n", Depth(pRoot2));
	//求树的结点总数
	printf("树的结点总数为：%d\n", NodeCount(pRoot2));
	printf("树的叶子结点总数为：%d\n", LeafCount(pRoot2));
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

//复制二叉树
void CopyTree(pBiTree pRoot,pBiTree &Root2)     //C++语法，传地址运算
{
	if (pRoot == NULL)
	{
		Root2 = NULL;
		return;
	}
	else
	{
		Root2 = CreateNode(pRoot->data);
		CopyTree(pRoot->Lchild,Root2->Lchild);
		CopyTree(pRoot->Rchild,Root2->Rchild);
	}
}

//计算二叉树深度
int Depth(pBiTree pRoot2)
{
	int m=0, n=0;
	if (pRoot2 == NULL) return 0;
	else
	{
		m = Depth(pRoot2->Lchild);
		n = Depth(pRoot2->Rchild);
		if (m > n) return m + 1;
		else return n + 1;
	}
}

//计算二叉树节点总数
int NodeCount(pBiTree pRoot2)
{
	if (pRoot2 == NULL) return 0;
	else
		return NodeCount(pRoot2->Lchild) + NodeCount(pRoot2->Rchild) + 1;
}

//计算叶子结点总数
int LeafCount(pBiTree pRoot2)
{
	if (pRoot2 == NULL) return 0;
	if (pRoot2->Lchild == NULL && pRoot2->Rchild == NULL)
		return 1;
	else
		return LeafCount(pRoot2->Lchild) + LeafCount(pRoot2->Rchild);
}