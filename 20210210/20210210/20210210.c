#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef int LDataType;
typedef struct listNode{
	
	LDataType _data;
	struct listNode* _next;	//��һ����ŵ�ַ

}listNode;

typedef struct list{
	//��ŵ�һ���ڵ��λ��
	listNode* _head;
}list;


//��ʼ��
void listInit(list* lst){
	 
	if (lst == NULL)
		return;
	//��ʼ��Ϊ�յ�����
	lst->_head = NULL;
}
//��Ϊ������Ҫһ��һ�������ռ�ı�,��δ����Ƚ��鷳,
//����ֱ�ӽ���������ķ�ʽ���з�װ,�γ�һ���ӿ�,ÿ�ε��þͿ�����
listNode* creatNode(LDataType val){
	
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}

//β��
void listPushBack(list* lst,LDataType val){
	
	if (lst == NULL)
		return; 

	//����������һ������
	if (lst->_head == NULL){
		lst->_head=creatNode(val);
	}
	//������Ϊ�յ�ʱ�����Ҫ����һ������,Ѱ������Ԫ��,���в���
	else{
		listNode* tail = lst->_head;	//�Ƚ�ͷ��㸳��
		while (tail->_next != NULL){	//Ȼ����б���
			tail = tail->_next;			//�������������
		}
		//�������ҵ���,���øշ�װ�Ĳ��뺯���������ü���
		tail->_next = creatNode(val);
	}
}
//βɾ
void listPopBack(list* lst){
	
	if (lst== NULL||lst->_head==NULL)
		return;

	struct listNode* tail = lst->_head;
	struct listNode* prev = NULL;

	//�����ҵ����һ���ڵ�
	while (tail->_next != NULL){
		
		prev = tail;	//�ҵ�Ҫɾ���ڵ��data
		tail = tail->_next;
	}
	//ɾ���ڵ�
	free(tail);
	//�޸�ָ��
	if (prev == NULL)	//ɾ����Ϊͷ���,�����ͷ���
		lst->_head = NULL;
	else
		prev->_next = NULL; 
}
//ͷ��
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
//ͷɾ
void listPopFront(list* lst){
	
	if (lst == NULL||lst->_head==NULL)
		return;

	struct listNode* next = lst->_head->_next;
	//�ͷ�ͷ���
	free(lst->_head);
	lst->_head = next;
}
//�м����
void listInsertAfter(listNode* cur, LDataType val){
	
	listNode* node = creatNode(val);
	listNode* next = cur->_next;

	cur->_next = node;
	node->_next = next;
} 
//ɾ���ڵ�cur����һ���ڵ�
void listEraseAfter(listNode* cur){
	
	listNode* next = cur->_next;
	if (next == NULL)
		return;

	struct listNode* nextnext = next->_next;
	free(next);
	cur->_next = nextnext;
}
//����
listNode* listFind(list* lst, LDataType val){
	
	if (lst == NULL||lst->_head==NULL)
		return NULL;

	//��ͷ��ʼ����
	struct listNode* cur = lst->_head;
	while (cur){
		if (cur->_data == val)
			return cur;

		cur = cur->_next;
	}
	return NULL;
}
//�ڴ��С
//int listSize(list* lst){}

//����(ֻ��Ҫ��������ڲ����пռ��ͷ�,ͷ���ֱ��Ϊ�ռ���)
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
//�����ӡ����������
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


