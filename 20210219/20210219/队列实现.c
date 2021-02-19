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
QDataType queueFornt(Queue* q){
	
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

test(){

	Queue q;
	queueInit(&q);
	queuePush(&q, 1);

}

int main(){

	test();

	system("pause");
	return 0;
}