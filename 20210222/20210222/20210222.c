//========================================1.��������ǰ�����,�ݹ�
int getSize(struct TreeNode* root){

	if (root){

		return  getSize(root->left) + getSize(root->right) + 1;
	}
	return 0;
}

void preorder(struct TreeNode* root, int* arr, int* idx){

	if (root){

		arr[*idx] = root->val;
		(*idx)++;
		preorder(root->left, arr, idx);
		preorder(root->right, arr, idx);
	}
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){

	int sz = getSize(root);
	int* arr = (int*)malloc(sizeof(int)*sz);
	int idx = 0;
	preorder(root, arr, &idx);
	*returnSize = idx;
	return arr;
}
//=============================================2.ǰ������ķǵݹ�
int* preorderTraversal(struct TreeNode* root, int* returnSize){

	int sz = getSize(root);
	int* arr = malloc(sizeof(int)*sz);
	stack st;
	stackInit(&st);
	int idx;
	//��ǰ�����Ľڵ㲻Ϊ��,��ջ��Ϊ��
	while (root || !stackEmpty(&st)){

		//1.�������·��
		while (root){

			arr[idx++] = root->val;
			//��ǰ�ڵ���ջ
			stackPush(&st, root);
			root = root->left;
		}
		//2.��ȡջ��Ԫ��,����������
		root = stackTop(&st);
		stackPop(&st);
		root = root->right;
	}
	*returnSize = idx;
	return arr;
}
//=========================================3.������� �ǵݹ�
int* inorderTraversal(struct TreeNode* root, int* returnSize){

	int sz = getSize(root);
	int* arr = malloc(sizeof(int)*sz);
	stack st;
	stackInit(&st);
	int idx = 0;

	while (root || !stackEmpty(&st)){

		//1.�ȱ������
		while (root){

			stackPush(&st, root);
			root = root->left;
		}
		//2.��ȡջ��Ԫ��

		root = stackTop(&st);
		stackPop(&st);
		arr[idx++] = root->val;

		//3.����������
		root = root->right;
	}
	*returnSize = idx;
	return arr;
}
//===========================================4.������� �ǵݹ�
int* postorderTraversal(struct TreeNode* root, int* returnSize){

	int sz = getSize(root);
	int* arr = (int*)malloc(sizeof(int)*sz);
	stack st;
	stackInit(&st);
	int idx = 0;
	//prev:�ϴη��ʼǵýڵ�λ��
	struct TreeNode* prev = NULL;
	while (root || !stackEmpty(&st)){

		//1.������·��
		while (root){

			stackPush(&st, root);
			root = root->left;
		}
		//top:ջ���Ľڵ�
		struct TreeNode* top = stackTop(&st);
		//����Ҫ�����ж��Ƿ��ܷ���ջ��
		//����:û�������������������������
		if (top->right == NULL || top->right == prev){

			//����ջ��Ԫ��
			arr[idx++] = top->val;
			stackPop(&st);

			prev = top;
		}
		else
			//����������
			root = top->right;
	}
	*returnSize = idx;
	return arr;
}