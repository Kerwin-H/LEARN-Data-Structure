#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef int QDataType;

typedef struct QNode{

	struct QNode* _next;
	QDataType _data;

}QNode;

typedef struct Queue{

	QNode* _front;
	QNode* _rear;
}Queue;

void queueInit(Queue* q);
QNode* creatNode(QDataType data);
void queuePush(Queue* q, QDataType data);
void queuePop(Queue* q);
int queueSize(Queue* q);
int queueEmpty(Queue* q);
void queueDestory(Queue* q);

void Swap(int* arr, int pos1, int pos2){

	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}

void printArr(int* arr, int n){

	for (int i = 0; i < n; ++i){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int getMid(int* arr, int begin, int end){

	int mid = begin + (end - begin) / 2;

	if (arr[begin] > arr[mid]){

		if (arr[mid] > arr[end])
			return mid;
		else if (arr[begin] > arr[end])
			return end;
		else
			return begin;
	}
	else{

		if (arr[mid] < arr[end])
			return mid;
		else if (arr[begin] < arr[end])
			return end;
		else
			return begin;
	}
}




//��ʼ��
void queueInit(Queue* q){

	q->_front = q->_rear = NULL;
}
//����
QNode* creatNode(QDataType data){

	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = data;
	node->_next = NULL;
	return node;
}
//��β���
void queuePush(Queue* q, QDataType data){

	QNode* node = creatNode(data);

	if (q->_front == NULL)
		q->_front = q->_rear = node;
	else{
		q->_rear->_next = node;
		q->_rear = node;
	}
}
//���ѳ���
void queuePop(Queue* q){
	if (q->_front){
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;

		//�ж��Ƿ�Ϊ��
		if (q->_front == NULL)
			q->_rear == NULL;
	}
}
//��ȡ��ͷԪ��
QDataType queueFront(Queue* q){

	return q->_front->_data;
}

//��ȡ��βԪ��
QDataType queueBack(Queue* q){

	return q->_rear->_data;
}



//��С
int queueSize(Queue* q){

	int num = 0;
	QNode* cur = q->_front;
	while (cur){

		++num;
		cur = cur->_next;
	}
	return num;

	//Ҳ����ֱ���ڽṹ������ڲ�����һ��size����,�ܸ����׵Ļ�ȡ
}
//�Ƿ�Ϊ��
int queueEmpty(Queue* q){

	if (q->_front == NULL)
		return 1;
	return 0;
}

int partion(int* arr, int begin, int end){

	//��ȡ��׼ֵλ��
	int mid = getMid(arr, begin, end);
	//�ѻ�׼ֵ�ŵ���ʼλ��
	Swap(arr, begin, end);

	//����ѡ���׼ֵ
	int key = arr[begin];
	int start = begin;

	while (begin < end){

		//�Ӻ���ǰ��С�ڻ�׼ֵ��λ��
		while (begin < end&&arr[end] >= key)
			--end;

		//��ǰ����Ҵ��ڵ�λ��
		while (begin < end&&arr[begin] <= key)
			++begin;
		//���ú�������
		Swap(arr, begin, end);
	}
	//������׼ֵ������λ�õ�����
	Swap(arr, start, begin);
	return begin;
}

//����
void queueDestory(Queue* q){

	QNode* cur = q->_front;
	while (cur){

		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}

void quickSortNoR2(int* arr, int n){
	
	Queue q;
	queueInit(&q);
	//����[0,n-1]����

	//�����Ƚ��ȳ�
	queuePush(&q, 0);
	queuePush(&q, n - 1);
	while (!queueEmpty(&q)){
		
		//ȡ��һ���������ʵ�ͽ���λ��
		int left = queueFront(&q);
		queuePop(&q);

		int right = queueFront(&q);
		queuePop(&q);
		//����[left,right]
		int div = partion(arr, left, right);

		//������[left,div-1]
		if (left < div - 1){
			
			queuePush(&q, left);
			queuePush(&q, div - 1);
		}

		//������[div+1,right]
		if (div + 1 < right){
			
			queuePush(&q, div + 1);
			queuePush(&q, right);
		}
	}
}







void test(){

	int arr[] = { 5, 1, 3, 2, 0, 7, 10, 4, 6, 8, 9 };
	//printArr(arr, sizeof(arr) / sizeof(arr[0]));
	//bubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	//printArr(arr, sizeof(arr) / sizeof(arr[0]));



	quickSortNoR2(arr, sizeof(arr) / sizeof(arr[0]));
	printArr(arr, sizeof(arr) / sizeof(arr[0]));
}


int main(){

	test();

	system("pause");
	return 0;
}