#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//�������
int main(){





	system("pause");
	return 0;
}

struct ListNode{
	int val;
	struct ListNode *next;  //�ṹ��ָ��
};
//ɾ�����е�һ��ֵ
struct ListNode* removeElements(struct ListNode* head,int val){
	
	struct ListNode* prev = NULL, *cur = head;
	while (cur){
		if (cur->val == val){

			//��ͷ�ڵ�
			if (prev != NULL){
				prev->next = cur->next;
			}
			else{
				//ͷ��� ,���½ڵ�
				head = cur->next;
			}
			ListNode* next = cur->next;
			free(cur);
			//���µ���һ���ڵ�
			cur = next;
		}
		else{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}

//��ת����
//1.������ת������,Ȼ����ת,Ȼ����ת������
//2.Ԫ��ͷ��
struct ListNode* reverseList(struct ListNode* head){
	struct ListNode* newHead=NULL, *cur=head;
	while (cur){
		//�ȱ�����һ���ڵ��λ��
		struct ListNode* next = cur->next;
		//ͷ��cur
		cur->next = newHead;
		newHead = cur;
		//ͷ����һ������
		cur = next;
	}
	return newHead;
	//================================================
	//��ָ��
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


//����һ��ͷ���ķǿյ�����,����������м���
struct ListNode* middleNode(struct ListNode* head){
	struct ListNode* fast = head, *slow = head;

	while (fast&&fast->next){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

//����һ������,���������k�����

//������������ϲ���һ���µ�������������













