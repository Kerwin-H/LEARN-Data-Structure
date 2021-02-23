#include<stdio.h>
#include<stdlib.h>


void Swap(int* arr, int pos1, int pos2){

	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}

//==========ð������
void bubbleSort(int* arr,int n){
	
	//����Ԫ�ؽ��бȽ�
	//������Χ:0-Ϊ��������һλ
	int end = n;
	while (end > 1){
		
		//��һ��ð������
		for (int i = 1; i < end; ++i){
			
			if (arr[i - 1]>arr[i]){
				
				//���Ԫ������ƶ�
				Swap(arr, i - 1, i);
			}
		}
		--end;		//��Ҫ����ѭ��
	}
}

//==========��������
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

//���ֺ���
int partion(int* arr, int begin, int end){

	//��ȡ��׼ֵλ��
	int mid = getMid(arr, begin, end);
	//�ѻ�׼ֵ�ŵ���ʼλ��
	Swap(arr, begin, end);

	//����ѡ���׼ֵ
	int key = arr[begin];
	int start = begin;

	while (begin < end){

		//�Ӻ���ǰ��С�ڻ�׼ֵ��λ��
		while (begin < end&&arr[end] >= key)
			--end;

		//��ǰ����Ҵ��ڵ�λ��
		while (begin < end&&arr[begin] <= key)
			++begin;
		//���ú�������
		Swap(arr, begin, end);
	}
	//������׼ֵ������λ�õ�����
	Swap(arr, start, begin);
	return begin;
}

void quickSort(int* arr, int begin, int end){
	
	if (begin >= end)
		return;
	//div:һ�λ��ֺ��׼ֵ
	int div = partion(arr, begin, end);
	//�ֱ�����������ߵĿ���
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