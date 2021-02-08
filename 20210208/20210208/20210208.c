#include"seqList.h"

typedef int SLDataType;

//#define N 10
//=====��̬˳���Ķ���
//struct seqList2{
//	SLDataType _data[N];		
//	size_t _size;			//��ЧԪ�صĸ���
//	size_t _capacity;		//��ǰ���ǿ��Դ�ŵ����Ԫ�ظ���
//}seqList2;			//����


//=====��̬˳���Ķ���
//typedef struct seqList{
//	SLDataType* _data;		//��Ҫ���ж�̬���ٵ�һ������
//	size_t _size;			//��ЧԪ�صĸ���
//	size_t _capacity;		//��ǰ���ǿ��Դ�ŵ����Ԫ�ظ���
//}seqList;			//����


//=====���ڶ�̬��̬�ڴ��С�����
//printf("%d\n",sizeof(seqList2));
//printf("%d\n", sizeof(seqList));


//=====�ӿڳ�ʼ��
void initSeqList(seqList * sl){
	
	sl->_data = NULL;		//��������������data��Ϊ��
	sl->_size = sl->_capacity = 0;	//����Ϊ0

}

//=====β������
void pushBack(seqList* sl,SLDataType val){
	
	checkCapacity(sl);
	sl->_data[sl->_size] = val;		//��size Ҳ���Ǳ��е����һ�����ݽ��в���
	++sl->_size;	//���ν���
}

//=====βɾ
void popBack(seqList* ls){

	if (ls == NULL)
		return;
	if (ls->_size > 0)
		ls->_size--;
}

//ͷ��,Ч�ʸ�
void pushFront(seqList* sl, SLDataType val){
	
	if (sl == NULL)
		return;
	checkCapacity(sl);
	//1.�ƶ�Ԫ��
	int end = sl->_size;
	while (end > 0){
		sl->_data[end] = sl->_data[end - 1];

		--end;		//����������ѭ������˼
	}
	//2.ͷ��
	sl->_data[0] = val;

	sl->_size++;
}

//ͷɾ
void popFront(seqList* sl){
	
	if (sl == NULL||sl->_size==0)
		return;
	checkCapacity(sl);

	int start = 1;
	while (start < sl->_size){
		sl->_data[start-1]=sl->_data[start];
		
		++start;		//ѭ��
	}
	--sl->_size;
}
//��������
void insert(seqList* sl,int pos,SLDataType val){

	if (sl == NULL)
		return;

	if (pos >= 0 && pos <= sl->_size){

		checkCapacity(sl);

		int end = sl->_size;
		while (end > pos){
			sl->_data[end] = sl->_data[end - 1];
			--end;
		}

		sl->_data[pos] = val;

		sl->_size++;
	}
}
//����ɾ��
void erase(seqList* sl, int pos){

	if (sl == NULL || sl->_size == 0)
		return;

	if (pos >= 0 && pos < sl->_size){
		
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

int findIdx(seqList* sl, SLDataType val){
	
	int i = 0;
	for (; i < sl->_size; ++i){
		if (sl->_data[i] == val)
			return i;
	}
	return -1;
}

void destorySeqList(seqList* sl){
	if (sl){
		if (sl->_data){
			free(sl->_data);
			sl->_data = NULL;
		}
	}
}


//=====���ռ��С,���С,����
void checkCapacity(seqList* sl){

	if (sl == NULL)
		return;
	//���Ԫ�ظ�����������,����Ҫ����   
	if (sl->_size == sl->_capacity){
		
		int newCapacity = sl->_capacity == 0 ? 1 : 2 * sl->_capacity;
		//���ռ�,��������,�ͷ�ԭ���ռ�
		SLDataType* tmp = (SLDataType*)malloc(sizeof(SLDataType)* newCapacity);
		memcpy(tmp, sl->_data, sizeof(SLDataType)*sl->_size);
		free(sl->_data);

		//����ֱ��realloc

		//����
		sl->_data = tmp;
		sl->_capacity = newCapacity;
	}
}
//��ӡ
void printSeqList(seqList* ls){

	for (int i = 0; i < ls->_size; ++i){
		printf("%d ",ls->_data[i]);
	}
	printf("\n");
}



void test(){
	
	seqList sl;
	initSeqList(&sl);
	pushFront(&sl, 0);
	pushFront(&sl, 1);
	pushFront(&sl, 2);
	pushFront(&sl, 3);
	printSeqList(&sl);
	insert(&sl, 2, 99);
	erase(&sl, 4);
	printSeqList(&sl);
}

int main(){

	test();

	system("pause");
	return 0;
}




//1. �ռ�����
//2.֧���������
//3.β��  βɾ	����
//6.�ռ������ʸ�
//4.����λ�ò���ɾ��Ч�ʵ�
//5.���ݴ��۴�
