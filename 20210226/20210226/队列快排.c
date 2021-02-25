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




//初始化
void queueInit(Queue* q){

	q->_front = q->_rear = NULL;
}
//创建
QNode* creatNode(QDataType data){

	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = data;
	node->_next = NULL;
	return node;
}
//队尾入队
void queuePush(Queue* q, QDataType data){

	QNode* node = creatNode(data);

	if (q->_front == NULL)
		q->_front = q->_rear = node;
	else{
		q->_rear->_next = node;
		q->_rear = node;
	}
}
//队友出队
void queuePop(Queue* q){
	if (q->_front){
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;

		//判断是否为空
		if (q->_front == NULL)
			q->_rear == NULL;
	}
}
//获取队头元素
QDataType queueFront(Queue* q){

	return q->_front->_data;
}

//获取队尾元素
QDataType queueBack(Queue* q){

	return q->_rear->_data;
}



//大小
int queueSize(Queue* q){

	int num = 0;
	QNode* cur = q->_front;
	while (cur){

		++num;
		cur = cur->_next;
	}
	return num;

	//也可以直接在结构体变量内部定义一个size变量,能更简易的获取
}
//是否为空
int queueEmpty(Queue* q){

	if (q->_front == NULL)
		return 1;
	return 0;
}

int partion(int* arr, int begin, int end){

	//获取基准值位置
	int mid = getMid(arr, begin, end);
	//把基准值放到起始位置
	Swap(arr, begin, end);

	//首先选择基准值
	int key = arr[begin];
	int start = begin;

	while (begin < end){

		//从后向前找小于基准值的位置
		while (begin < end&&arr[end] >= key)
			--end;

		//从前向后找大于的位置
		while (begin < end&&arr[begin] <= key)
			++begin;
		//调用函数交换
		Swap(arr, begin, end);
	}
	//交换基准值与相遇位置的数据
	Swap(arr, start, begin);
	return begin;
}

//销毁
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
	//保存[0,n-1]区间

	//队列先进先出
	queuePush(&q, 0);
	queuePush(&q, n - 1);
	while (!queueEmpty(&q)){
		
		//取出一个区间的其实和结束位置
		int left = queueFront(&q);
		queuePop(&q);

		int right = queueFront(&q);
		queuePop(&q);
		//划分[left,right]
		int div = partion(arr, left, right);

		//子区间[left,div-1]
		if (left < div - 1){
			
			queuePush(&q, left);
			queuePush(&q, div - 1);
		}

		//子区间[div+1,right]
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