//#pragma once   //∑¿÷π÷ÿ∏¥
#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;

typedef struct SeqList{
	SLDataType* _a;
	size_t _size;
	size_t _capacity;
}SeqList;

void SeqListInit(SeqList *ps);
void SeqListDestory(SeqList *ps);


void SeqListPushBack(SeqList *ps,SLDataType x);
void SeqListPopBack(SeqList *ps);
void SeqListPushFront(SeqList *ps, SLDataType x);
void SeqListPopFront(SeqList *ps);


#endif //__SEQLIST_H__
