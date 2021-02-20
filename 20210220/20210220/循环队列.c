
typedef struct {
	int* _data;
	int _front;     //��һ��Ԫ��λ��
	int _rear;      //���
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
	//����
	MyCircularQueue* mq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	mq->_data = (int*)malloc(sizeof(int)*k);
	mq->_front = mq->_rear = 0;
	mq->_k = k;
	mq->_size = 0;
	return mq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {

	if (myCircularQueueIsFull(obj))  //�ж��Ƿ�����
		return false;

	obj->_data[obj->_rear++] = value; //��ֵ

	if (obj->_rear >= obj->_k)    //����Ƿ�Խ��
		obj->_rear = 0;
	++obj->_size;
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {

	//�ж϶����Ƿ�Ϊ��
	if (myCircularQueueIsEmpty(obj))
		return false;
	//����
	obj->_front++;
	//�ж�ͷ�Ƿ�Խ��
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
	//���ض���:rear��ǰһ��λ�õ�Ԫ��
	if (obj->_rear != 0)
		return obj->_data[obj->_rear - 1];
	else
		return obj->_data[obj->_k - 1];
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->_data);
	free(obj);
}