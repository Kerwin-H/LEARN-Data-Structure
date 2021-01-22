#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef int SLDataType;

//��̬˳���
typedef struct seqList{
	SLDataType* _data;  //��̬���ٵ�����
	size_t _size;		//��ЧԪ�ظ���
	size_t _capacity;   //�ɴ�����Ԫ�ظ���


}seqList;

void initSeqList(seqList* sl){  //ע����г�ʼ��
	sl->_data = NULL;
	sl->_size = sl->_capacity = 0;
}




void checkCapacity(seqList* sl){

	assert(sl);//debug��Ч

	if (sl == NULL){
		return;
	}

	//���Ԫ�ظ�����������ͬ,������,Ҫ�����ռ�
	if (sl->_size == sl->_capacity){

		int newCapacity = sl->_capacity == 0 ? 1 : 2 * sl->_capacity;

		//����һ�������,������������,�ͷ�ԭ���ռ�
		SLDataType* tmp = (SLDataType*)malloc(sizeof(SLDataType)*newCapacity);
		memcpy(tmp, sl->_data, sizeof(SLDataType)* sl->_size);
		free(sl->_data);

		//��һ��д��  
		//sl->_data = (SLDataType*)realloc(sl->_data, sizeof(SLDataType)*newCapacity);


		//����
		sl->_data = tmp;
		sl->_capacity = newCapacity;

	}
}

//β��һ������O(1)
void pushBack(seqList* sl, SLDataType val){
	//�������
	checkCapacity(sl);
	sl->_data[sl->_size] = val;
	++sl->_size;

	//insert(sl, sl->_size, val);

}

void printSeqList(seqList* sl){
	for (int i = 0; i < sl->_size; ++i){
		printf("%d ",sl->_data[i]);
	}
	printf("\n");
}

//βɾO(1)
void popBack(seqList* sl){
	if (sl == NULL)
		return;
	if (sl->_size>0)
		sl->_size--;
}


//ͷ��  1.�ƶ�Ԫ�� O(n)
//Ч�ʵ�
void pushFornt(seqList* sl,SLDataType val){

	if (sl == NULL)
		return;

	checkCapacity(sl);  //�������
	//1.����Ԫ�ص��ƶ�,�Ӻ���ǰ
	int end = sl->_size;
	while (end > 0){
		sl->_data[end] = sl->_data[end - 1];  //��������ƶ�
		--end;
	}
	//2. ͷ��
	sl->_data[0] = val;

	sl->_size++;

	//insert(sl, 0, val);

}

//ͷɾO(n)
void popFront(seqList* sl){
	if (sl == NULL||sl->_size==0)
		return;
	int start = 1;
	while (start < sl->_size){
		sl->_data[start-1] = sl->_data[start];
		++start;
	}
	--sl->_size;

}

//�������,ԭʼ��������ƶ�
void insert(seqList* sl,int pos,SLDataType val){
	//���
	if (sl == NULL)
		return;

	checkCapacity(sl);
	//�ƶ�Ԫ��
	int end = sl->_size;
	while (end >pos ){
		sl->_data[end ] = sl->_data[end-1];
		--end;
	}
	//��������
	sl->_data[pos] = val;
	//����
	sl->_size++;

}

//ѡ��ɾ��
void erase(seqList* sl, int pos){
	if (sl == NULL || sl->_size == 0)
		return ;
	if (pos >= 0 && pos < sl->_size){
		//1.(pos,size]
		int start = pos + 1;
		while (start < sl->_size){
			sl->_data[start - 1] = sl->_data[start];
			++start;
		}
		--sl->_size;
	}
}

int empty(seqList* sl){
	if (sl == NULL || sl->_size == 0)
		return 1;
	else
		return 0;
}

int size(seqList* sl){
	if (sl == NULL)
		return 0;
	else
		return sl->_size;

}
//����
int find(seqList* sl, SLDataType val){
	int i = 0;
	for (i = 0; i < sl->_size; i++){
		if (sl->_data[i] == val)
			return i;
	}
	return -1;
}


//��ȡĳһ��λ��
SLDataType getId(seqList* sl, int pos){
	if (pos >= 0 && pos < sl->_size)
		return sl->_data[pos];


}

void destroy(seqList* sl){
	if (sl){
		if (sl->_data){
			//�ͷ�
			free(sl->_data);
			sl->_data = NULL;
		}
	}
}

void test(){
	seqList sl;
	initSeqList(&sl);
	pushBack(&sl, 1);
	pushBack(&sl, 2);
	pushBack(&sl, 3);
	pushBack(&sl, 4);
	pushBack(&sl, 5);
	printSeqList(&sl);

	//popFront(&sl);
	//printSeqList(&sl);
	//popFront(&sl);
	//printSeqList(&sl);
	//popFront(&sl);
	//printSeqList(&sl);
	//popFront(&sl);
	//printSeqList(&sl);
	//popFront(&sl);
	//printSeqList(&sl); 

	insert(&sl, 1, 99);
	printSeqList(&sl);

	
	insert(&sl, 0, 99);  //ͷ��

	insert(&sl, sl._size, 99);	//β��


}






int main(){

	test();

	system("pause");
	return 0;
}





//
//˳���:
//
//1.�ռ�����
//2.֧���������
//3.β�� βɾЧ�ʸ� O(1)
//4.�ռ����ø�
//5.����λ�ò����ɾ����Ч�ʵ�    ��Ҫ�ƶ�Ԫ��
//6.���ݴ��۴�
//
//�ʺ��ڷ��ʺͱ���


//eg  ɾ��Ϊval����
int removeElement(int* nums, int numSize, int val){
	int idx, i;
	idx = 0;
	i = 0;
	for (; i < numSize; ++i){
		if (nums[i] != val)	nums[idx++] = nums[i];
	}
	return idx;
}