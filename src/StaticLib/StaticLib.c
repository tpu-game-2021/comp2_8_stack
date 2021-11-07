#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>

#include "../include/lib_func.h"


// mem_size の容量でスタック用のメモリを確保する
void initialize(STACK* s, size_t mem_size)
{
	if (s == NULL) return;

	s->stack_pointer = NULL;
	s->stack_memory = NULL;
	s->end = NULL;
}


// 確保したメモリを解放する
void finalize(STACK* s)
{
	free(&s);
	// ToDo: Initializeで確保したメモリを解放しよう
}


// valの値をスタックに積む。実行の成否を返す
bool push(STACK* s, int val)
{
	if (s == !NULL)
	{
	s = val;
		return true;
	}
	else
	{
		return false;
	}
	return false;
}


// addrから始まるnum個の整数をスタックに積む。実行の成否を返す
bool push_array(STACK* s, int* addr, int num)
{
	int i;
	for (i = 0; i < num; i++) {
		s = addr;
	}
	if (i == num) {
		return true;
	}
	else {
		return false;
	}
	// ToDo: addrからはじまるnum個の整数をスタックに保存しよう
	
}

// スタックから一つの要素を取り出す
int pop(STACK* s)
{
	int x;
	x = s;
	if (x != NULL)
		return x;
	else
		return 0;
	
}

// addrにスタックからnumの要素を取り出す。取り出せた個数を返す
int pop_array(STACK* s, int* addr, int num)
{
	// ToDo: スタックからnum個の値を取り出してaddrから始まるメモリに保存しよう
	// スタックにnum個の要素がたまっていなかたら、積まれている要素を返して、
	// 積んだ要素数を返り値として返そう
	return 0;
}