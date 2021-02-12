/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
//=================1.�ҳ��������������ʼ�ڵ�
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	int lenA = 0, lenB = 0;
	struct ListNode* curA = headA;
	struct ListNode* curB = headB;
	while (curA){

		++lenA;
		curA = curA->next;
	}
	while (curB){

		++lenB;
		curB = curB->next;
	}

	int gap = abs(lenA - lenB);

	struct ListNode* longList = headA, *shortList = headB;
	if (lenB>lenA){

		longList = headB;
		shortList = headA;
	}
	while (gap--){

		longList = longList->next;
	}
	while (longList&&shortList){

		if (longList == shortList)
			return longList;
		longList = longList->next;
		shortList = shortList->next;
	}
	return NULL;
}

//=========2.�ж������Ƿ��л�
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* listCycle(struct ListNode* head){

	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast&&fast->next){

		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return fast;
	}
	return NULL;
}

bool hasCycle(struct ListNode *head) {

	struct ListNode* node = listCycle(head);
	if (node){
		while (node){

			if (node == head)
				return node;
			node = node->next;
			head = head->next;
		}
	}
	return NULL;
}

//=============3.���ƴ������ָ�������

//========4. ��������в�������
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* insertionSortList(struct ListNode* head){
	//��ǰ�����б���
	//if(head==NULL||head->head==NULL)
	//    return head;

	struct ListNode* tail, *cur, *prev, *node;

	tail = head;
	cur = head->next;
	while (cur){

		if (cur->val<tail->val){

			//ͷ��㿪ʼ����
			prev == NULL;
			node = head;
			while (node && node->val <= cur->val){

				prev = node;
				node = node->next;
			}
			tail->next = cur->next;
			cur->next = node;
			if (prev)
				prev->next = cur;
			else
				head = cur;
			cur = tail->next;
		}
		else{

			tail = tail->next;
			cur = tail->next;
		}

	}
	return head;
}

//==========5.��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ��
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead){
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		ListNode* prev, *start, *end;
		prev = NULL;
		start = pHead;
		end = start->next;
		while (end){

			if (start->val == end->val){

				//�ҵ�����
				while (end&& end->val == start->val)
					end = end->next;

				while (start != end){

					struct ListNode* next = start->next;
					free(start);
					start = next;
				}
				if (prev == NULL)
					pHead = start;
				else
					prev->next = start;
				if (end)
					end = end->next;
			}
			else{

				prev = start;
				start = end;
				end = end->next;
			}
		}
		return pHead;
	}
};