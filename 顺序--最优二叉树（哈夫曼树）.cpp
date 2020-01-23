#include <stdio.h>
#include <stdlib.h>

//哈夫曼树的存储表示
typedef struct
{
	int weigHT;    // 权值
	int parent, lChild, rChild;    // 双亲及左右孩子的下标 
}HuffmanTree, *pHuffmanTree;

void CreateHuffmanTree(pHuffmanTree &HT, int n);
void SelectMin(pHuffmanTree HT, int n, int &s1, int &s2);
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
	for (int i = 1; i <= m; ++i) {
		HT[i].parent = HT[i].lChild = HT[i].rChild = 0;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &HT[i].weigHT);    // 输入权值 
	}
	HT[0].weigHT = m;    // 用0号节点保存节点数量
						 //初始化完毕, 创建哈夫曼树
	for (int i = n + 1; i <= m; ++i) {
		int s1, s2;
		SelectMin(HT, i, s1, s2);
		HT[s1].parent = HT[s2].parent = i;
		HT[i].lChild = s1; HT[i].rChild = s2;    // 作为新节点的孩子 
		HT[i].weigHT = HT[s1].weigHT + HT[s2].weigHT;    // 新节点为左右孩子节点权值之和 
	}
}

// 选择权值最小的两颗树 
void SelectMin(pHuffmanTree HT, int n, int &s1, int &s2)
{
	s1 = s2 = 0;

	int i;
	for (i = 1; i < n; ++i) {
		if (0 == HT[i].parent) {
			if (0 == s1) {
				s1 = i;
			}
			else {
				s2 = i;
				break;
			}
		}
	}
	if (HT[s1].weigHT > HT[s2].weigHT) {
		int t = s1;
		s1 = s2;
		s2 = t;
	}

	for (i += 1; i < n; ++i) {
		if (0 == HT[i].parent) {
			if (HT[i].weigHT < HT[s1].weigHT) {
				s2 = s1;
				s1 = i;
			}
			else if (HT[i].weigHT < HT[s2].weigHT) {
				s2 = i;
			}
		}
	}
}

// 构造有n个权值（叶子节点）的哈夫曼树 
int HuffmanTreeWPL_(pHuffmanTree HT, int i, int deepth)
{
	if (HT[i].lChild == 0 && HT[i].rChild == 0) {
		return HT[i].weigHT * deepth;
	}
	else {
		return HuffmanTreeWPL_(HT, HT[i].lChild, deepth + 1) + HuffmanTreeWPL_(HT, HT[i].rChild, deepth + 1);
	}
}

// 计算WPL（带权路径长度） 
int HuffmanTreeWPL(pHuffmanTree HT)
{
	return HuffmanTreeWPL_(HT, HT[0].weigHT, 0);
}

void PrintTree(pHuffmanTree HT, int m)
{
	printf("Index weigHT parent lChild rChild\n");
	for (int i = 1; i <= m; i++)
		printf("%-5d %-6d %-6d %-6d %-6d\n", 
			i, HT[i].weigHT, HT[i].parent, HT[i].lChild, HT[i].rChild);
	printf("WPL = %d\n", HuffmanTreeWPL(HT));
}

// 销毁哈夫曼树 
void DestroyHuffmanTree(pHuffmanTree &HT)
{
	free(HT);
	HT = NULL;
}