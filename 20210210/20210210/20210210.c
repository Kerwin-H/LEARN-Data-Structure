#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef int LDataType;
typedef struct listNode{
	
	LDataType _data;
	struct listNode* _next;	//下一个存放地址

}listNode;

typedef struct list{
	//存放第一个节点的位置
	listNode* _head;
}list;


//初始化
void listInit(list* lst){
	 
	if (lst == NULL)
		return;
	//初始化为空的链表
	lst->_head = NULL;
}
//因为链表是要一个一个创建空间的表,多次创建比较麻烦,
//我们直接将创建链表的方式进行封装,形成一个接口,每次调用就可以了
listNode* creatNode(LDataType val){
	
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}

//尾插
void listPushBack(list* lst,LDataType val){
	
	if (lst == NULL)
		return; 

	//空链表插入第一个数据
	if (lst->_head == NULL){
		lst->_head=creatNode(val);
	}
	//当链表不为空的时候就需要进行一个遍历,寻找最后的元素,进行插入
	else{
		listNode* tail = lst->_head;	//先将头结点赋予
		while (tail->_next != NULL){	//然后进行遍历
			tail = tail->_next;			//不等则继续遍历
		}
		//遍历完找到后,利用刚封装的插入函数进行利用即可
		tail->_next = creatNode(val);
	}
}
//尾删
void listPopBack(list* lst){
	
	if (lst== NULL||lst->_head==NULL)
		return;

	struct listNode* tail = lst->_head;
	struct listNode* prev = NULL;

	//遍历找到最后一个节点
	while (tail->_next != NULL){
		
		prev = tail;	//找到要删除节点的data
		tail = tail->_next;
	}
	//删除节点
	free(tail);
	//修改指向
	if (prev == NULL)	//删除的为头结点,则更新头结点
		lst->_head = NULL;
	else
		prev->_next = NULL; 
}
//头插
void listPushFront(list* lst,LDataType val){
	
	if (lst == NULL)
		return;
	if (lst->_head == NULL)
		lst->_head = creatNode(val);

	else{
		listNode* node = creatNode(val);
		listNode* next = lst->_head;

		lst->_head = node;
		node->_next = next;
	}
}
//头删
void listPopFront(list* lst){
	
	if (lst == NULL||lst->_head==NULL)
		return;

	struct listNode* next = lst->_head->_next;
	//释放头结点
	free(lst->_head);
	lst->_head = next;
}
//中间插入
void listInsertAfter(listNode* cur, LDataType val){
	
	listNode* node = creatNode(val);
	listNode* next = cur->_next;

	cur->_next = node;
	node->_next = next;
} 
//删除节点cur的下一个节点
void listEraseAfter(listNode* cur){
	
	listNode* next = cur->_next;
	if (next == NULL)
		return;

	struct listNode* nextnext = next->_next;
	free(next);
	cur->_next = nextnext;
}
//查找
listNode* listFind(list* lst, LDataType val){
	
	if (lst == NULL||lst->_head==NULL)
		return NULL;

	//从头开始遍历
	struct listNode* cur = lst->_head;
	while (cur){
		if (cur->_data == val)
			return cur;

		cur = cur->_next;
	}
	return NULL;
}
//内存大小
//int listSize(list* lst){}

//销毁(只需要对链表的内部进行空间释放,头结点直接为空即可)
void listDestory(list* lst){
	
	if (lst->_head == NULL||lst==NULL)
		return;
	else{
		listNode* cur = lst->_head;
		while (cur){
			listNode* next = cur->_next;
			free(cur);
			cur = next;
		}
	}
	lst->_head = NULL;
}
//这个打印函数有问题
void Printlist(listNode* lst){
	
	listNode* tmp;
	tmp=lst->_data;
	
	while (tmp != NULL){
		
		printf("%d  ",tmp);
		tmp= tmp->_next;
	}
	printf("\n");
}

void test(){
	list lst;
	listInit(&lst);
	listPushBack(&lst, 5);
	
	

	

	

	Printlist(&lst);

}
int main(){

	test();

	system("pause");
	return 0;
}


