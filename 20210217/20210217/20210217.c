//=====尾插数据
void pushBack(seqList* sl, SLDataType val){

	checkCapacity(sl);
	sl->_data[sl->_size] = val;		//将size 也就是表中的最后一个数据进行插入
	++sl->_size;	//依次进行
}

//=====尾删
void popBack(seqList* ls){

	if (ls == NULL)
		return;
	if (ls->_size > 0)
		ls->_size--;
}

//头插,效率高
void pushFront(seqList* sl, SLDataType val){

	if (sl == NULL)
		return;
	checkCapacity(sl);
	//1.移动元素
	int end = sl->_size;
	while (end > 0){
		sl->_data[end] = sl->_data[end - 1];

		--end;		//这里是依次循环的意思
	}
	//2.头插
	sl->_data[0] = val;

	sl->_size++;
}