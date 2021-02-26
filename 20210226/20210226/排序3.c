#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//NoRΪ�ǵݹ�

//С�����Ż�:
//�ڵ�ǰ��Ҫ��������ݱȽ�С��ʱ��,����û��Ҫ���õݹ�ķ�ʽ,������̫�˷ѿռ�
//����ֱ�����ò�������һ������,��С�������Ӧ��,�������Դ��ļ���ʱ�临�Ӷ�
//�����ڳ������Ч����.

//�鲢����
//�Ƚ����н��зֽ�,��ͣ�ز��,һֱ��������ֻ��һ��Ԫ��,Ȼ��������н��кϲ�,���ճ���������


//==================================�ݹ�
//���������кϲ�
//���ڿռ�Ķ���,����ֻ��Ҫ�������ݾͿ�����
//begin      mid        end    �Ϳ��Խ��ռ��Ϊ2
void merge(int* arr, int begin, int mid, int end, int* tmp){
	
	//����
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;

	//�����ռ�
	int idx = begin;
	
	//�ϲ����������
	//����Ƿ�Խ��
	while (begin1 <= end1&&begin2 <= end2){
		
		if (arr[begin1] <= arr[begin2])
			tmp[idx++] = arr[begin1++];

		else
			tmp[idx++] = arr[begin2++];
	}
	//�ж��Ƿ���û�кϲ���Ԫ��
	if (begin1 <= end1)		//���1����ʣ��
		memcpy(tmp + idx, arr + begin1, sizeof(int)*(end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(tmp + idx, arr + begin2, sizeof(int)*(end2 - begin2 + 1));

	//�ϲ�������п�����ԭʼ������
	memcpy(arr + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}
void _mergeSort(int* arr, int begin, int end, int* tmp){
	
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;

	//�Ƚ��������еĺϲ�
	_mergeSort(arr, begin, mid, tmp);
	_mergeSort(arr, mid + 1, end, tmp);
	//���������Ƕ��������еĺϲ�,Ҳ���ǽ�һ������С�����кϲ�

	//�ϲ����������������
	merge(arr, begin, mid, end, tmp);
}
void mergeSort(int* arr, int n){
	
	//���븨���ռ�
	int* tmp = (int*)malloc(sizeof(int)*n);
	_mergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}


//=========================�ǵݹ�
void mergeSortNoR(int* arr, int n){

	int* tmp = (int*)malloc(sizeof(int)*n);
	//�����еĲ���
	int step = 1;
	while (step < n){
		for (int idx = 0; idx < n; idx += 2 * step){

			//�ҵ��������ϲ�������������
			//[begin,mid]  [mid+1,end]
			int begin = idx;
			int mid = idx + step - 1;
			//�ж��Ƿ���ڵڶ���������
			if (mid >= n - 1)
				continue;	//�����ڵڶ���������,ֱ������
			int end = idx + 2 * step - 1;
			//�жϵڶ����������Ƿ�Խ��
			if (end > n)
				end = n - 1;
			merge(arr, begin, mid, end, tmp);
		}

		//���²���
		step *= 2;
	}
}

//====================================3.�ǱȽ�����(��������)
//�����ĵĿռ����    �ռ临�Ӷȴ�
void countSort(int* arr, int n){
	
	//�ҵ�������Сֵ
	int max, min;
	min = max = arr[0];
	for (int i = 1; i < n; ++i){
	
		if (arr[i]>max)
			max = arr[i];
		if (arr[i < min])
			min = arr[i];
	}
	//���㷶Χ
	int range = max - min + 1;
	//����һ����������,��ʼ��Ϊ0
	int* countArr = (int*)calloc(range, sizeof(int));

	//����
	for (int i = 0; i < n; ++i){
		
		countArr[arr[i] - min]++;
	}
	
	//������������
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