#include <stdio.h>
#include <stdlib.h>

//哈夫曼树的存储表示
typedef struct
{
	int weight;    // 权值
	int parent;
	int Lchild;
	int Rchild;    // 双亲及左右孩子的下标 
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

	HT = (pHuffmanTree)malloc(sizeof(HuffmanTree)*(m + 1));    // 0号节点不使用 
	for (int i = 1; i <= m; i++) 
	{
		HT[i].parent = HT[i].Lchild = HT[i].Rchild = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &HT[i].weight);    // 输入权值 
	}
	HT[0].weight = m;    // 用0号节点保存节点数量
	//初始化完毕, 创建哈夫曼树
	for (int i = n + 1; i <= m; i++)
	{
		int s1, s2;
		Select(HT, i, s1, s2);
		HT[s1].parent = HT[s2].parent = i;
		HT[i].Lchild = s1; HT[i].Rchild = s2;    // 作为新节点的孩子 
		HT[i].weight = HT[s1].weight + HT[s2].weight;    // 新节点为左右孩子节点权值之和 
	}
}

// 选择权值最小的两颗树 
void Select(pHuffmanTree HT, int len, int &s1, int &s2)
{
	// 先赋予最大值	
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
	// 将原值存放起来，然后先赋予最大值，防止s1被重复选择	
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
	// 恢复原来的值
	HT[s1].weight = temp;
}

// 构造有n个权值（叶子节点）的哈夫曼树 
int HuffmanTreeWPL_(pHuffmanTree HT, int i, int deepth)
{
	if (HT[i].Lchild == 0 && HT[i].Rchild == 0) {
		return HT[i].weight * deepth;
	}
	else {
		return HuffmanTreeWPL_(HT, HT[i].Lchild, deepth + 1) + HuffmanTreeWPL_(HT, HT[i].Rchild, deepth + 1);
	}
}

// 计算WPL（带权路径长度） 
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

// 销毁哈夫曼树 
void DestroyHuffmanTree(pHuffmanTree &HT)
{
	free(HT);
	HT = NULL;
}