#include<stdio.h>
#include<stdlib.h>


void Swap(int* arr, int pos1, int pos2){

	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}

//==========冒泡排序
void bubbleSort(int* arr,int n){
	
	//相邻元素进行比较
	//遍历范围:0-为排序的最后一位
	int end = n;
	while (end > 1){
		
		//第一次冒泡排序
		for (int i = 1; i < end; ++i){
			
			if (arr[i - 1]>arr[i]){
				
				//大的元素向后移动
				Swap(arr, i - 1, i);
			}
		}
		--end;		//主要进行循环
	}
}

//==========快速排序
int getMid(int* arr, int begin, int end){

	int mid = begin + (end - begin) / 2;

	if (arr[begin] > arr[mid]){

		if (arr[mid] > arr[end])
			return mid;
		else if (arr[begin] > arr[end])
			return end;
		else
			return begin;
	}
	else{

		if (arr[mid] < arr[end])
			return mid;
		else if (arr[begin] < arr[end])
			return end;
		else
			return begin;
	}
}

//划分函数
int partion(int* arr, int begin, int end){

	//获取基准值位置
	int mid = getMid(arr, begin, end);
	//把基准值放到起始位置
	Swap(arr, begin, end);

	//首先选择基准值
	int key = arr[begin];
	int start = begin;

	while (begin < end){

		//从后向前找小于基准值的位置
		while (begin < end&&arr[end] >= key)
			--end;

		//从前向后找大于的位置
		while (begin < end&&arr[begin] <= key)
			++begin;
		//调用函数交换
		Swap(arr, begin, end);
	}
	//交换基准值与相遇位置的数据
	Swap(arr, start, begin);
	return begin;
}

void quickSort(int* arr, int begin, int end){
	
	if (begin >= end)
		return;
	//div:一次划分后基准值
	int div = partion(arr, begin, end);
	//分别进行左右两边的快排
	//[begin,div-1]
	//[div+1,end]
	quickSort(arr, begin, div - 1);
	quickSort(arr, div + 1, end);
}






void printArr(int* arr, int n){

	for (int i = 0; i < n; ++i){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test(){
	
	int arr[] = { 1, 5, 7, 9, 6, 3, 8, 4 };
	printArr(arr, sizeof(arr) / sizeof(arr[0]));
	bubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	printArr(arr, sizeof(arr) / sizeof(arr[0]));



	quickSort(arr,0, sizeof(arr) / sizeof(arr[0])-1);
	printArr(arr, sizeof(arr) / sizeof(arr[0]));
}

int main(){
	 
	test();

	system("pause");
	return 0;
}