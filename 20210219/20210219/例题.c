//==============1.括号匹配问题
//找到了左边的括号,就将其入栈,当找到了右边匹配的,则将左边的出栈,这样栈就为空,就成功匹配
bool isValid(char * s){
	stack st;

	stackInit(&st);		//初始化
	static char map[][2] = { { '(', ')' }, { '[', ']' }, { '{', '}' } };	//检测括号

	while (*s){	//存在字符时

		int i = 0;

		for (; i<3; ++i){	//利用循环找到左边对应的括号
			if (*s == map[i][0]){
				stackPush(&st, *s);	//找到就入栈
				++s;
				break;	//结束循环

			}
		}
		if (i == 3){	//如果没有找到,为3则没找到

			if (stackEmpty(&st))	//判断如果为空,则直接返回
				return false;
			char topchar = stackTop(&st);	//定义一个字符指向栈顶

			for (int j = 0; j<3; ++j){	//寻找有后面括号的字符

				if (*s == map[j][1]){	//存在字符于后面的时候

					if (topchar == map[j][0]){	//如果找到

						stackPop(&st);	//让其出栈
						++s;
						break;
					}
					else
						return false;		//没找到则返回错误

				}
			}
		}

	}
	if (stackEmpty(&st))		//字符寻找完后,如果为空
		return true;	//则证明成功匹配了,为真
	return false;
}
//=-==========2.用队列实现栈
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
//===========================3.栈实现队列

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