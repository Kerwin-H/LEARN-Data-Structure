//尾插一个数据O(1)
void pushBack(seqList* sl, SLDataType val){
	//检查容量
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

//尾删O(1)
void popBack(seqList* sl){
	if (sl == NULL)
		return;
	if (sl->_size>0)
		sl->_size--;
}


//头插  1.移动元素 O(n)
//效率低
void pushFornt(seqList* sl, SLDataType val){

	if (sl == NULL)
		return;

	checkCapacity(sl);  //检查容量
	//1.进行元素的移动,从后向前
	int end = sl->_size;
	while (end > 0){
		sl->_data[end] = sl->_data[end - 1];  //依次向后移动
		--end;
	}
	//2. 头插
	sl->_data[0] = val;

	sl->_size++;

	//insert(sl, 0, val);

}

//头删O(n)
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

//随机插入,原始数据向后移动
void insert(seqList* sl, int pos, SLDataType val){
	//检查
	if (sl == NULL)
		return;

	checkCapacity(sl);
	//移动元素
	int end = sl->_size;
	while (end >pos){
		sl->_data[end] = sl->_data[end - 1];
		--end;
	}
	//插入数据
	sl->_data[pos] = val;
	//更新
	sl->_size++;

}

//选择删除
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