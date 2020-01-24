#include <stdio.h>
#include <stdlib.h>

//���������Ĵ洢��ʾ
typedef struct
{
	int weight;    // Ȩֵ
	int parent;
	int Lchild;
	int Rchild;    // ˫�׼����Һ��ӵ��±� 
}HuffmanTree, *pHuffmanTree;

void CreateHuffmanTree(pHuffmanTree &HT, int n);
void Select(pHuffmanTree HT, int n, int &s1, int &s2);
int HuffmanTreeWPL(pHuffmanTree HT);
int HuffmanTreeWPL_(pHuffmanTree HT, int i, int deepth);
void PrintTree(pHuffmanTree HT, int m);
void DestroyHuffmanTree(pHuffmanTree &HT);

int main()
{
	pHuffmanTree HT;
	int n;
	scanf("%d", &n);
	CreateHuffmanTree(HT, n);
	PrintTree(HT, 2 * n - 1);
	DestroyHuffmanTree(HT);
	return 0;
}

void CreateHuffmanTree(pHuffmanTree &HT, int n)
{
	int m = 2 * n - 1;

	HT = (pHuffmanTree)malloc(sizeof(HuffmanTree)*(m + 1));    // 0�Žڵ㲻ʹ�� 
	for (int i = 1; i <= m; i++) 
	{
		HT[i].parent = HT[i].Lchild = HT[i].Rchild = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &HT[i].weight);    // ����Ȩֵ 
	}
	HT[0].weight = m;    // ��0�Žڵ㱣��ڵ�����
	//��ʼ�����, ������������
	for (int i = n + 1; i <= m; i++)
	{
		int s1, s2;
		Select(HT, i, s1, s2);
		HT[s1].parent = HT[s2].parent = i;
		HT[i].Lchild = s1; HT[i].Rchild = s2;    // ��Ϊ�½ڵ�ĺ��� 
		HT[i].weight = HT[s1].weight + HT[s2].weight;    // �½ڵ�Ϊ���Һ��ӽڵ�Ȩֵ֮�� 
	}
}

// ѡ��Ȩֵ��С�������� 
void Select(pHuffmanTree HT, int len, int &s1, int &s2)
{
	// �ȸ������ֵ	
	int i;
	int min1 = 0x3f3f3f3f;
	int min2 = 0x3f3f3f3f;

	for (i = 1; i < len; i++)	
	{	
		if (HT[i].weight<min1 && HT[i].parent == 0)		
		{			
			min1 = HT[i].weight;		
			s1 = i;	
		}
	}	
	// ��ԭֵ���������Ȼ���ȸ������ֵ����ֹs1���ظ�ѡ��	
	int temp = HT[s1].weight; 
	HT[s1].weight = 0x3f3f3f3f;
	for (i = 1; i < len; i++)	
	{	
		if (HT[i].weight<min2 && HT[i].parent == 0)	
		{			
			min2 = HT[i].weight;			
			s2 = i;	
		}	
	}
	// �ָ�ԭ����ֵ
	HT[s1].weight = temp;
}

// ������n��Ȩֵ��Ҷ�ӽڵ㣩�Ĺ������� 
int HuffmanTreeWPL_(pHuffmanTree HT, int i, int deepth)
{
	if (HT[i].Lchild == 0 && HT[i].Rchild == 0) {
		return HT[i].weight * deepth;
	}
	else {
		return HuffmanTreeWPL_(HT, HT[i].Lchild, deepth + 1) + HuffmanTreeWPL_(HT, HT[i].Rchild, deepth + 1);
	}
}

// ����WPL����Ȩ·�����ȣ� 
int HuffmanTreeWPL(pHuffmanTree HT)
{
	return HuffmanTreeWPL_(HT, HT[0].weight, 0);
}

void PrintTree(pHuffmanTree HT, int m)
{
	printf("Index weigHT parent Lchild Rchild\n");
	for (int i = 1; i <= m; i++)
		printf("%-5d %-6d %-6d %-6d %-6d\n", 
			i, HT[i].weight, HT[i].parent, HT[i].Lchild, HT[i].Rchild);
	printf("WPL = %d\n", HuffmanTreeWPL(HT));
}

// ���ٹ������� 
void DestroyHuffmanTree(pHuffmanTree &HT)
{
	free(HT);
	HT = NULL;
}