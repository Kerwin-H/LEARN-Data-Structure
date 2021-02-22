#include<stdio.h>
#include<stdlib.h>


void Swap(int* arr, int pos1, int pos2){

	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}


//==========���������㷨   ʱ�临�Ӷ�O(n^2)
//���������ʱ�� :O(n)
void insertSort(int* arr, int n){
	
	//�����һ�������������
	//δ��������[1,n)
	for (int i = 0; i < n; ++i){
		
		//����������һ��λ�ý��б���
		int end = i - 1;
		int data = arr[i];
		while (end >= 0 && arr[end] >= data){
			
			//�ϴ����������ƶ�
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = data;
	}
}

//==========ϣ������
//ʱ�临�Ӷ�:n^1.3  ���ȶ�
void shellSort(int* arr, int n){
	
	int gap = n;
	//һ�˹�ϣ����
	while (gap > 1){

		gap = gap / 3 + 1;
		for (int i = gap; i < n; ++i){

			//ͬ������,���һ�����������λ��
			int end = i - gap;
			//�����������
			int data = arr[i];
			while (end >= 0 && arr[end]>data){

				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = data;
		}
	}
}

//ѡ������
//�ȶ�    O(n^2)
void selectSort(int* arr, int n){
	
	int start = 0;
	int end = n - 1;
	while (start < end){
		
		//�����ҵ���Сֵ��λ��
		int minIdx = start;
		int i;
		for (i = start + 1; i <= end; ++i){
			
			if (arr[i] < arr[minIdx])
				minIdx=i;
		}
		//����Сֵ������ʼλ��
		Swap(arr, start, minIdx);
		//ѭ��
		++start;
	}
}

void selectSortPlus(int* arr, int n){
	
	int start = 0;
	int end = n - 1;
	//��������ͬ���ķ���,ֻ������ÿ�α�����ʱ��
	//Ѱ��һ�����ĺ�һ����С��,�����������ܼ���һ��
	while (start < end){
		
		int minIdx = start;
		int maxIdx = start;
		for (int j = start + 1; j <= end; ++j){
			
			if (arr[j] < arr[minIdx])
				minIdx = j;
			if (arr[j]>arr[maxIdx])
				maxIdx = j;
		}
		//��Сֵ����ͷ��
		Swap(arr, start, minIdx);
		//�ж����ֵλ���Ƿ�����ʼλ��
		if (maxIdx == start)
			maxIdx = minIdx;
		//���ֵ����β��
		Swap(arr, end, maxIdx);

		++start;
		--end;
	}
}

//��ӡ
void printArr(int* arr,int n){

	for (int i = 0; i < n; ++i){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

//������
//ʱ�临�Ӷ�:O(nlogn)
//�ȶ���: ���ȶ�
void shiftDown(int* arr, int n, int parent){
	
	int child = 2 * parent + 1;		//���һ���ڵ��λ��
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

//ͬ��ֵ�����������ǲ��ȶ�����
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