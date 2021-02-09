#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int SLDataType;

//=====��̬˳���Ķ���
typedef struct seqList{
	SLDataType* _data;		//��Ҫ���ж�̬���ٵ�һ������
	size_t _size;			//��ЧԪ�صĸ���
	size_t _capacity;		//��ǰ���ǿ��Դ�ŵ����Ԫ�ظ���
}seqList;			//����


//=====�ӿڳ�ʼ��
void initSeqList(seqList * sl);
//β��
void pushBack(seqList* sl, SLDataType val);
//�����Ƿ�Ϊ��
void checkCapacity(seqList* sl);
//������ӡ
void printSeqList(seqList* ls);
//βɾ 
void popBack(seqList* ls);
//ͷ��
void pushFront(seqList* sl, SLDataType val);
//ͷɾ
void popFront(seqList* sl);
//ָ������
void insert(seqList* sl, int pos, SLDataType val);
//����
int empty(seqList* sl);
//�ڴ��С
int size(seqList* sl);
//���Ҷ�Ӧ��ֵ
int findIdx(seqList* sl, SLDataType val);
//�ͷ�
void destorySeqList(seqList* sl);
//ָ��ɾ��
void erase(seqList* sl, int pos);

