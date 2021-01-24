#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//单链表的接口实现

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
void listPushBack(list* lst, LDataType val){
	if (lst == NULL)
		return;
	//空链表,插入第一个数据
	if (lst->_head == NULL){
		//创建节点
		lst->_head = creatNode(val);
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

//尾删   将上一个节点修改
void listPopBack(list* lst){
	
	if (lst == NULL||lst->_head==NULL)
		return;

	listNode* tail = lst->_head;
	listNode* prev = NULL;

	//遍历
	while (tail->_next != NULL){
		prev = tail;
		tail = tail->_next;
	}
	//删除节点
	free(tail);
	
	//如果只存在一个节点,则删除的为头结点
	if (prev == NULL)
		lst->_head = NULL;    //更新头结点
	else
		prev->_next = NULL;   //修改指向
}


//头插数据
void listPushFront(list* lst,LDataType val){
	
	if (lst == NULL)
		return;
	//空的链表,插入第一个数据
	if (lst->_head == NULL)
		lst->_head = creatNode(val);
	else{
		listNode* node = creatNode(val);
		listNode* next = lst->_head;
		//head,node,next
		lst->_head = node; 
		node->_next = next;
	} 
}
//头删
void listPopFront(list* lst){

	if (lst == NULL||lst->_head==NULL)
		return;

	listNode* next = lst->_head->_next;
	//释放头结点
	free(lst->_head);
	lst->_head = next;
}

//中间位置
void listInsertAfter(listNode* cur,LDataType val){

	listNode* node = creatNode(val);
	listNode* next = cur->_next;

	cur->_next = node;
	node->_next = next; 
}
//删除cur节点的下一个节点
void listEraseAfter(listNode* cur){
	
	// cur  next  next->next

	listNode* next = cur->_next;
	if (next == NULL)
		return;
	listNode* nextnext = next->_next;
	free(next);
	cur->_next = nextnext;
}

listNode* listFind(list* lst,LDataType val){

	if (lst == NULL || lst->_head == NULL)
		return NULL;
	listNode* cur = lst->_head;
	//从第一个节点开始遍历
	while (cur){
		if (cur->_data == val)
			return cur;

		cur = cur->_next;
	}
	return NULL;
}

int listSize(){}

//将其销毁
void listDestroy(list* lst){

	if (lst == NULL || lst->_head)
		return;
	//从第一个节点开始释放
	listNode* cur = lst->_head;
	while (cur){
	
		list* next = cur->_next;
		//开始释放
		free(cur);
		cur = next;
	}
	lst->_head = NULL;
}


void test(){
	list lst;
	listInit(&lst);
	listPushBack(&lst, 1);
	listPushBack(&lst, 2);
	listPushBack(&lst, 3);
	listPushBack(&lst, 4);
	listPushBack(&lst, 5);
	
	listPopFront(&lst);		//头删
}






int main(){


	test();




	system("pause");
	return 0;
}