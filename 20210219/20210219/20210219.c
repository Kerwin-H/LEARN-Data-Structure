#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int STDataType;

typedef struct stack{

	STDataType* _data;
	int _size;
	int _capacity;
}stack;
//��ʼ��
void stackInit(stack* st){
	
	if (st == NULL)
		return;

	st->_data = NULL;
	st->_size = st->_capacity = 0;

}
//�������
void checkCapacity(stack* st){

	if (st->_size == st->_capacity){
		int newCapacity = st->_capacity == 0 ? 1 : 2 * st->_capacity;
		st->_data = (STDataType*)realloc(st->_data, sizeof(STDataType)*newCapacity);
		st->_capacity = newCapacity;
	}
}

//��ջ
void stackPush(stack* st, STDataType val){

	if (st == NULL)
		return;
	checkCapacity(st);

	st->_data[st->_size++] = val;

} 

//��ջ
void stackPop(stack* st){

	if (st == NULL)
		return;

	if (st->_size > 0){
		
		st->_size--;
	}
}
//��ȡջ����Ԫ��
STDataType stackTop(stack* st){
	
	return st->_data[st->_size - 1];
}

//�ж�ջ�Ƿ�Ϊ��
int stackEmpty(stack* st){
	
	if (st == NULL || st->_size == 0)
		return 1;
	else
		return 0;
}

//ջ��С
int stackSize(stack* st){
	
	if (st == NULL)
		return 0;
	return st->_size;
}

void test(){
	
	stack st;
	stackInit(&st);
	stackPush(&st, 4);
	stackPush(&st, 5);
	stackPush(&st, 3);
	stackPush(&st, 2);
	
	for (int i = 0; i < 4; ++i){
		
		printf("%d ",stackTop(&st));
		stackPop(&st);
	}
	printf("\n");
}


int main(){

	test();

	system("pause");
	return 0;
}