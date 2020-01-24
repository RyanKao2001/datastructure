#include <iostream>

using namespace std;

typedef struct HT
{
	int weight;
	int parent;
	int Lchild;
	int Rchild;
}HuffmanTree,*pHuffmanTree;

typedef char HuffmanCode;
typedef char **ppHuffmanCode;

void Select(pHuffmanTree HT, int n, int &s1, int &s2);
void CreateHuffmanTree(pHuffmanTree &HT, int n);
void CreateHuffmanCode(pHuffmanTree HT, ppHuffmanCode &HC, int n);
void PrintHuffmanCode(pHuffmanTree HT, ppHuffmanCode HC);

int main()
{
	int n;
	cin >> n;
	pHuffmanTree HT;
	ppHuffmanCode HC;
	CreateHuffmanTree(HT, n);
	CreateHuffmanCode(HT, HC, n);
	PrintHuffmanCode(HT, HC);
	return 0;
}

void CreateHuffmanTree(pHuffmanTree &HT, int n)
{
	int m = 2 * n - 1;

	HT = new HuffmanTree[m+1];    // 0号节点不使用 
	for (int i = 1; i <= m; i++)
	{
		HT[i].parent = HT[i].Lchild = HT[i].Rchild = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> HT[i].weight;    // 输入权值 
	}
	HT[0].weight = m;    // 用0号节点保存节点
	//初始化完毕, 创建哈夫曼树
	for (int i = n + 1; i <= m; i++) {
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

void CreateHuffmanCode(pHuffmanTree HT, ppHuffmanCode &HC, int n)
{
	int i, start, c, f;
	HC = new char *[n + 1];
	char *cd = new char[n];
	cd[n - 1] = '\0';
	for (int i=1; i <= n; i++)
	{
		start = n - 1; 
		c = i;
		f = HT[i].parent;
		while (f != 0)
		{
			--start;
			if (HT[f].Lchild == c)
				cd[start] = '0';
			else
				cd[start] = '1';
			c = f;
			f = HT[f].parent;
		}
		HC[i] = new char[n - start];
		strcpy(HC[i], &cd[start]);
	}
	delete cd;
}

//打印哈夫曼编码
void PrintHuffmanCode(pHuffmanTree HT, ppHuffmanCode HC)
{
	for (int i = 1; i <= sizeof(HC) + 1; i++)
		cout << HT[i].weight << "编码为" << HC[i] << endl;
}