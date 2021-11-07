#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>

#include "../include/lib_func.h"


// mem_size の容量でスタック用のメモリを確保する
void initialize(STACK* s, size_t mem_size)
{
	if (s == NULL)
		return;


	s->stack_pointer = (int*)malloc(sizeof(int) * mem_size);
	s->stack_memory = 0;
	s->end = mem_size;
}


// 確保したメモリを解放する
void finalize(STACK* s)
{
	if (s == NULL)
		return;

	free(s->stack_pointer);
	s->stack_pointer = NULL;
	s->stack_memory = NULL;
	s->end = NULL;

	// ToDo: Initializeで確保したメモリを解放しよう
}


// valの値をスタックに積む。実行の成否を返す
bool push(STACK* s, int val)
{
	if (val == NULL || s == NULL)
		return false;

	int a = s->stack_memory;



	if (s->stack_memory < s->end)
		s->stack_memory++;

	s->stack_pointer[a] = val;


	return true;
	// ToDo: valの値をスタックに保存しよう
}


// addrから始まるnum個の整数をスタックに積む。実行の成否を返す
bool push_array(STACK* s, int* addr, int num)
{

	if (addr == NULL || s == NULL || num <= 0||num>s->end)
		return false;


	s->stack_memory = 0;


	for (int i = 0; i < num; i++) {

		if (s->stack_memory > s->end)
			s->stack_memory++;

		s->stack_pointer[i] = addr[i];
	}
	// ToDo: addrからはじまるnum個の整数をスタックに保存しよう
	return true;
}


// スタックから一つの要素を取り出す
int pop(STACK* s)
{
	if (s == NULL)
		return 0;

	int a, b;


	if (s->stack_memory > 0)
		s->stack_memory--;

	a = s->stack_memory;
	b = s->stack_pointer[a];


	return b;

	// ToDo: スタックの最上位の値を取り出して返そう
	// 不具合時は0を返す
}

// addrにスタックからnumの要素を取り出す。取り出せた個数を返す
int pop_array(STACK* s, int* addr, int num)
{
	if (s == NULL || addr == NULL || num <= 0||num>s->end)
		return 0;

	int x=0;

	for (int i = 0; i < num; i++) {
		int a, b;
		if (s->stack_memory > 0)
			s->stack_memory--;

		x++;

		addr[i]= s->stack_pointer[i];
	}
	// ToDo: スタックからnum個の値を取り出してaddrから始まるメモリに保存しよう
	// スタックにnum個の要素がたまっていなかたら、積まれている要素を返して、
	// 積んだ要素数を返り値として返そう
	return x;
}