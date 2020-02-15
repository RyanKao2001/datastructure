#include <iostream>
#define MAXSIZE 25
#define KEY 7        //除留取余，最好选择质数

using namespace std;

//用链地址法防止冲突
typedef struct link {
	int data;
	link* next;
}hash_arr, * p_hash_arr, link, * p_link;

//存放数据的数组，可由用户输入
int data_arr[MAXSIZE] = { 0 };

void input_data_arr();
p_hash_arr create_hash_arr();
p_link create_link(int data);
void insert_hash(p_hash_arr hash_arr, int data);
bool search_hash(p_hash_arr hash_arr, int tar_data);

int main() {
	int tar_data;
	input_data_arr();
	cout << "默认数据初始化完毕..." << endl;
	p_hash_arr hash_arr = create_hash_arr();
	for (int i = 0; i < MAXSIZE; i++) {
		insert_hash(hash_arr, data_arr[i]);
	}
	cout << "哈希表建立完成！" << endl;
	cout << "请输入查找的目标值：";
	cin >> tar_data;
	if (search_hash(hash_arr, tar_data)) {
		cout << "查找成功！目标值 \"" << tar_data << "\" 存在于哈希表中！" << endl;
	}
	else {
		cout << "查找失败！哈希表无目标值 \"" << tar_data << "\"" << endl;
	}
	return 0;
}

//输入数据，可自行输入
void input_data_arr() {
	for (int i = 0; i < MAXSIZE; i++) {
		data_arr[i] = i + 1;
	}
}

//创建哈希表
p_hash_arr create_hash_arr() {
	p_hash_arr arr = new hash_arr[KEY];     //创建哈希数组
	for (int i = 0; i < KEY; i++) {
		arr[i].data = 0;            //新数组的每一个data域赋值为0
		arr[i].next = NULL;          //指针域赋值为空
	}
	return arr;
}

//以链地址法解决冲突
p_link create_link(int data) {
	p_link node = new link;         //创建一个新结点node
	node->data = data;           //初始化
	node->next = NULL;
	return node;
}

//头插法插入哈希表
void insert_hash(p_hash_arr hash_arr, int data) {
	int cur = data % KEY;             //用除留取余减少空间浪费
	p_link node = create_link(data);         //建立新结点
	node->next = hash_arr[cur].next;        //头插法
	hash_arr[cur].next = node;
}

bool search_hash(p_hash_arr hash_arr, int tar_data) {
	int cur = tar_data % KEY;            //除留取余寻找到对应的地址
	p_link p_temp = hash_arr[cur].next;       //首先取哈希链地址的第一个值
	
	while (p_temp) {
		if (p_temp->data == tar_data) {       //判断此值是否为目标值
			return true;          //直接返回true
		}
		p_temp = p_temp->next;   //否则向下寻找
	}
	return false;         //未找到目标值则返回false
}