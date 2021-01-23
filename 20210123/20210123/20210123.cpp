#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef int LDataType;

typedef struct listNode{

	LDataType _data;
	struct listNode* _next;  //下一个数据的存放位置

}listNode;

typedef struct list{

	listNode* _head;  //存放第一个节点的地址
 
}list;

void listInit(list* lst){
	if (lst == NULL)
		return;
	//初始化为空链表
	lst->_head = NULL;
}

listNode* creatNode(LDataType val){
	//开辟动态数组
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}
//尾插
void listPushBack(list* lst,LDataType val){
	if (lst == NULL)
		return;
	//空链表,插入第一个数据
	if (lst->_head == NULL){
		//创建节点
		lst->_head=creatNode(val);
	} 
	else{
		//遍历,直到找到最后一个节点
		listNode* tail = lst->_head;
		while (tail->_next != NULL){
			tail = tail->_next;
		}
	//插入
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


////删去重复的数据 
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
////将两个数组内的数据进行合并,并有序的组成一个新的数组
//void merge(int* nums1, int num1Size, int m, int* nums2, int num2Size, int n){
//	//int* nums3 = (int*)malloc(sizeof(int)*(m + n));
//	//int i = 0, j = 0, idx = 0;
//	////进行同时遍历
//	//while (i < m&&j < n){
//	//	if (nums1[i] <= nums2[j])
//	//		nums3[idx++] = nums1[i++];
//	//	else
//	//		nums3[idx++] = nums2[j++];
//	//}
//	////判断是否由剩余的元素
//	//if (i < m)
//	//	memcpy(nums3 + idx, nums1 + i, sizeof(int)*(m - i));
//	//if(i<n)
//	//	memcpy(nums3 + idx, nums2 + i, sizeof(int)*(n - i));
//	//memcpy(nums1, nums3, sizeof(int)*(m + n));
//	//free(nums3);
//
//	//从后向前遍历
//
//	int i = m - 1, j = n - 1, idx = m + n - 1;
//	while (i >= 0 && j >= 0){
//		if (nums1[i] >= nums2[j])
//			nums1[idx--] = nums1[i--];
//		else
//			nums1[idx--] = nums2[j--];
//	}
//	//判断2中是否还有剩余的元素
//	if (j >= 0)
//		memcpy(nums1, nums2, sizeof(int)*(j + 1));
//	//没有使用malloc 所以不需要释放	
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
////旋转数组(运用右旋3次操作)
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
////数组和数字进行相加,并输出对应的数组
//int* addToArrayFrom(int* A, int ASize, int K, int* returnSize){
//	//获取数字的长度
//	int len = 0;
//	int tmp = K;
//	while (tmp){
//		++len;
//		tmp /= 10;
//	}
//	//获取长度
//	int arrLen = len > ASize ? len + 1 : ASize + 1;
//	int* ret = (int*)malloc(sizeof(int)*arrLen);
//
//	//从个位开始相加
//	int end = ASize - 1;
//	//上面一步进位
//	int idx = 0;
//	int step = 0;
//	while (end >= 0 || K > 0){
//		//每一个位置的值=进位+对应位的值
//		//先加进位的值
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
//		//逆序存放
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