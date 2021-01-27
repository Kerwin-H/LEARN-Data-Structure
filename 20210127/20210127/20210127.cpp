//β��һ������O(1)
void pushBack(seqList* sl, SLDataType val){
	//�������
	checkCapacity(sl);
	sl->_data[sl->_size] = val;
	++sl->_size;

	//insert(sl, sl->_size, val);

}

void printSeqList(seqList* sl){
	for (int i = 0; i < sl->_size; ++i){
		printf("%d ", sl->_data[i]);
	}
	printf("\n");
}

//βɾO(1)
void popBack(seqList* sl){
	if (sl == NULL)
		return;
	if (sl->_size>0)
		sl->_size--;
}


//ͷ��  1.�ƶ�Ԫ�� O(n)
//Ч�ʵ�
void pushFornt(seqList* sl, SLDataType val){

	if (sl == NULL)
		return;

	checkCapacity(sl);  //�������
	//1.����Ԫ�ص��ƶ�,�Ӻ���ǰ
	int end = sl->_size;
	while (end > 0){
		sl->_data[end] = sl->_data[end - 1];  //��������ƶ�
		--end;
	}
	//2. ͷ��
	sl->_data[0] = val;

	sl->_size++;

	//insert(sl, 0, val);

}

//ͷɾO(n)
void popFront(seqList* sl){
	if (sl == NULL || sl->_size == 0)
		return;
	int start = 1;
	while (start < sl->_size){
		sl->_data[start - 1] = sl->_data[start];
		++start;
	}
	--sl->_size;

}

//�������,ԭʼ��������ƶ�
void insert(seqList* sl, int pos, SLDataType val){
	//���
	if (sl == NULL)
		return;

	checkCapacity(sl);
	//�ƶ�Ԫ��
	int end = sl->_size;
	while (end >pos){
		sl->_data[end] = sl->_data[end - 1];
		--end;
	}
	//��������
	sl->_data[pos] = val;
	//����
	sl->_size++;

}

//ѡ��ɾ��
void erase(seqList* sl, int pos){
	if (sl == NULL || sl->_size == 0)
		return;
	if (pos >= 0 && pos < sl->_size){
		//1.(pos,size]
		int start = pos + 1;
		while (start < sl->_size){
			sl->_data[start - 1] = sl->_data[start];
			++start;
		}
		--sl->_size;
	}
}