#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//==������������ϲ���һ���µ�������������
//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
//	//����Ƿ�Ϊ��
//	if (l1 == NULL)
//		return l1;
//	if (l2 == NULL)
//		return l2;
//
//	struct ListNode* newHead, *newTail;
//	//ȷ����ͷ
//	if (l1->val <= l2->val){
//		newHead = newTail = l1;
//		l1 = l1->next;
//	}
//	else{
//		newHead = newTail = l2;

//	}

//}

//===================
struct ListNode{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Partition{
public:
	ListNode* partition(ListNode* pHead, int x){
		
		struct ListNode* lessHead, *lessTail, *greaterHead, *greaterLess,*cur;

		lessHead = lessTail = greaterHead = greaterLess = NULL;
		
		cur = pHead;
		while (cur){
			if (cur->val <= x){
				//�ж��Ƿ�Ϊ������
				if (lessHead == NULL)
					lessHead = lessTail = cur;
				else{
					lessTail->next = cur;
					lessTail = lessTail->next;
				}
			}
			else{
				if (greaterHead == NULL)
					greaterHead = greaterTail= cur;
				else{
					greaterTail->next = cur;
					greaterTail = greaterTail->next;
				}
			}
			cur = cur->next;
		}
		lessTail->next = greaterHead;
		greaterTail->next = NULL;
	}
};

//��20210126 ¼��


