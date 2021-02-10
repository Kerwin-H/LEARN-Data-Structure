#include<stdio.h>
//int removeElement(int* nums, int numsSize, int val){
//
//	int* new = (int*)malloc(sizeof(int)*numsSize);
//	int idx = 0;
//	for (int i = 0; i<numsSize; ++i){
//		if (nums[i] != val){
//			new[idx++] = nums[i];
//		}
//	}
//	memcpy(nums, new, sizeof(int)*idx);
//	return idx;
//}
//====1.������Ԫ���Ƴ�,����ʱ�临�Ӷ���С
int removeElement(int* nums, int numsSize, int val){
	
	if (nums == NULL || numsSize = 0)
		return;

	int idx = 0;
	int i = 0;
	for (i = 0; i <= numsSize; ++i){
		if (nums[i] != val){
			nums[idx++] = nums[i];
		}
	}
	return idx;
}

//=======2.ɾ���ظ���,Ҫ���Ӷ�
int removeDuplicates(int* nums, int numsSize){
	if (numsSize <= 1)
		return numsSize;

	int i = 0, j = 1, idx = 0;
	while (j < numsSize){
		nums[idx++] = nums[i];
		if (nums[i] == nums[j]){
			while (j < numsSize&&nums[i] == nums[j]){
				++j;

				i = j;
				++j;
			}
		}
		else{
			++i;
			++j;
		}
	}
	if (i < numsSize)
		nums[idx++] = nums[i];
	return idx;
}

//3.=====�ϲ�����
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){

	int* nums3 = (int*)malloc(sizeof(int)*(m + n));
	int i = 0, j = 0, idx = 0;

	//����ͬʱ����
	while (i<m&&j<n){
		if (nums1[i] <= nums2[j])
			nums3[idx++] = nums1[i++];
		else
			nums3[idx++] = nums2[i++];
	}
	if (i<m)
		memcpy(nums3 + idx, nums1 + i, sizeof(int)*(m - i));
	if (j<n)
		memcpy(nums3 + idx, nums2 + j, sizeof(int)*(n - j));
	memcpy(nums1, nums3, sizeof(int)*(m + n));
	free(nums3);
}

//
//
///**
//* Note: The returned array must be malloced, assume caller calls free().
//*/
//int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
//
//	int len = 0;
//	int tmp = K;
//	while (tmp){
//		++len;
//		tmp /= 10;
//	}
//
//	int arrlen = len>Asize ? len + 1 : Asize + 1;
//	int* ret = (int*)malloc(sizeof(int)*arrlen);
//
//	int end = Asize - 1;
//
//	int step = 0;
//	int idx = 0;
//	while (end >= 0 || K>0){
//
//		int curRet = step;
//		if (end >= 0)
//			curRet += A[end];
//		if (K>0)
//			curRet += K % 10;
//
//		if (curRet>9){
//			step = 1;
//			curRet -= 10;
//		}
//		ret[idx++] = curRet;
//		--end;
//		K /= 10;
//	}
//	if (step == 1)
//		ret[idx++] = 1;
//
//	int start = 0;
//	int end = idx - 1;
//	while (start<end){
//
//		int tmp = ret[start];
//		ret[start] = ret[end];
//		ret[end] = tmp;
//		++start;
//		--end;
//	}
//	*returnSize = idx;
//	return ret;
//}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int missNumber(int* nums, int numsSize)
{
	int i = 0;
	int res = numsSize;
	for (i = 0; i < numsSize; i++)
	{
		res = res ^i ^ nums[i];
	}
	return res;
}/*
int main()
{
	int num[] = { 5, 4, 3, 1, 2, 6, 7, 9, 0 };
	int n = 0;
	n = sizeof(num) / sizeof(num[0]);
	int p = missNumber(num, n);
	printf("ȱʧ�������ǣ�%d\n", p);
	system("pause");
	return 0;
}*/



//
//
//int find(int arr[], int len){
//	int i, j, k;
//	for (i = 0; i < len; ++i){
//		k = 0;
//		for (j = 0; j < len; ++j){
//			if (arr[i] == arr[j]){
//				k++;
//			}
//		}
//		if (k == 1){
//			printf("%d ",arr[i]);
//		}
//	}
//	printf("\n");
//}
//int main(){
//	int arr[] = { 1,1,5,7,9,8,5,7 };
//	int len = 0;
//	len = sizeof(arr) / sizeof(arr[0]);
//	find(arr, len);
//	system("pause");
//	return 0;
//}