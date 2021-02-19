//==============1.����ƥ������
//�ҵ�����ߵ�����,�ͽ�����ջ,���ҵ����ұ�ƥ���,����ߵĳ�ջ,����ջ��Ϊ��,�ͳɹ�ƥ��
bool isValid(char * s){
	stack st;

	stackInit(&st);		//��ʼ��
	static char map[][2] = { { '(', ')' }, { '[', ']' }, { '{', '}' } };	//�������

	while (*s){	//�����ַ�ʱ

		int i = 0;

		for (; i<3; ++i){	//����ѭ���ҵ���߶�Ӧ������
			if (*s == map[i][0]){
				stackPush(&st, *s);	//�ҵ�����ջ
				++s;
				break;	//����ѭ��

			}
		}
		if (i == 3){	//���û���ҵ�,Ϊ3��û�ҵ�

			if (stackEmpty(&st))	//�ж����Ϊ��,��ֱ�ӷ���
				return false;
			char topchar = stackTop(&st);	//����һ���ַ�ָ��ջ��

			for (int j = 0; j<3; ++j){	//Ѱ���к������ŵ��ַ�

				if (*s == map[j][1]){	//�����ַ��ں����ʱ��

					if (topchar == map[j][0]){	//����ҵ�

						stackPop(&st);	//�����ջ
						++s;
						break;
					}
					else
						return false;		//û�ҵ��򷵻ش���

				}
			}
		}

	}
	if (stackEmpty(&st))		//�ַ�Ѱ�����,���Ϊ��
		return true;	//��֤���ɹ�ƥ����,Ϊ��
	return false;
}
//=-==========2.�ö���ʵ��ջ
typedef struct{

	Queue q;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {

	MyStack* ms = (MyStack*)malloc(sizeof(MyStack));
	queueInit(&ms->q);
	return ms;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	queuePush(&obj->q, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {

	int ret;
	int size = queueSize(&obj->q);
	while (size>1){

		int front = queueFront(&obj->q);
		queuePop(&obj->q);
		queuePush(&obj->q, front);
		--size;
	}
	ret = queueFront(&obj->q);
	queuePop(&obj->q);
	return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	return queueBack(&obj->q);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return queueEmpty(&obj->q);
}

void myStackFree(MyStack* obj) {
	queueDestory(&obj->q);
	free(obj);
}
//===========================3.ջʵ�ֶ���

typedef struct {

	stack pushST;
	stack popST;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {

	MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
	stackInit(&mq->pushST, 10);
	stackInit(&mq->popST, 10);
	return mq;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	stackPush(&mq->pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	int ret;
	if (stackEmpty(&obj->popST)){

		while (stackEmpty(&obj->pushST) != 1){

			int top = stackTop(&obj->pushST);
			stackPop(&obj->pushST);
			stackPush(&obj->popST, top);
		}
	}
	ret = stackTop(&obj->popST);
	stackPop(&obj->popST);
	return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (stackEmpty(&obj->popST)){

		while (stackEmpty(&obj->pushST) != 1){

			int top = stackTop(&obj->pushST);
			stackPop(&obj->pushST);
			stackPush(&obj->popST, top);
		}
	}
	return ret = stackTop(&obj->popST);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return stackEmpty(&obj->pushST) && stackEmpty(&obj->popST);
}

void myQueueFree(MyQueue* obj) {
	stackDestory(&obj->pushST);
	stackDestory(&obj->popST);
	free(obj);
}