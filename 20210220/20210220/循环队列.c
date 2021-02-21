
typedef struct {
	int* _data;
	int _front;     //第一个元素位置
	int _rear;      //最后
	int _k;
	int _size;
} MyCircularQueue;


bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	if (obj->_size == 0)
		return true;
	else
		return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {

	if (obj->_size == obj->_k)
		return true;
	else
		return false;
}

MyCircularQueue* myCircularQueueCreate(int k) {
	//创建
	MyCircularQueue* mq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	mq->_data = (int*)malloc(sizeof(int)*k);
	mq->_front = mq->_rear = 0;
	mq->_k = k;
	mq->_size = 0;
	return mq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {

	if (myCircularQueueIsFull(obj))  //判断是否已满
		return false;

	obj->_data[obj->_rear++] = value; //赋值

	if (obj->_rear >= obj->_k)    //检查是否越界
		obj->_rear = 0;
	++obj->_size;
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {

	//判断队列是否为空
	if (myCircularQueueIsEmpty(obj))
		return false;
	//出队
	obj->_front++;
	//判断头是否越界
	if (obj->_front >= obj->_k)
		obj->_front = 0;
	--obj->_size;
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->_data[obj->_front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	//返回队列:rear的前一个位置的元素
	if (obj->_rear != 0)
		return obj->_data[obj->_rear - 1];
	else
		return obj->_data[obj->_k - 1];
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->_data);
	free(obj);
}