//#include<stdio.h>
#include<stdlib.h>
//
////===ʱ�临�Ӷ�
////F(N)=N^2+2N+10���еĴ��� 
//void Func1(int N) {			//O(N^2)
//	int count = 0;
//	for (int i = 0; i < N; ++i) {
//		for (int j = 0; j < N; ++j)
//		{
//			++count;
//		}
//	}
//for (int k = 0; k < 2 * N; ++k) {
//	++count;
//}
//int M = 10;
//while (M--) {
//	++count;
//}
//printf("%d\n", count);
//}
//
////����
//
////F(N)=2N+2
//void Func2(int N) {	//O(N)=N
//	int count = 0;
//	for (int k = 0; k < 2 * N; ++k) {
//		++count;
//	}
//	int M = 10;
//	while (M--) {
//		++count;
//	}
//	printf("%d\n", count);
//}
//
////M+N
//void Func3(int N, int M) {
//	int count = 0;
//	for (int k = 0; k < M; ++k) {
//		++count;
//	}
//	for (int k = 0; k < N; ++k) {
//		++count;
//	}
//	printf("%d\n", count);
//}
//
//
////O(1)
//void Func4(int N) {
//	int count = 0;
//	for (int k = 0; k < 100; ++k) {
//		++count;
//	}
//	printf("%d\n", count);
//}
//
//
////�������ն��ֲ��Һ�ð�������ʱ�临�Ӷ�
//// O(N^2)
//long long Fibonacci(size_t N) {
//	return N < 2 ? N : Fibonacci(N - 1) + Fibonacci(N - 2);
//}
//
//
////===�ռ临�Ӷ�
////�׳�ʱ�临�Ӷ�O(n)
//
//
//
////=========================================����
////˳���:������������

#include"SeqList.h"

void TestSeqList1(){
	SeqList s;
 	SeqListInit(&s);
}

int main(){

	TestSeqList1();

	system("pause");
	return 0;
}