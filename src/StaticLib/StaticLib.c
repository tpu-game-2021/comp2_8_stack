#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>

#include "../include/lib_func.h"


// mem_size の容量でスタック用のメモリを確保する
void initialize(STACK* s, size_t mem_size)
{
	if (s == NULL) return;

	s->stack_pointer = NULL;
	s->stack_memory = (int*)malloc(mem_size);
	s->end = s->stack_memory + mem_size;

	s->stack_pointer = s->end;
}


// 確保したメモリを解放する
void finalize(STACK* s)
{
	if (s == NULL) return;
	if (s->stack_pointer == NULL) return;
	free(s->stack_memory);
	s->stack_pointer = NULL;
	s->end = NULL;
}


// valの値をスタックに積む。実行の成否を返す
bool push(STACK* s, int val)
{
	if (s == NULL) return false;

	if (*(s->stack_pointer) - sizeof(int) > *(s->stack_memory)) return false;
	*(s->stack_pointer) -= sizeof(int);
	
	*(s->stack_pointer) = val;
	return (*s->stack_pointer == val) ? true : false;
}


// addrから始まるnum個の整数をスタックに積む。実行の成否を返す
bool push_array(STACK* s, int* addr, int num)
{
	if (s == NULL) return false;
	int i;
	for (i = 0; i < num; i++)
	{
		if (*(s->stack_pointer) - sizeof(int) > *(s->stack_memory)) return false;
		*(s->stack_pointer) -= sizeof(int);

		*(s->stack_pointer) = addr[i];
		return (*s->stack_pointer == addr[i]) ? true : false;
	}
	return false;
}

// スタックから一つの要素を取り出す
int pop(STACK* s)
{
	if (s == NULL) return 0;
	if (s->stack_pointer == s->end) return 0;

	int val;

	val = *(s->stack_pointer);
	*(s->stack_pointer) += sizeof(int);
	return val;

	return 0;
}

// addrにスタックからnumの要素を取り出す。取り出せた個数を返す
int pop_array(STACK* s, int* addr, int num)
{
	if (s == NULL) return false;
	int i;
	int val;
	for (i = 0; i < num; i++)
	{
		addr[i] = *(s->stack_pointer);
		*(s->stack_pointer) += sizeof(int);
	}
	return i;

	return 0;
}