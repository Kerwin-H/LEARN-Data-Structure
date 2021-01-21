#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>


typedef int SLDataType;


//静态顺序表
//#define N 10
//typedef struct seqList2{
//	SLDataType _deta[N];  //开辟内存 
//	size_t _size;
//	size_t _capacity;
//
//}seqList2;


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

//尾插一个数据
void pushBack(seqList* sl, SLDataType val){
	//检查容量
	checkCapacity(sl);
	sl->_data[sl->_size] = val;
	++sl->_size;
}

void test(){
	seqList sl;
	initSeqList(&sl);
	pushBack(&sl, 1);
	pushBack(&sl, 2);
	pushBack(&sl, 3);
	pushBack(&sl, 4);
	pushBack(&sl, 5);
	

}



//void test(){
	//printf("静态:%d\n",sizeof(seqList2));
	//printf("动态:%d\n", sizeof(seqList));

//}




int main(){

//	//关于时间复杂度
//	int N;
//	for (int i = 0; i < N; ++i) {
//		for (int i = 0; i < N; ++i){
//			//如果像这种嵌套,则O(n)=N^2
//	}
//}
//
//	for (int i = 0; i < 2 * N; ++i)
//		//O(n)=2N
//
//
//		//渐进时间复杂度
//		//一般对于时间复杂度,只取最高此项,并去除系数
//
//		
//	for (int i = 0; i < M ++i)
//	for (int i = 0; i < N; ++i)
//		//O(N+M)
//
//
//
//	for (int i = 0; i < 100; ++i)
//		//O(1)   常数都是1
//
//
//	//求strchr时间复杂度
//		const char * strchr(const char * str, int character);
//	//按照搜索的最坏情况,O(n)来算
//
//
//	//冒泡排序n^2
//
//
//
//
//	//递归调用  求时间复杂度
//	long long Factorial(size_t N) {
//		return N < 2 ? N : Factorial(N - 1)*N;
//	}
//	//O(n)  看基本操作的执行次数
//
//	long long Fibonacci(size_t N) {
//		return N < 2 ? N : Fibonacci(N - 1) + Fibonacci(N - 2);
//	}
	//因为他是两边依次调用递归,所以为O(2^n)


	//空间复杂度看变量个数,找出其中含有的创建变量


	test();



	system("pause");
	return 0;
}