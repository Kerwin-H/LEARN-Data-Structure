void listErase(List* lst, struct ListNode* node){

	//不能删除head结点
	if (lst == NULL || lst->_head == node)
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