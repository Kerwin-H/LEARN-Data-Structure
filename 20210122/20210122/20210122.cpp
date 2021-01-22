#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef int SLDataType;

//动态顺序表
typedef struct seqList{
	SLDataType* _data;  //动态开辟的数组
	size_t _size;		//有效元素个数
	size_t _capacity;   //可存放最大元素个数


}seqList;

void initSeqList(seqList* sl){  //注意进行初始化
	sl->_data = NULL;
	sl->_size = sl->_capacity = 0;
}




void checkCapacity(seqList* sl){

	assert(sl);//debug有效

	if (sl == NULL){
		return;
	}

	//如果元素个数和容量相同,则满了,要调整空间
	if (sl->_size == sl->_capacity){

		int newCapacity = sl->_capacity == 0 ? 1 : 2 * sl->_capacity;

		//开辟一个更大的,拷贝已有数据,释放原来空间
		SLDataType* tmp = (SLDataType*)malloc(sizeof(SLDataType)*newCapacity);
		memcpy(tmp, sl->_data, sizeof(SLDataType)* sl->_size);
		free(sl->_data);

		//另一种写法  
		//sl->_data = (SLDataType*)realloc(sl->_data, sizeof(SLDataType)*newCapacity);


		//更新
		sl->_data = tmp;
		sl->_capacity = newCapacity;

	}
}

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
		printf("%d ",sl->_data[i]);
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
void pushFornt(seqList* sl,SLDataType val){

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
	if (sl == NULL||sl->_size==0)
		return;
	int start = 1;
	while (start < sl->_size){
		sl->_data[start-1] = sl->_data[start];
		++start;
	}
	--sl->_size;

}

//随机插入,原始数据向后移动
void insert(seqList* sl,int pos,SLDataType val){
	//检查
	if (sl == NULL)
		return;

	checkCapacity(sl);
	//移动元素
	int end = sl->_size;
	while (end >pos ){
		sl->_data[end ] = sl->_data[end-1];
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
		return ;
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

int empty(seqList* sl){
	if (sl == NULL || sl->_size == 0)
		return 1;
	else
		return 0;
}

int size(seqList* sl){
	if (sl == NULL)
		return 0;
	else
		return sl->_size;

}
//查找
int find(seqList* sl, SLDataType val){
	int i = 0;
	for (i = 0; i < sl->_size; i++){
		if (sl->_data[i] == val)
			return i;
	}
	return -1;
}


//获取某一个位置
SLDataType getId(seqList* sl, int pos){
	if (pos >= 0 && pos < sl->_size)
		return sl->_data[pos];


}

void destroy(seqList* sl){
	if (sl){
		if (sl->_data){
			//释放
			free(sl->_data);
			sl->_data = NULL;
		}
	}
}

void test(){
	seqList sl;
	initSeqList(&sl);
	pushBack(&sl, 1);
	pushBack(&sl, 2);
	pushBack(&sl, 3);
	pushBack(&sl, 4);
	pushBack(&sl, 5);
	printSeqList(&sl);

	//popFront(&sl);
	//printSeqList(&sl);
	//popFront(&sl);
	//printSeqList(&sl);
	//popFront(&sl);
	//printSeqList(&sl);
	//popFront(&sl);
	//printSeqList(&sl);
	//popFront(&sl);
	//printSeqList(&sl); 

	insert(&sl, 1, 99);
	printSeqList(&sl);

	
	insert(&sl, 0, 99);  //头插

	insert(&sl, sl._size, 99);	//尾插


}






int main(){

	test();

	system("pause");
	return 0;
}





//
//顺序表:
//
//1.空间连续
//2.支持随机访问
//3.尾插 尾删效率高 O(1)
//4.空间利用高
//5.其他位置插入和删除的效率低    需要移动元素
//6.增容代价大
//
//适合于访问和保存


//eg  删除为val的数
int removeElement(int* nums, int numSize, int val){
	int idx, i;
	idx = 0;
	i = 0;
	for (; i < numSize; ++i){
		if (nums[i] != val)	nums[idx++] = nums[i];
	}
	return idx;
}