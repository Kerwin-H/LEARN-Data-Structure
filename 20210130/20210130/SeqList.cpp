#include"SeqList.h"



void SeqListInit(SeqList *ps){
	
	ps->_a = NULL;
	ps->_size = 0;
	ps->_capacity = 0;
}

void SeqListDestory(SeqList *ps){
	assert(ps);

	free(ps->_a);
	ps->_a = NULL;
	ps->_size = ps->_capacity = 0;

}

void SeqListCheckFront(SeqList *ps){

	if (ps->_size >= ps->_capacity){

		size_t newcapacity = ps->_capacity;
		ps->_a=realloc(ps->_a, ps->_capacity * 2 * sizeof(SLDataType));


	}
}



void SeqListPushBack(SeqList *ps, SLDataType x){
	assert(ps);

	SeqListCheckFront(ps);
	 
	if (ps->_size == ps->_capacity){
	
	
	
	}

	//ps->_size++



}
void SeqListPopBack(SeqList *ps);
void SeqListPushFront(SeqList *ps, SLDataType x);
void SeqListPopFront(SeqList *ps);