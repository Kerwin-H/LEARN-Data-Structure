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
QDataType queueFornt(Queue* q){
	
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