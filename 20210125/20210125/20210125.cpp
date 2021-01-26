#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//例题理解
int main(){





	system("pause");
	return 0;
}

struct ListNode{
	int val;
	struct ListNode *next;  //结构体指针
};
//删除其中的一个值
struct ListNode* removeElements(struct ListNode* head,int val){
	
	struct ListNode* prev = NULL, *cur = head;
	while (cur){
		if (cur->val == val){

			//非头节点
			if (prev != NULL){
				prev->next = cur->next;
			}
			else{
				//头结点 ,更新节点
				head = cur->next;
			}
			ListNode* next = cur->next;
			free(cur);
			//更新到下一个节点
			cur = next;
		}
		else{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}

//逆转链表
//1.可以先转成数组,然后逆转,然后再转成链表
//2.元素头插
struct ListNode* reverseList(struct ListNode* head){
	struct ListNode* newHead=NULL, *cur=head;
	while (cur){
		//先保存下一个节点的位置
		struct ListNode* next = cur->next;
		//头插cur
		cur->next = newHead;
		newHead = cur;
		//头插下一个数据
		cur = next;
	}
	return newHead;
	//================================================
	//多指针
	if (head == NULL||head->next == NULL)
		return head;

	struct ListNode* n1, *n2, *n3;
	n1 = head;
	n2 = n1->next;
	n3 = n2->next;
	
	n1->next = NULL;
	while (n2){
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3)
			n3 = n3->next;
	}
	return n1;
}


//给定一个头结点的非空单链表,返回链表的中间结点
struct ListNode* middleNode(struct ListNode* head){
	struct ListNode* fast = head, *slow = head;

	while (fast&&fast->next){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

//输入一个链表,输出倒数第k个结点

//两个升序链表合并成一个新的升序链表并返回













