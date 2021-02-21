#include<stdio.h>
#include<stdlib.h>

typedef char DataType;

typedef struct BNode{

	DataType _data;
	struct BNode* _left;
	struct BNode* _right;
}BNode;


//ABD##E#H##CF##G##\
//创建树
BNode* creatBTree(DataType arr[], int* idx){
	
	if (arr[*idx] == '#'){
		
		(*idx)++;
		return NULL;
	}
	else{
		//创建以当前为根的子树
		BNode* root = (BNode*)malloc(sizeof(BNode));
		root->_data = arr[*idx];
		++(*idx);
		 

		root->_left=creatBTree(arr, idx);
		root->_right = creatBTree(arr, idx);
		return root;
	}
}

//前序遍历
void preOrder(BNode* root){
	
	if (root){
		//根  左子树  右子树
		printf("%c ", root->_data);
		preOrder(root->_left);
		preOrder(root->_right);
	}
}

//中序遍历
void inOrder(BNode* root){
	if (root){
		//左子树  根  右子树
		inOrder(root->_left);
		printf("%c ", root->_data);
		inOrder(root->_right);
	}
}

//后序遍历
void postOrder(BNode* root){
	if (root){
		//左子树    右子树  根
		postOrder(root->_left);
		postOrder(root->_right);
		printf("%c ", root->_data);
	}
}

//节点数
int bTreeSize(BNode* root){
	
	if (root == NULL)
		return 0;
	//root左子树+右子树+1
	return bTreeSize(root->_left) + bTreeSize(root->_right) + 1;
}

//叶子数
int bTreeLeafSize(BNode* root){
	
	if (root == NULL)
		return 0;
	else if (root->_left == NULL&&root->_right == NULL)
		return 1;
	//左右子树的叶子和
	return bTreeLeafSize(root->_left) + bTreeLeafSize(root->_right);

}

//第K层的节点数
int bTreeKSize(BNode* root,int k){
	
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	//左右子树第K-1层节点和
	return bTreeKSize(root->_left, k - 1) + bTreeKSize(root->_right, k - 1);
}
//查找
BNode* bTreeFind(BNode* root, DataType ch){
	
	BNode* node;
	if (root == NULL)
		return NULL;
	if (root->_data == ch)
		return root;
	//左子树
	node= bTreeFind(root->_left, ch);
	if (node)
		return node;
	//右子树
	return bTreeFind(root->_right, ch);
}

//销毁
void bTreeDestory(BNode** root){
	
	bTreeDestory(&(*root)->_left);
	bTreeDestory(&(*root)->_right);
	free(*root);
	*root == NULL;
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

	printf("size:%d \n",bTreeSize(root));

	printf("leafsize:%d \n", bTreeLeafSize(root));

	printf("Ksize:%d \n", bTreeKSize(root,3));

	node = bTreeFind(root, 'G');
	printf("%p-->%c \n",node,*node);

	bTreeDestory(&root);
}

int main(){
	
	test();
	

	system("pause");
	return 0;
}