#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

typedef char DataType;

typedef struct BNode{

	DataType _data;
	struct BNode* _left;
	struct BNode* _right;
}BNode;


//ABD##E#H##CF##G##\
//������
BNode* creatBTree(DataType arr[], int* idx){

	if (arr[*idx] == '#'){

		(*idx)++;
		return NULL;
	}
	else{
		//�����Ե�ǰΪ��������
		BNode* root = (BNode*)malloc(sizeof(BNode));
		root->_data = arr[*idx];
		++(*idx);


		root->_left = creatBTree(arr, idx);
		root->_right = creatBTree(arr, idx);
		return root;
	}
}

////ǰ�����
//void preOrder(BNode* root){
//
//	if (root){
//		//��  ������  ������
//		printf("%c ", root->_data);
//		preOrder(root->_left);
//		preOrder(root->_right);
//	}
//}
//
////�������
//void inOrder(BNode* root){
//	if (root){
//		//������  ��  ������
//		inOrder(root->_left);
//		printf("%c ", root->_data);
//		inOrder(root->_right);
//	}
//}
//
////�������
//void postOrder(BNode* root){
//	if (root){
//		//������    ������  ��
//		postOrder(root->_left);
//		postOrder(root->_right);
//		printf("%c ", root->_data);
//	}
//}
//
////�ڵ���
//int bTreeSize(BNode* root){
//
//	if (root == NULL)
//		return 0;
//	//root������+������+1
//	return bTreeSize(root->_left) + bTreeSize(root->_right) + 1;
//}
//
////Ҷ����
//int bTreeLeafSize(BNode* root){
//
//	if (root == NULL)
//		return 0;
//	else if (root->_left == NULL&&root->_right == NULL)
//		return 1;
//	//����������Ҷ�Ӻ�
//	return bTreeLeafSize(root->_left) + bTreeLeafSize(root->_right);
//
//}
//
////��K��Ľڵ���
//int bTreeKSize(BNode* root, int k){
//
//	if (root == NULL)
//		return 0;
//	if (k == 1)
//		return 1;
//	//����������K-1��ڵ��
//	return bTreeKSize(root->_left, k - 1) + bTreeKSize(root->_right, k - 1);
//}
////����
//BNode* bTreeFind(BNode* root, DataType ch){
//
//	BNode* node;
//	if (root == NULL)
//		return NULL;
//	if (root->_data == ch)
//		return root;
//	//������
//	node = bTreeFind(root->_left, ch);
//	if (node)
//		return node;
//	//������
//	return bTreeFind(root->_right, ch);
//}
//
////����
//void bTreeDestory(BNode** root){
//
//	bTreeDestory(&(*root)->_left);
//	bTreeDestory(&(*root)->_right);
//	free(*root);
//	*root == NULL;
//}


//�������
void bTreeLevelOrder(BNode* root){

	//�������б���ڵ�
	Queue q;
	queueInit(&q);
	//���ڵ�������
	if (root)
		queuePush(&q, root);
	//���������л��ÿһ���ڵ�
	while (!queueEmpty(&q)){
		
		//��ȡ��ͷԪ��
		BNode* front = queueFront(&q);
		//����
		queuePop(&q);

		printf("%d ",front->_data);

		//�����ͷԪ�ص����Һ��ӽڵ�
		if (front->_left)
			queuePush(&q, front->_left);
		if (front->_right)
			queuePush(&q, front->_right);
	}
	printf("\n");
} 

//�Ƿ�Ϊ��ȫ������
//�������,�ڵ�����,�м�û�нڵ�
int isCompleteBtree(BNode* root){
	
	Queue q;
	queueInit(&q);
	if (root)
		queuePush(&q, root);
	while (!queueEmpty(&q)){
		
		//��ȡ��ͷԪ��
		BNode* front = queueFront(&q);
		queuePop(&q);
		//���Һ������
		if (front){

			queuePush(&q, front->_data);
			queuePush(&q, front->_right);
		}
		else
			break;
	}
	//�鿴ʣ��Ԫ�����Ƿ��зǿսڵ�
	while (!queueEmpty(&q)){
		
		BNode* front = queueFront(&q);
		if (front)
			//���ʣ��Ԫ���д��ڷǿսڵ�,�������
			return 0;
	}
	//���еĶ�����
	return 1;
}




void test(){

	char arr[] = "ABD##E#H##CF##G##";
	int idx = 0;
	BNode* root = creatBTree(arr, &idx);

	BNode* node;

	preOrder(root);
	printf("\n");
	inOrder(root);
	printf("\n");
	postOrder(root);
	printf("\n");

	printf("size:%d \n", bTreeSize(root));

	printf("leafsize:%d \n", bTreeLeafSize(root));

	printf("Ksize:%d \n", bTreeKSize(root, 3));

	node = bTreeFind(root, 'G');
	printf("%p-->%c \n", node, *node);

	bTreeDestory(&root);
}

int main(){

	test();


	system("pause");
	return 0;
}