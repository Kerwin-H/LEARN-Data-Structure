//=====β������
void pushBack(seqList* sl, SLDataType val){

	checkCapacity(sl);
	sl->_data[sl->_size] = val;		//��size Ҳ���Ǳ��е����һ�����ݽ��в���
	++sl->_size;	//���ν���
}

//=====βɾ
void popBack(seqList* ls){

	if (ls == NULL)
		return;
	if (ls->_size > 0)
		ls->_size--;
}

//ͷ��,Ч�ʸ�
void pushFront(seqList* sl, SLDataType val){

	if (sl == NULL)
		return;
	checkCapacity(sl);
	//1.�ƶ�Ԫ��
	int end = sl->_size;
	while (end > 0){
		sl->_data[end] = sl->_data[end - 1];

		--end;		//����������ѭ������˼
	}
	//2.ͷ��
	sl->_data[0] = val;

	sl->_size++;
}