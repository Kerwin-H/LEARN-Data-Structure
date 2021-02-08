#include"seqList.h"

typedef int SLDataType;

//#define N 10
//=====静态顺序表的定义
//struct seqList2{
//	SLDataType _data[N];		
//	size_t _size;			//有效元素的个数
//	size_t _capacity;		//当前我们可以存放的最大元素个数
//}seqList2;			//别名


//=====动态顺序表的定义
//typedef struct seqList{
//	SLDataType* _data;		//需要进行动态开辟的一个数组
//	size_t _size;			//有效元素的个数
//	size_t _capacity;		//当前我们可以存放的最大元素个数
//}seqList;			//别名


//=====对于动态静态内存大小的理解
//printf("%d\n",sizeof(seqList2));
//printf("%d\n", sizeof(seqList));


//=====接口初始化
void initSeqList(seqList * sl){
	
	sl->_data = NULL;		//传入的这个变量在data中为空
	sl->_size = sl->_capacity = 0;	//让它为0

}

//=====尾插数据
void pushBack(seqList* sl,SLDataType val){
	
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

//头删
void popFront(seqList* sl){
	
	if (sl == NULL||sl->_size==0)
		return;
	checkCapacity(sl);

	int start = 1;
	while (start < sl->_size){
		sl->_data[start-1]=sl->_data[start];
		
		++start;		//循环
	}
	--sl->_size;
}
//插入数据
void insert(seqList* sl,int pos,SLDataType val){

	if (sl == NULL)
		return;

	if (pos >= 0 && pos <= sl->_size){

		checkCapacity(sl);

		int end = sl->_size;
		while (end > pos){
			sl->_data[end] = sl->_data[end - 1];
			--end;
		}

		sl->_data[pos] = val;

		sl->_size++;
	}
}
//查找删除
void erase(seqList* sl, int pos){

	if (sl == NULL || sl->_size == 0)
		return;

	if (pos >= 0 && pos < sl->_size){
		
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

int findIdx(seqList* sl, SLDataType val){
	
	int i = 0;
	for (; i < sl->_size; ++i){
		if (sl->_data[i] == val)
			return i;
	}
	return -1;
}

void destorySeqList(seqList* sl){
	if (sl){
		if (sl->_data){
			free(sl->_data);
			sl->_data = NULL;
		}
	}
}


//=====检查空间大小,如果小,增大
void checkCapacity(seqList* sl){

	if (sl == NULL)
		return;
	//如果元素个数等于容量,则需要增容   
	if (sl->_size == sl->_capacity){
		
		int newCapacity = sl->_capacity == 0 ? 1 : 2 * sl->_capacity;
		//开空间,拷贝数据,释放原来空间
		SLDataType* tmp = (SLDataType*)malloc(sizeof(SLDataType)* newCapacity);
		memcpy(tmp, sl->_data, sizeof(SLDataType)*sl->_size);
		free(sl->_data);

		//或者直接realloc

		//更新
		sl->_data = tmp;
		sl->_capacity = newCapacity;
	}
}
//打印
void printSeqList(seqList* ls){

	for (int i = 0; i < ls->_size; ++i){
		printf("%d ",ls->_data[i]);
	}
	printf("\n");
}



void test(){
	
	seqList sl;
	initSeqList(&sl);
	pushFront(&sl, 0);
	pushFront(&sl, 1);
	pushFront(&sl, 2);
	pushFront(&sl, 3);
	printSeqList(&sl);
	insert(&sl, 2, 99);
	erase(&sl, 4);
	printSeqList(&sl);
}

int main(){

	test();

	system("pause");
	return 0;
}




//1. 空间连续
//2.支持随机访问
//3.尾插  尾删	常用
//6.空间利用率高
//4.其他位置插入删除效率低
//5.增容代价大
