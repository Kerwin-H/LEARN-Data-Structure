/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
//=================1.找出两个单链表的起始节点
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

//=========2.判断链表是否有环
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

//=============3.复制带有随机指针的链表

//========4. 对链表进行插入排序
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* insertionSortList(struct ListNode* head){
	//从前向后进行遍历
	//if(head==NULL||head->head==NULL)
	//    return head;

	struct ListNode* tail, *cur, *prev, *node;

	tail = head;
	cur = head->next;
	while (cur){

		if (cur->val<tail->val){

			//头结点开始遍历
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

//==========5.在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针
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

				//找到数据
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