#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//NoR为非递归

//小区间优化:
//在当前需要排序的数据比较小的时候,我们没必要采用递归的方式,这样会太浪费空间
//我们直接运用插入排序一个函数,对小区间进行应用,这样可以大大的减轻时间复杂度
//有利于程序的有效进行.

//归并排序
//先将序列进行分解,不停地拆分,一直到子序列只有一个元素,然后对子序列进行合并,最终成有序序列


//==================================递归
//相邻子序列合并
//对于空间的二分,我们只需要三个数据就可以了
//begin      mid        end    就可以将空间分为2
void merge(int* arr, int begin, int mid, int end, int* tmp){
	
	//递增
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;

	//辅助空间
	int idx = begin;
	
	//合并有序的序列
	//检查是否越界
	while (begin1 <= end1&&begin2 <= end2){
		
		if (arr[begin1] <= arr[begin2])
			tmp[idx++] = arr[begin1++];

		else
			tmp[idx++] = arr[begin2++];
	}
	//判断是否有没有合并的元素
	if (begin1 <= end1)		//如果1中有剩余
		memcpy(tmp + idx, arr + begin1, sizeof(int)*(end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(tmp + idx, arr + begin2, sizeof(int)*(end2 - begin2 + 1));

	//合并后的序列拷贝到原始的数据
	memcpy(arr + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}
void _mergeSort(int* arr, int begin, int end, int* tmp){
	
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;

	//先进行子序列的合并
	_mergeSort(arr, begin, mid, tmp);
	_mergeSort(arr, mid + 1, end, tmp);
	//上面两部是对于子序列的合并,也就是将一个个的小点点进行合并

	//合并两个有序的子序列
	merge(arr, begin, mid, end, tmp);
}
void mergeSort(int* arr, int n){
	
	//申请辅助空间
	int* tmp = (int*)malloc(sizeof(int)*n);
	_mergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}


//=========================非递归
void mergeSortNoR(int* arr, int n){

	int* tmp = (int*)malloc(sizeof(int)*n);
	//子序列的步长
	int step = 1;
	while (step < n){
		for (int idx = 0; idx < n; idx += 2 * step){

			//找到两个待合并的子序列区间
			//[begin,mid]  [mid+1,end]
			int begin = idx;
			int mid = idx + step - 1;
			//判断是否存在第二个子序列
			if (mid >= n - 1)
				continue;	//不存在第二个子序列,直接跳过
			int end = idx + 2 * step - 1;
			//判断第二个子序列是否越界
			if (end > n)
				end = n - 1;
			merge(arr, begin, mid, end, tmp);
		}

		//更新步长
		step *= 2;
	}
}

//====================================3.非比较排序(计数排序)
//所消耗的空间过大    空间复杂度大
void countSort(int* arr, int n){
	
	//找到最大和最小值
	int max, min;
	min = max = arr[0];
	for (int i = 1; i < n; ++i){
	
		if (arr[i]>max)
			max = arr[i];
		if (arr[i < min])
			min = arr[i];
	}
	//计算范围
	int range = max - min + 1;
	//创建一个计数数组,初始化为0
	int* countArr = (int*)calloc(range, sizeof(int));

	//计数
	for (int i = 0; i < n; ++i){
		
		countArr[arr[i] - min]++;
	}
	
	//遍历计数数组
	int idx = 0;
	for (int i = 0; i < range; ++i){
		
		while (countArr[i]--){

			arr[idx++] = i + min;
		}
	}
}






void printArr(int* arr, int n){

	for (int i = 0; i < n; ++i){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void test(){

	int arr[] = { 5, 1, 3, 2, 0, 7, 10, 4, 6, 8, 9 };
	//printArr(arr, sizeof(arr) / sizeof(arr[0]));
	//bubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	//printArr(arr, sizeof(arr) / sizeof(arr[0]));

	mergeSortNoR(arr, sizeof(arr) / sizeof(arr[0]));
	printArr(arr, sizeof(arr) / sizeof(arr[0]));

	mergeSort(arr, sizeof(arr) / sizeof(arr[0]));
	printArr(arr, sizeof(arr) / sizeof(arr[0]));

	countSort(arr, sizeof(arr) / sizeof(arr[0]));
	printArr(arr, sizeof(arr) / sizeof(arr[0]));
}


int main(){

	test();

	system("pause");
	return 0;
}