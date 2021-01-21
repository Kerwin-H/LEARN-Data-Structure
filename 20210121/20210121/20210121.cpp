#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>


typedef int SLDataType;


//��̬˳���
//#define N 10
//typedef struct seqList2{
//	SLDataType _deta[N];  //�����ڴ� 
//	size_t _size;
//	size_t _capacity;
//
//}seqList2;


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

//β��һ������
void pushBack(seqList* sl, SLDataType val){
	//�������
	checkCapacity(sl);
	sl->_data[sl->_size] = val;
	++sl->_size;
}

void test(){
	seqList sl;
	initSeqList(&sl);
	pushBack(&sl, 1);
	pushBack(&sl, 2);
	pushBack(&sl, 3);
	pushBack(&sl, 4);
	pushBack(&sl, 5);
	

}



//void test(){
	//printf("��̬:%d\n",sizeof(seqList2));
	//printf("��̬:%d\n", sizeof(seqList));

//}




int main(){

//	//����ʱ�临�Ӷ�
//	int N;
//	for (int i = 0; i < N; ++i) {
//		for (int i = 0; i < N; ++i){
//			//���������Ƕ��,��O(n)=N^2
//	}
//}
//
//	for (int i = 0; i < 2 * N; ++i)
//		//O(n)=2N
//
//
//		//����ʱ�临�Ӷ�
//		//һ�����ʱ�临�Ӷ�,ֻȡ��ߴ���,��ȥ��ϵ��
//
//		
//	for (int i = 0; i < M ++i)
//	for (int i = 0; i < N; ++i)
//		//O(N+M)
//
//
//
//	for (int i = 0; i < 100; ++i)
//		//O(1)   ��������1
//
//
//	//��strchrʱ�临�Ӷ�
//		const char * strchr(const char * str, int character);
//	//��������������,O(n)����
//
//
//	//ð������n^2
//
//
//
//
//	//�ݹ����  ��ʱ�临�Ӷ�
//	long long Factorial(size_t N) {
//		return N < 2 ? N : Factorial(N - 1)*N;
//	}
//	//O(n)  ������������ִ�д���
//
//	long long Fibonacci(size_t N) {
//		return N < 2 ? N : Fibonacci(N - 1) + Fibonacci(N - 2);
//	}
	//��Ϊ�����������ε��õݹ�,����ΪO(2^n)


	//�ռ临�Ӷȿ���������,�ҳ����к��еĴ�������


	test();



	system("pause");
	return 0;
}