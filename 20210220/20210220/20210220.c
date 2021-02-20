#include<stdio.h>
#include<stdlib.h>

//假设小堆
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


//=======================================基础交换函数
void Swap(int* a, int* b){
	
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//==============================1.初始化
void heapInit(heap* hp){
	
	if (hp == NULL)
		return;

	hp->_data = NULL;
	hp->_capacity = hp->_size = 0;
}
//================================2.堆插入
void heapPush(heap* hp, HDataType val){
	
	if (hp == NULL)
		return;
	//检查空间
	checkCapacity(hp);

	//尾插
	hp->_data[hp->_size++] = val;
	//向上调整
	shiftUp(hp->_data, hp->_size, hp->_size - 1);
}
//=================================3.堆删除
void heapPop(heap* hp){
	
	if (hp->_size > 0){
		//交换
		Swap(hp->_data[0], &hp->_data[hp->_size - 1]);
		//尾删
		hp->_size--;
		//从堆顶向下调整
		shiftDown(hp->_data, hp->_size, 0);
	}
}

//====================================4.堆检查增容
void checkCapacity(heap* hp){
	
	if (hp->_size == hp->_capacity){
		
		int newC = hp->_capacity == 0 ? 1 : 2 * hp->_capacity;
		hp->_data = (HDataType*)realloc(hp->_data, sizeof(HDataType)*newC);
		hp->_capacity = newC;
	}
}

//===================================5.小堆向下调整
void shiftDown(int * arr, int n, int cur){
	//找到孩子的位置
	//左孩子
	int child = 2 * cur + 1;

	while (child < n){
		//左右孩子中找到最小的
		if (child + 1 < n && arr[child + 1] < arr[child])
			++child;
		//和当前数据比较
		//1.调整
		if (arr[child] < arr[cur]){
			int tmp = arr[child];
			arr[child] = arr[cur];
			arr[cur] = tmp;

			//位置更新
			cur = child;
			child = 2 * cur + 1;
		}
		//2.不调整
		else
			break;
	}
}
//=======================================6.大堆向下调整
void shiftDownD(int * arr, int n, int cur){
	//找到孩子的位置
	//左孩子
	int child = 2 * cur + 1;

	while (child < n){
		//左右孩子中找到最小的
		if (child + 1 < n && arr[child + 1] > arr[child])
			++child;
		//和当前数据比较
		//1.调整
		if (arr[child] > arr[cur]){
			int tmp = arr[child];
			arr[child] = arr[cur];
			arr[cur] = tmp;

			//位置更新
			cur = child;
			child = 2 * cur + 1;
		}
		//2.不调整
		else
			break;
	}
}
//=====================================7.大堆向上调整
void shiftUpD(int* arr, int n, int cur){

	//和父节点进行比较
	int parent = (cur - 1) / 2;

	while (cur > 0){
		if (arr[cur] > arr[parent]){

			int tmp = arr[cur];
			arr[cur] = arr[parent];
			arr[parent] = tmp;

			//更新
			cur = parent;
			parent = (cur - 1) / 2;
		}
		else
			break;
	}
}


//==========================================8.小堆向上调整
void shiftUp(int* arr, int n, int cur){

	//和父节点进行比较
	int parent = (cur - 1) / 2;

	while (cur > 0){
		if (arr[cur] < arr[parent]){

			int tmp = arr[cur];
			arr[cur] = arr[parent];
			arr[parent] = tmp;

			//更新
			cur = parent;
			parent = (cur - 1) / 2;
		}
		else
			break;
	}
}
//=============================取出堆首
HDataType heapTop(heap* hp){
	
	return hp->_data[0];
}
//===========================判空
int heapEmpty(heap* hp){

	if (hp == NULL || hp->_size == 0)
		return 1;
	else
		return 0;
}
//=====================================打印
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
//==================================9.堆排序
void test(){
	
	int arr[] = {20,17,4,16,5,3};
	int n = sizeof(arr) / sizeof(arr[0]);
	//建堆O(n)
	for (int i = (n - 2) / 2; i >= 0; --i){
		
		shiftDown(arr, n, i);
	}
	//堆排序 nlog(n)
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
//	//建堆
//	//建堆的意思就是将一串子没有按照堆形式排列的数组进行排列而已
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