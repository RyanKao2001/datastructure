#include <stdio.h>
#define MAXQSIZE 100

using namespace std;

typedef struct Queue
{
	int *array;
	int front;
	int rear;
}SqQueue;

void CreateQueue(SqQueue &Q);
int QueueLength(SqQueue Q);
void EnQueue(SqQueue &Q, int data);
int DeQueue(SqQueue &Q);
int GetHead(SqQueue Q);

int main()
{
	SqQueue Q;
	CreateQueue(Q);

	return 0;
}

void CreateQueue(SqQueue &Q)
{
	Q.array = new int[MAXQSIZE];
	Q.front = Q.rear = 0;
}

int QueueLength(SqQueue Q)
{
	int length = (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
	return length;
}

void EnQueue(SqQueue &Q, int data)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)       //�ж��Ƿ����
		return;
	Q.array[Q.rear] = data;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
}

int DeQueue(SqQueue &Q)        //�ж��Ƿ�ӿ�
{
	if (Q.front == Q.rear)
		return -1;
	int data = Q.array[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;      //ͷָ��++
	return data;
}

int GetHead(SqQueue Q)
{
	if (Q.front != Q.rear)        //���в�Ϊ��
		return Q.array[Q.front];
}