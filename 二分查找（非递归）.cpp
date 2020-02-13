#include <iostream>
#define MAXSIZE 20
#define ERROR -1

using namespace std;

int bin_search(int arr[], int key);

int main() {
	int key;
	int arr[MAXSIZE] = { 0 };
	for (int i = 0; i < MAXSIZE; i++) {
		arr[i] = i + 1;
	}
	cout << "������Ҫ���ҵ�ֵ��";
	cin >> key;
	int result = bin_search(arr, key);
	if (result == ERROR) {
		cerr << "δ�ҵ�ָ�����ݣ�" << endl;
	}
	else {
		cout << "ֵ" << key << "�������е��±�Ϊ��";
		cout << result << endl;
	}
}

int bin_search(int arr[], int key) {
	int low = 0;
	int high = MAXSIZE - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (key == arr[mid]) {
			return mid;
		}
		else {
			if (key < arr[mid]) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
	}
	return ERROR;
}