/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

//=================================================1.单值二叉树
bool _isUnivalTree(struct TreeNode* root, int val){

	if (root){

		return root->val == val
			&& _isUnivalTree(root->left, val)
			&& _isUnivalTree(root->right, val);
	}
	return true;
}

bool isUnivalTree(struct TreeNode* root){
	if (root == NULL)
		return true;
	return _isUnivalTree(root, root->val);
}

//==================================================2.翻转二叉树
struct TreeNode* invertTree(struct TreeNode* root){

	if (root == NULL)
		return NULL;
	//交换左右子树
	struct TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	invertTree(root->left);
	invertTree(root->right);
	return root;
}
//===================================================3.相同的树
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if (p == NULL&&q == NULL)
		return true;
	//没有同时到达NULL
	if (p == NULL || q == NULL)
		return false;
	return p->val == q->val
		&& isSameTree(p->left, p->left)
		&& isSameTree(q->left, q->left);
}
//====================================================4.另一个树的子树
bool isSameTree(struct TreeNode* p, struct TreeNode* q){

	if (p == NULL&&q == NULL)
		return true;
	//没有同时到达NULL
	if (p == NULL || q == NULL)
		return false;
	return p->val == q->val
		&&isSameTree(p->left, q->left)
		&& isSameTree(p->right, q->right);
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t){

	if (t == NULL)
		return true;
	if (s == NULL)
		return false;
	return isSameTree(s, t)
		|| isSubtree(s->left, t)
		|| isSubtree(s->right, t);
}
//==================================================5.对称二叉树
bool _isSym(struct TreeNode* left, struct TreeNode* right){

	if (left == NULL&&right == NULL)
		return true;
	if (left == NULL || right == NULL)
		return false;
	return left->val == right->val
		&& _isSym(left->left, right->right)
		&& _isSym(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root){
	if (root == NULL)
		return true;
	return _isSym(root->left, root->right);
}
//====================================================6.平衡二叉树
int getHeight(struct TreeNode* root){

	if (root){

		int left = getHeight(root->left);
		int right = getHeight(root->right);
		return left>right ? left + 1 : right + 1;
	}
	return 0;
}

bool isBalanced(struct TreeNode* root){
	if (root == NULL)
		return true;
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	//当前节点的左右子树插差<2
	return abs(left - right)<2
		&& isBalanced(root->left)
		&& isBalanced(root->right);
}