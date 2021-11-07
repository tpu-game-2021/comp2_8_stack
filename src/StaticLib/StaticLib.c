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
    if (s->stack_memory == NULL) exit(0);

	s->end = mem_size;
}


// 確保したメモリを解放する
void finalize(STACK* s)
{
	// ToDo: Initializeで確保したメモリを解放しよう
	if (s == NULL) return;

	free(s->stack_memory);

	s->stack_memory = NULL;
	s->end = NULL;
}


// valの値をスタックに積む。実行の成否を返す
bool push(STACK* s, int val)
{
	// ToDo: valの値をスタックに保存しよう
	if (val == NULL || s == NULL) return false;

	if (s->stack_pointer >= s->end) 
	{
		return false;
	}

	s->stack_memory[s->stack_pointer] = val;
	s->stack_pointer += sizeof(int);

	return true;	
}


// addrから始まるnum個の整数をスタックに積む。実行の成否を返す
bool push_array(STACK* s, int* addr, int num)
{
	// ToDo: addrからはじまるnum個の整数をスタックに保存しよう
	if (s == NULL) return false;

	if (s->stack_pointer + (sizeof(int) * num) > s->end) 
	{
		return false;
	}

	for (int i = 0; i < num; i++)
	{
		s->stack_memory[s->stack_pointer] = addr[num - 1 - i];
		s->stack_pointer += sizeof(int);
	}

	return true;
}

// スタックから一つの要素を取り出す
int pop(STACK* s)
{
	// ToDo: スタックの最上位の値を取り出して返そう
	// 不具合時は0を返す
    if (s == NULL) return 0;

	if (s->stack_pointer <= 0) 
	{
		return 0;
	}

	s->stack_pointer -= sizeof(int);

	return s->stack_memory[s->stack_pointer];
}

// addrにスタックからnumの要素を取り出す。取り出せた個数を返す
int pop_array(STACK* s, int* addr, int num)
{
	// ToDo: スタックからnum個の値を取り出してaddrから始まるメモリに保存しよう
	// スタックにnum個の要素がたまっていなかたら、積まれている要素を返して、
	// 積んだ要素数を返り値として返そう
	if (s == NULL) return 0;

	int i, count = 0;

	for (i = 0; i < num; i++)
	{
		s->stack_pointer -= sizeof(int);

		if (s->stack_pointer < 0)
		{
			break;
		}

		addr[i] = s->stack_memory[s->stack_pointer];
		count++;
	}

	return count;
}