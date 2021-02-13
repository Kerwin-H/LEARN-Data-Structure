#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef int LDataType;
//双向带头循环链表的节点
typedef struct ListNode{

	LDataType _data;
	struct ListNode* _next;		//下一个节点的起始位置
	struct ListNode* _prev;		//上一个节点的起始位置
}ListNode;

//双向带头循环链表
typedef struct List{

	struct ListNode* _head;
}List;

ListNode* createListNode(LDataType val){
	
	struct ListNode* node = (struct ListNode*)malloc(sizeof(ListNode));
	node->_data = val;
	node->_next = NULL;
	node->_prev = NULL;

	return node;
}

void listInit(List*lst){
	
	if (lst == NULL)
		return;
	//空链表
	lst->_head = createListNode(0);
	lst->_head->_next = lst->_head->_prev = lst->_head;
}

//尾插O(1)
void listPushBack(List* lst, LDataType val){

	if (lst == NULL) 
		return;

	struct ListNode* last = lst->_head->_prev;
	struct ListNode* newNode = createListNode(val);
	//_head  .....last  newNode 
	last->_next = newNode;
	newNode->_prev = last;
	
	newNode->_next = lst->_head;
	lst->_head->_prev = newNode;
}

//尾删
void listPopBack(List* lst){
	
	if (lst == NULL)
		return;
	//空链表判断
	if (lst->_head->_next == lst->_head)
		return;
	
	struct ListNode* last = lst->_head->_prev;
	struct ListNode* prev = last->_prev;

	free(last);

	lst->_head->_prev = prev;
	prev->_next = lst->_head;

}

void printList(List* lst){

	struct ListNode* cur = lst->_head->_next;
	while (cur != lst->_head){
		printf("%d ",cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
//头插
void listPushFront(List* lst,LDataType val){

	if (lst == NULL)
		return;

	struct ListNode* next = lst->_head->_next;
	struct ListNode* newNode = createListNode(val);
	
	//head   newNode next
	lst->_head->_next = newNode;
	newNode->_prev = lst->_head;

	newNode->_next = next;
	next->_prev = newNode;

}
//头删
void listPopFront(List* lst){
	
	if (lst == NULL||lst->_head->_next==lst->_head)
		return;

	struct ListNode* next = lst->_head->_next;
	struct ListNode* nextnext = next->_next;
	//head cur  next
	nextnext->_prev = lst->_head;
	lst->_head->_next = nextnext;
	free(next);
}
//
void listErase(List* lst, struct ListNode* node){
	
	//不能删除head结点
	if (lst==NULL||lst->_head == node)
		return;

	//prev  node  next
	struct ListNode* prev = node->_prev;
	struct ListNode* next = node->_next;

	prev->_next = next;
	next->_prev = prev;

	free(node);
}

void listInsert(List* lst, struct ListNode* node, LDataType val){

	if (lst == NULL)
		return;

	struct ListNode* prev = node->_prev;
	struct ListNode* newNode = createListNode(val);

	//prev  newNode  node
	prev->_next = newNode;
	newNode->_prev = prev;

	newNode->_next = node;
	node->_prev = newNode;
}

listDestory(List* lst){
	
	if (lst){
		if (lst->_head){
			struct ListNode* cur = lst->_head->_next;
			while (cur != lst->_head){
				
				struct ListNode* next = cur->_next;
				free(cur);
				cur = next;
			}
			free(lst->_head);
		}
	}
}

void test(){

	List lst;
	listInit(&lst);
	listPushBack(&lst, 1);
	listPushBack(&lst, 2);
	listPushBack(&lst, 3);
	listPushBack(&lst, 4);
	listPopBack(&lst);
	listPushFront(&lst,99);
	
	printList(&lst);

	
	//printList(&lst);
}

int main(){
	test();

	system("pause");
	return 0;
}




