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
	//���ƶ�����
	printf("-----------------------\n");
	printf("  ���ڸ��ƶ�����......\n");
	printf("-----------------------\n");
	pBiTree Root2 = NULL;
	CopyTree(pRoot, Root2);
	//����ָ��ָ��������
	pBiTree pRoot2 = Root2;
	//�����������
	printf("�������������\n");
	PreOrderTraverse(pRoot2);
	printf("END\n");
	//������
	printf("�������Ϊ��%d\n", Depth(pRoot2));
	//�����Ľ������
	printf("���Ľ������Ϊ��%d\n", NodeCount(pRoot2));
	printf("����Ҷ�ӽ������Ϊ��%d\n", LeafCount(pRoot2));
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

//���ƶ�����
void CopyTree(pBiTree pRoot,pBiTree &Root2)     //C++�﷨������ַ����
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

//������������
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

//����������ڵ�����
int NodeCount(pBiTree pRoot2)
{
	if (pRoot2 == NULL) return 0;
	else
		return NodeCount(pRoot2->Lchild) + NodeCount(pRoot2->Rchild) + 1;
}

//����Ҷ�ӽ������
int LeafCount(pBiTree pRoot2)
{
	if (pRoot2 == NULL) return 0;
	if (pRoot2->Lchild == NULL && pRoot2->Rchild == NULL)
		return 1;
	else
		return LeafCount(pRoot2->Lchild) + LeafCount(pRoot2->Rchild);
}