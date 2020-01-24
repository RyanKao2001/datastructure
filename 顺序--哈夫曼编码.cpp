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

	HT = new HuffmanTree[m+1];    // 0�Žڵ㲻ʹ�� 
	for (int i = 1; i <= m; i++)
	{
		HT[i].parent = HT[i].Lchild = HT[i].Rchild = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> HT[i].weight;    // ����Ȩֵ 
	}
	HT[0].weight = m;    // ��0�Žڵ㱣��ڵ�
	//��ʼ�����, ������������
	for (int i = n + 1; i <= m; i++) {
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

//��ӡ����������
void PrintHuffmanCode(pHuffmanTree HT, ppHuffmanCode HC)
{
	for (int i = 1; i <= sizeof(HC) + 1; i++)
		cout << HT[i].weight << "����Ϊ" << HC[i] << endl;
}