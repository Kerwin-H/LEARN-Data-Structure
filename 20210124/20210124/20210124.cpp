#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//������Ľӿ�ʵ��

typedef int LDataType;

typedef struct listNode{

	LDataType _data;
	struct listNode* _next;  //��һ�����ݵĴ��λ��

}listNode;

typedef struct list{

	listNode* _head;  //��ŵ�һ���ڵ�ĵ�ַ

}list;

void listInit(list* lst){
	if (lst == NULL)
		return;
	//��ʼ��Ϊ������
	lst->_head = NULL;
}

listNode* creatNode(LDataType val){
	//���ٶ�̬����
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}
//β��
void listPushBack(list* lst, LDataType val){
	if (lst == NULL)
		return;
	//������,�����һ������
	if (lst->_head == NULL){
		//�����ڵ�
		lst->_head = creatNode(val);
	}
	else{
		//����,ֱ���ҵ����һ���ڵ�
		listNode* tail = lst->_head;
		while (tail->_next != NULL){
			tail = tail->_next;
		}
		//����
		tail->_next = creatNode(val);
	}
}

//βɾ   ����һ���ڵ��޸�
void listPopBack(list* lst){
	
	if (lst == NULL||lst->_head==NULL)
		return;

	listNode* tail = lst->_head;
	listNode* prev = NULL;

	//����
	while (tail->_next != NULL){
		prev = tail;
		tail = tail->_next;
	}
	//ɾ���ڵ�
	free(tail);
	
	//���ֻ����һ���ڵ�,��ɾ����Ϊͷ���
	if (prev == NULL)
		lst->_head = NULL;    //����ͷ���
	else
		prev->_next = NULL;   //�޸�ָ��
}


//ͷ������
void listPushFront(list* lst,LDataType val){
	
	if (lst == NULL)
		return;
	//�յ�����,�����һ������
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
//ͷɾ
void listPopFront(list* lst){

	if (lst == NULL||lst->_head==NULL)
		return;

	listNode* next = lst->_head->_next;
	//�ͷ�ͷ���
	free(lst->_head);
	lst->_head = next;
}

//�м�λ��
void listInsertAfter(listNode* cur,LDataType val){

	listNode* node = creatNode(val);
	listNode* next = cur->_next;

	cur->_next = node;
	node->_next = next; 
}
//ɾ��cur�ڵ����һ���ڵ�
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
	//�ӵ�һ���ڵ㿪ʼ����
	while (cur){
		if (cur->_data == val)
			return cur;

		cur = cur->_next;
	}
	return NULL;
}

int listSize(){}

//��������
void listDestroy(list* lst){

	if (lst == NULL || lst->_head)
		return;
	//�ӵ�һ���ڵ㿪ʼ�ͷ�
	listNode* cur = lst->_head;
	while (cur){
	
		list* next = cur->_next;
		//��ʼ�ͷ�
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
	
	listPopFront(&lst);		//ͷɾ
}






int main(){


	test();




	system("pause");
	return 0;
}