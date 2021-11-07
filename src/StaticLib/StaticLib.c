#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>

#include "../include/lib_func.h"


// mem_size の容量でスタック用のメモリを確保する
void initialize(STACK* s, size_t mem_size)
{
	if (s == NULL) return;

	s->stack_pointer = 0;
	s->stack_memory = (int*)malloc(mem_size);
	s->end = mem_size / sizeof(int);
}


// 確保したメモリを解放する
void finalize(STACK* s)
{
	if (s == NULL) return;
	// ToDo: Initializeで確保したメモリを解放しよう
	free(s->stack_memory);
	s->stack_memory = NULL;
}


// valの値をスタックに積む。実行の成否を返す
bool push(STACK *s, int val)
{
	if (s == NULL) return false;
	// ToDo: valの値をスタックに保存しよう
	int sp = s->stack_pointer, end = s->end;
	if (sp < end)
	{
		s->stack_memory[sp] = val;
		sp++;
		s->stack_pointer = sp;
		return true;
	}
	else 
	{
		return false;
	}
}


// addrから始まるnum個の整数をスタックに積む。実行の成否を返す
bool push_array(STACK* s, int* addr, int num)
{
	if (s == NULL || num <= 0) return false;
	// ToDo: addrからはじまるnum個の整数をスタックに保存しよう
	int sp = s->stack_pointer;
	if (sp + num <= s->end)
	{
		for (int i = num - 1; i >= 0; i--)
		{
			s->stack_memory[sp] = addr[i];
			sp++;
			s->stack_pointer = sp;
		}

		return true;
	}
	else 
	{
		return false;
	}
}

// スタックから一つの要素を取り出す
int pop(STACK* s)
{
	if (s == NULL) return 0;
	// ToDo: スタックの最上位の値を取り出して返そう
	int sp = s->stack_pointer;
	if (sp > 0)
	{
		sp--;
		s->stack_pointer = sp;
		return s->stack_memory[sp];
	}
	// 不具合時は0を返す
	else
	{
		return 0;
	}
}

// addrにスタックからnumの要素を取り出す。取り出せた個数を返す
int pop_array(STACK* s, int* addr, int num)
{
	if (s == NULL || num <= 0) return 0;
	// ToDo: スタックからnum個の値を取り出してaddrから始まるメモリに保存しよう
	// スタックにnum個の要素がたまっていなかたら、積まれている要素を返して、
	// 積んだ要素数を返り値として返そう
	int i, sp = s->stack_pointer;
	for (i = 0; i < num; i++)
	{
		if (sp > 0)
		{
			sp--;
			s->stack_pointer = sp;
			addr[i] = s->stack_memory[sp];
		}
		else return i;
	}
	return num;
}