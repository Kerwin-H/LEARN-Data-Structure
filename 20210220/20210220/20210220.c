#include<stdio.h>
#include<stdlib.h>

//����С��
typedef int HDataType;

typedef struct heap{

	HDataType* _data;
	int _size;
	int _capacity;
}heap;


void Swap(int* a, int* b);
void heapInit(heap* hp);
void heapPush(heap* hp, HDataType val);
void heapPop(heap* hp);
void checkCapacity(heap* hp);
void shiftDown(int * arr, int n, int cur);
void shiftDownD(int * arr, int n, int cur);
void shiftUpD(int* arr, int n, int cur);
void shiftUp(int* arr, int n, int cur);
HDataType heapTop(heap* hp);
int heapEmpty(heap* hp);
void printTop(int* a, int n, int k);


//=======================================������������
void Swap(int* a, int* b){
	
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//==============================1.��ʼ��
void heapInit(heap* hp){
	
	if (hp == NULL)
		return;

	hp->_data = NULL;
	hp->_capacity = hp->_size = 0;
}
//================================2.�Ѳ���
void heapPush(heap* hp, HDataType val){
	
	if (hp == NULL)
		return;
	//���ռ�
	checkCapacity(hp);

	//β��
	hp->_data[hp->_size++] = val;
	//���ϵ���
	shiftUp(hp->_data, hp->_size, hp->_size - 1);
}
//=================================3.��ɾ��
void heapPop(heap* hp){
	
	if (hp->_size > 0){
		//����
		Swap(hp->_data[0], &hp->_data[hp->_size - 1]);
		//βɾ
		hp->_size--;
		//�ӶѶ����µ���
		shiftDown(hp->_data, hp->_size, 0);
	}
}

//====================================4.�Ѽ������
void checkCapacity(heap* hp){
	
	if (hp->_size == hp->_capacity){
		
		int newC = hp->_capacity == 0 ? 1 : 2 * hp->_capacity;
		hp->_data = (HDataType*)realloc(hp->_data, sizeof(HDataType)*newC);
		hp->_capacity = newC;
	}
}

//===================================5.С�����µ���
void shiftDown(int * arr, int n, int cur){
	//�ҵ����ӵ�λ��
	//����
	int child = 2 * cur + 1;

	while (child < n){
		//���Һ������ҵ���С��
		if (child + 1 < n && arr[child + 1] < arr[child])
			++child;
		//�͵�ǰ���ݱȽ�
		//1.����
		if (arr[child] < arr[cur]){
			int tmp = arr[child];
			arr[child] = arr[cur];
			arr[cur] = tmp;

			//λ�ø���
			cur = child;
			child = 2 * cur + 1;
		}
		//2.������
		else
			break;
	}
}
//=======================================6.������µ���
void shiftDownD(int * arr, int n, int cur){
	//�ҵ����ӵ�λ��
	//����
	int child = 2 * cur + 1;

	while (child < n){
		//���Һ������ҵ���С��
		if (child + 1 < n && arr[child + 1] > arr[child])
			++child;
		//�͵�ǰ���ݱȽ�
		//1.����
		if (arr[child] > arr[cur]){
			int tmp = arr[child];
			arr[child] = arr[cur];
			arr[cur] = tmp;

			//λ�ø���
			cur = child;
			child = 2 * cur + 1;
		}
		//2.������
		else
			break;
	}
}
//=====================================7.������ϵ���
void shiftUpD(int* arr, int n, int cur){

	//�͸��ڵ���бȽ�
	int parent = (cur - 1) / 2;

	while (cur > 0){
		if (arr[cur] > arr[parent]){

			int tmp = arr[cur];
			arr[cur] = arr[parent];
			arr[parent] = tmp;

			//����
			cur = parent;
			parent = (cur - 1) / 2;
		}
		else
			break;
	}
}


//==========================================8.С�����ϵ���
void shiftUp(int* arr, int n, int cur){

	//�͸��ڵ���бȽ�
	int parent = (cur - 1) / 2;

	while (cur > 0){
		if (arr[cur] < arr[parent]){

			int tmp = arr[cur];
			arr[cur] = arr[parent];
			arr[parent] = tmp;

			//����
			cur = parent;
			parent = (cur - 1) / 2;
		}
		else
			break;
	}
}
//=============================ȡ������
HDataType heapTop(heap* hp){
	
	return hp->_data[0];
}
//===========================�п�
int heapEmpty(heap* hp){

	if (hp == NULL || hp->_size == 0)
		return 1;
	else
		return 0;
}
//=====================================��ӡ
void printTop(int* a, int n, int k){
	
	heap hp;
	heapInit(&hp);
	for (int i = 0; i < n; ++i){
		heapPush(&hp, a[i]);
	}
	for (int i = 0; i < n; ++i){
		printf("%d ",heapTop(&hp));
		heapPop(&hp);
	}

}
//==================================9.������
void test(){
	
	int arr[] = {20,17,4,16,5,3};
	int n = sizeof(arr) / sizeof(arr[0]);
	//����O(n)
	for (int i = (n - 2) / 2; i >= 0; --i){
		
		shiftDown(arr, n, i);
	}
	//������ nlog(n)
	int end = n - 1;

	while (end > 0){
		
		Swap(&arr[0], &arr[end]);
		shiftDown(arr, end, 0);
		end--;
	}
}



//void test(){
//
//	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//
//	//����
//	//���ѵ���˼���ǽ�һ����û�а��ն���ʽ���е�����������ж���
//	for (int i = (n - 2) / 2; i >= 0; --i){
//
//		shiftDown(arr, n, i);
//	}
//}

//void test(){
//	
//	int arr[] = { 10, 5, 3, 8, 7, 6 };
//	
//	shiftDown(arr, sizeof(arr) / sizeof(arr[0]), 0);
//
//}

int main(){

	test();

	system("pause");
	return 0;
}