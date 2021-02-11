//==============1.删除链表中给定val值的节点
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* removeElements(struct ListNode* head, int val){
	//if(head==NULL)
	//  return ;

	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	while (cur){

		if (cur->val == val){
			//非头结点
			if (prev != NULL){
				prev->next = cur->next;
				//这里是直接将要连接节点的地址赋予prev
			}
			else{
				//头结点
				head = cur->next;
			}
			struct ListNode* next = cur->next;
			free(cur);
			cur = next;
		}
		else{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}

//==============2.反转单链表
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* reverseList(struct ListNode* head){
	struct ListNode* newHead = NULL;
	struct ListNode* cur = head;
	while (cur){
		//头插
		struct ListNode* next = cur->next;
		cur->next = newHead;
		newHead = cur;

		cur = next;
	}
	return newHead;
}

//=============3.求中间元素

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* middleNode(struct ListNode* head){
	struct ListNode* cur = head;
	struct ListNode* tmp = head;
	int len = 0;
	while (cur){

		len++;
		cur = cur->next;
	}
	int k = len / 2;
	while (k--){

		tmp = tmp->next;
	}
	return tmp;
}
//eg2
struct ListNode* middleNode(struct ListNode* head){

	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast&&fast->next){

		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

//============4.输入链表,输出倒数第K个节点
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
	struct ListNode* fast = pListHead;
	struct ListNode* slow = pListHead;

	while (k--){
		if (fast)
			fast = fast->next;
		else
			return NULL;
	}

	while (fast){

		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

//=============5.合并两个有序的链表
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

	// if(l1==NULL)
	//    return l2;
	// if(l2=NULL)
	//    return l1;

	struct ListNode* newHead, *newTail;

	if (l1->val <= l2->val){

		newHead = newTail = l1;
		l1 = l1->next;
	}
	else{

		newHead = newTail = l2;
		l2 = l2->next;
	}
	while (l1 && l2){

		if (l1->val <= l2->val){

			newTail->next = l1;
			l1 = l1->next;
			newTail = newTail->next;
		}
		else{

			newTail->next = l2;
			l2 = l2->next;
			newTail = newTail->next;
		}
	}
	if (l1)
		newTail->next = l1;
	if (l2)
		newTail->next = l2;

	return newHead;
}
