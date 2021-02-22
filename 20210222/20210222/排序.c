#include<stdio.h>
#include<stdlib.h>


void Swap(int* arr, int pos1, int pos2){

	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}


//==========插入排序算法   时间复杂度O(n^2)
//数据有序的时候 :O(n)
void insertSort(int* arr, int n){
	
	//假设第一个数据是有序的
	//未插入数据[1,n)
	for (int i = 0; i < n; ++i){
		
		//从有序的最后一个位置进行遍历
		int end = i - 1;
		int data = arr[i];
		while (end >= 0 && arr[end] >= data){
			
			//较大的数据向后移动
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = data;
	}
}

//==========希尔排序
//时间复杂度:n^1.3  不稳定
void shellSort(int* arr, int n){
	
	int gap = n;
	//一趟哈希排序
	while (gap > 1){

		gap = gap / 3 + 1;
		for (int i = gap; i < n; ++i){

			//同组数据,最后一个有序数组的位置
			int end = i - gap;
			//待插入的数据
			int data = arr[i];
			while (end >= 0 && arr[end]>data){

				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = data;
		}
	}
}

//选择排序
//稳定    O(n^2)
void selectSort(int* arr, int n){
	
	int start = 0;
	int end = n - 1;
	while (start < end){
		
		//首先找到最小值的位置
		int minIdx = start;
		int i;
		for (i = start + 1; i <= end; ++i){
			
			if (arr[i] < arr[minIdx])
				minIdx=i;
		}
		//将最小值存在起始位置
		Swap(arr, start, minIdx);
		//循环
		++start;
	}
}

void selectSortPlus(int* arr, int n){
	
	int start = 0;
	int end = n - 1;
	//我们运用同样的方法,只不过在每次遍历的时候
	//寻找一个最大的和一个最小的,这样遍历就能减少一半
	while (start < end){
		
		int minIdx = start;
		int maxIdx = start;
		for (int j = start + 1; j <= end; ++j){
			
			if (arr[j] < arr[minIdx])
				minIdx = j;
			if (arr[j]>arr[maxIdx])
				maxIdx = j;
		}
		//最小值放在头部
		Swap(arr, start, minIdx);
		//判断最大值位置是否在起始位置
		if (maxIdx == start)
			maxIdx = minIdx;
		//最大值放在尾部
		Swap(arr, end, maxIdx);

		++start;
		--end;
	}
}

//打印
void printArr(int* arr,int n){

	for (int i = 0; i < n; ++i){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

//堆排序
//时间复杂度:O(nlogn)
//稳定性: 不稳定
void shiftDown(int* arr, int n, int parent){
	
	int child = 2 * parent + 1;		//最后一个节点的位置
	while (child < n){
		
		if (child + 1 < n&&arr[child + 1] > arr[child])
			++child;
		if (arr[child]>arr[parent]){

			Swap(arr, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

void heapSort(int* arr, int n){
	
	for (int i = (n - 2) / 2; i >= 0; --i){
		
		shiftDown(arr, n, i);
	}
	int end = n - 1;
	while (end > 0){
		
		Swap(arr, end, 0);
		shiftDown(arr, end, 0);
		--end;
	}
}

//同样值发生交换就是不稳定排序
void test(){
	
	int arr[] = { 1,9, 6, 8, 2, 4, 7, 2, 5 };
	printArr(arr, sizeof(arr) / sizeof(arr[0]));
	heapSort(arr, sizeof(arr) / sizeof(arr[0]));
	printArr(arr, sizeof(arr) / sizeof(arr[0]));


	/*int arr[] = { 9, 6, 8, 2, 4, 7, 2, 5 };
	printArr(arr, sizeof(arr) / sizeof(arr[0]));
	insertSort(arr, sizeof(arr) / sizeof(arr[0]));
	printArr(arr, sizeof(arr) / sizeof(arr[0]));*/

}

int main(){

	test();

	system("pause");
	return 0;
}