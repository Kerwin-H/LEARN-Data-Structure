#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int SLDataType;

//=====动态顺序表的定义
typedef struct seqList{
	SLDataType* _data;		//需要进行动态开辟的一个数组
	size_t _size;			//有效元素的个数
	size_t _capacity;		//当前我们可以存放的最大元素个数
}seqList;			//别名


//=====接口初始化
void initSeqList(seqList * sl);
//尾插
void pushBack(seqList* sl, SLDataType val);
//检查表是否为空
void checkCapacity(seqList* sl);
//函数打印
void printSeqList(seqList* ls);
//尾删 
void popBack(seqList* ls);
//头插
void pushFront(seqList* sl, SLDataType val);
//头删
void popFront(seqList* sl);
//指定插入
void insert(seqList* sl, int pos, SLDataType val);
//销毁
int empty(seqList* sl);
//内存大小
int size(seqList* sl);
//查找对应的值
int findIdx(seqList* sl, SLDataType val);
//释放
void destorySeqList(seqList* sl);
//指定删除
void erase(seqList* sl, int pos);

