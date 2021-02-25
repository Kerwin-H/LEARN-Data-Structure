#include<stdio.h>
#include<stdlib.h>


void Swap(int* arr, int pos1, int pos2){

	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
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
	//int div = partion(arr, begin, end);
	//int div = partion2(arr, begin, end);
	int div = partion3(arr, begin, end);
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



//===============================1=======================
//����2  �ڿӷ�
int partion2(int* arr, int begin, int end){
	
	int mid = getMid(arr, begin, end);
	Swap(arr, begin, mid);
	
	//��һ����׼ֵ,Ҳ���ǳ�ʼΪ�ӵ�λ��
	int key = arr[begin];
	while (begin < end){
		//�Ӻ���ǰ�ҵ�С��
		while (begin < end&&arr[end] >= key)
			--end;
		//�������
		arr[begin] = arr[end];
		//��ǰ�����Ҵ��
		while (begin < end&&arr[begin] <= key)
			++begin;
		//���
		arr[end] = arr[begin];
	}
	arr[begin] = key;
	return begin;
}




//================================����3ǰ��ָ��
int partion3(int* arr, int begin, int end){
	
	int mid = getMid(arr, begin, end);
	Swap(arr, begin, mid);
	//��һ��С�ڻ�׼ֵ��λ��
	int prev = begin;
	//��һ��С�ڻ�׼ֵ��λ��
	int cur = begin + 1;

	int key = arr[begin];
	while (cur <= end){
		
		//��cur�ߵ���һ����׼ֵ��λ�õ�ʱ��,�ж��Ƿ�����
		if (arr[cur]<key && ++prev != cur) {
			
			//������,��������
			Swap(arr, prev,cur);
		}
		++cur;
	}
	Swap(arr, begin, prev);
	return prev;
}


//�ǵݹ����
void quickSortNoR(int* arr, int n){

	//����һ��˳���,���ֻ�������
	seqList sq;
	initSeqList(&sq);

	//�ȱ�����������
	//���ȷ���,�ڷ���
	pushBack(&sq, n - 1);
	pushBack(&sq, 0);

	//����˳���,��������
	while (!empty(&sq)){

		//ȡ��һ������
		int left = seqListBack(&sq);
		popBack(&sq);

		int right = seqListBack(&sq);
		popBack(&sq);

		//��������
		int div = partion(arr, left, right);

		//���������������
		if (left < div - 1){

			pushBack(&sq, div - 1);
			pushBack(&sq, left);
		}
		if (div + 1 < right){

			pushBack(&sq, div + 1);
			pushBack(&sq, right);
		}
	}
}



void test(){

	int arr[] = { 5, 1, 3, 2, 0, 7, 10, 4, 6, 8, 9 };
	//printArr(arr, sizeof(arr) / sizeof(arr[0]));
	//bubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	//printArr(arr, sizeof(arr) / sizeof(arr[0]));



	quickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	printArr(arr, sizeof(arr) / sizeof(arr[0]));
}


int main(){

	test();

	system("pause");
	return 0;
}