#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int STDataType;
//顺序结构实现
typedef struct stack{

	STDataType* _data;
	int _size;
	int _capacity;
}stack;

void stackInit()

void checkCapacity(stack* st){
	
	if (st->_size == st->_capacity){
		int newCapacity = st->_capacity == 0 ? 1 : 2 * st->_capacity;
		st->_data = (STDataType*)realloc(st->_data,sizeof(STDataType)* newCapacity );
		st->_capacity = newCapacity;
	}	
}

//入栈
void stackPush(stack* st, STDataType val){
	
	if (st == NULL)
		return;
	checkCapacity(st);
	//尾插
	st->_data[st->_size++] = val;
	
}
