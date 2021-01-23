#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef int LDataType;

typedef struct listNode{

	LDataType _data;
	struct listNode* _next;  //��һ�����ݵĴ��λ��

}listNode;

typedef struct list{

	listNode* _head;  //��ŵ�һ���ڵ�ĵ�ַ
 
}list;

void listInit(list* lst){
	if (lst == NULL)
		return;
	//��ʼ��Ϊ������
	lst->_head = NULL;
}

listNode* creatNode(LDataType val){
	//���ٶ�̬����
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}
//β��
void listPushBack(list* lst,LDataType val){
	if (lst == NULL)
		return;
	//������,�����һ������
	if (lst->_head == NULL){
		//�����ڵ�
		lst->_head=creatNode(val);
	} 
	else{
		//����,ֱ���ҵ����һ���ڵ�
		listNode* tail = lst->_head;
		while (tail->_next != NULL){
			tail = tail->_next;
		}
	//����
		tail->_next = creatNode(val);
	}
}



void test(){
	list lst;
	listInit(&lst);
	listPushBack(&lst, 1);
	listPushBack(&lst, 2);
	listPushBack(&lst, 3);
	listPushBack(&lst, 4);
	listPushBack(&lst, 5);
	listPushBack(&lst, 6);


}






int main(){


	test();




	system("pause");
	return 0;
}
//021123


////ɾȥ�ظ������� 
//int removeDupLicates(int* nums, int numSize){
//	if (numSize <= 1)
//		return numSize;
//	int i = 0, j = 1, idx = 0;
//	while (j < numSize){
//		nums[idx++] = nums[i];
//		if (nums[i] == nums[j]){
//			while (j < numSize&&nums[i] == nums[j])
//				++j;
//			i = j;
//			++j;
//		}
//		else{
//			++i;
//			++j;
//		}
//	}
//	if (i < numSize)
//		nums[idx++] = nums[i];
//	return idx;
//}
//
////�����������ڵ����ݽ��кϲ�,����������һ���µ�����
//void merge(int* nums1, int num1Size, int m, int* nums2, int num2Size, int n){
//	//int* nums3 = (int*)malloc(sizeof(int)*(m + n));
//	//int i = 0, j = 0, idx = 0;
//	////����ͬʱ����
//	//while (i < m&&j < n){
//	//	if (nums1[i] <= nums2[j])
//	//		nums3[idx++] = nums1[i++];
//	//	else
//	//		nums3[idx++] = nums2[j++];
//	//}
//	////�ж��Ƿ���ʣ���Ԫ��
//	//if (i < m)
//	//	memcpy(nums3 + idx, nums1 + i, sizeof(int)*(m - i));
//	//if(i<n)
//	//	memcpy(nums3 + idx, nums2 + i, sizeof(int)*(n - i));
//	//memcpy(nums1, nums3, sizeof(int)*(m + n));
//	//free(nums3);
//
//	//�Ӻ���ǰ����
//
//	int i = m - 1, j = n - 1, idx = m + n - 1;
//	while (i >= 0 && j >= 0){
//		if (nums1[i] >= nums2[j])
//			nums1[idx--] = nums1[i--];
//		else
//			nums1[idx--] = nums2[j--];
//	}
//	//�ж�2���Ƿ���ʣ���Ԫ��
//	if (j >= 0)
//		memcpy(nums1, nums2, sizeof(int)*(j + 1));
//	//û��ʹ��malloc ���Բ���Ҫ�ͷ�	
//}
//
//
//void reverse(int* num, int start, int end){
//	/*for (int i = 0; i < (end - start) / 2; ++i){
//		int tmp = num[i];
//		num[i] = num[end - i];
//		num[end - i] = tmp;
//	}*/
//	while (start < end){
//		int tmp = num[start];
//		num[start] = num[end];
//		num[end] = tmp;
//		++start;
//		--end;
//	}
//}
////��ת����(��������3�β���)
//void rotate(int* nums, int numSize, int k){
//	if (numSize <= 1)
//		return;
//	k %= numSize;
//	reverse(nums, 0, numSize - k - 1);
//	reverse(nums, numSize-k, numSize - 1);
//	reverse(nums, 0, numSize - 1);
//}
//
//
//
////��������ֽ������,�������Ӧ������
//int* addToArrayFrom(int* A, int ASize, int K, int* returnSize){
//	//��ȡ���ֵĳ���
//	int len = 0;
//	int tmp = K;
//	while (tmp){
//		++len;
//		tmp /= 10;
//	}
//	//��ȡ����
//	int arrLen = len > ASize ? len + 1 : ASize + 1;
//	int* ret = (int*)malloc(sizeof(int)*arrLen);
//
//	//�Ӹ�λ��ʼ���
//	int end = ASize - 1;
//	//����һ����λ
//	int idx = 0;
//	int step = 0;
//	while (end >= 0 || K > 0){
//		//ÿһ��λ�õ�ֵ=��λ+��Ӧλ��ֵ
//		//�ȼӽ�λ��ֵ
//		int curRet = step;
//		if (end >= 0)
//			curRet += A[end];
//		if (K > 0)
//			curRet += K % 10;
//		
//		if (curRet > 9){
//			step = 1;
//			curRet -= 10;
//		}
//		else
//			step = 0;
//		//������
//		ret[idx++] = curRet;
//		--end;
//		K /= 10;
//	}
//	if (step == 1)
//		ret[idx++] = 1;
//	int start = 0;
//	int end = idx - 1;
//	while (start < end){
//		int tmp = ret[start];
//		ret[start] = ret[end];
//		ret[end] = tmp;
//		++start;
//		--end;
//	}
//	*returnSize = idx;
//	return ret;
//
//}