#include <iostream>
#define MAXSIZE 25
#define KEY 7        //����ȡ�࣬���ѡ������

using namespace std;

//������ַ����ֹ��ͻ
typedef struct link {
	int data;
	link* next;
}hash_arr, * p_hash_arr, link, * p_link;

//������ݵ����飬�����û�����
int data_arr[MAXSIZE] = { 0 };

void input_data_arr();
p_hash_arr create_hash_arr();
p_link create_link(int data);
void insert_hash(p_hash_arr hash_arr, int data);
bool search_hash(p_hash_arr hash_arr, int tar_data);

int main() {
	int tar_data;
	input_data_arr();
	cout << "Ĭ�����ݳ�ʼ�����..." << endl;
	p_hash_arr hash_arr = create_hash_arr();
	for (int i = 0; i < MAXSIZE; i++) {
		insert_hash(hash_arr, data_arr[i]);
	}
	cout << "��ϣ������ɣ�" << endl;
	cout << "��������ҵ�Ŀ��ֵ��";
	cin >> tar_data;
	if (search_hash(hash_arr, tar_data)) {
		cout << "���ҳɹ���Ŀ��ֵ \"" << tar_data << "\" �����ڹ�ϣ���У�" << endl;
	}
	else {
		cout << "����ʧ�ܣ���ϣ����Ŀ��ֵ \"" << tar_data << "\"" << endl;
	}
	return 0;
}

//�������ݣ�����������
void input_data_arr() {
	for (int i = 0; i < MAXSIZE; i++) {
		data_arr[i] = i + 1;
	}
}

//������ϣ��
p_hash_arr create_hash_arr() {
	p_hash_arr arr = new hash_arr[KEY];     //������ϣ����
	for (int i = 0; i < KEY; i++) {
		arr[i].data = 0;            //�������ÿһ��data��ֵΪ0
		arr[i].next = NULL;          //ָ����ֵΪ��
	}
	return arr;
}

//������ַ�������ͻ
p_link create_link(int data) {
	p_link node = new link;         //����һ���½��node
	node->data = data;           //��ʼ��
	node->next = NULL;
	return node;
}

//ͷ�巨�����ϣ��
void insert_hash(p_hash_arr hash_arr, int data) {
	int cur = data % KEY;             //�ó���ȡ����ٿռ��˷�
	p_link node = create_link(data);         //�����½��
	node->next = hash_arr[cur].next;        //ͷ�巨
	hash_arr[cur].next = node;
}

bool search_hash(p_hash_arr hash_arr, int tar_data) {
	int cur = tar_data % KEY;            //����ȡ��Ѱ�ҵ���Ӧ�ĵ�ַ
	p_link p_temp = hash_arr[cur].next;       //����ȡ��ϣ����ַ�ĵ�һ��ֵ
	
	while (p_temp) {
		if (p_temp->data == tar_data) {       //�жϴ�ֵ�Ƿ�ΪĿ��ֵ
			return true;          //ֱ�ӷ���true
		}
		p_temp = p_temp->next;   //��������Ѱ��
	}
	return false;         //δ�ҵ�Ŀ��ֵ�򷵻�false
}