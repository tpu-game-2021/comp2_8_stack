#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>

#include "../include/lib_func.h"


// mem_size の容量でスタック用のメモリを確保する
void initialize(STACK* s, size_t mem_size)
{
	if (s == NULL) return;
	int* p = (int*)malloc(mem_size);

	if (p == NULL) {
		s->stack_pointer = NULL;
		s->stack_memory = NULL;
		s->end = NULL;
		return;
	}

	s->stack_memory = p;
	s->end = p + mem_size / sizeof(int);
	s->stack_pointer = s->end;
}


// 確保したメモリを解放する
void finalize(STACK* s)
{
	if (s == NULL || s->stack_memory == NULL) return;

	free(s->stack_memory);

	s->stack_memory = NULL;
	s->end = NULL;
	s->stack_pointer = NULL;
}


// valの値をスタックに積む。実行の成否を返す
bool push(STACK* s, int val)
{
	if (s == NULL || s->stack_memory == NULL) return false;
	if (s->stack_pointer <= s->stack_memory) return false;

	s->stack_pointer--;
	*s->stack_pointer = val;

	return true;
}


// addrから始まるnum個の整数をスタックに積む。実行の成否を返す
bool push_array(STACK* s, int* addr, int num)
{
	if (s == NULL || s->stack_memory == NULL) return false;
	if (s->stack_pointer - num < s->stack_memory) return false;
	if (num <= 0) return false;

	s->stack_pointer -= num;
	memcpy(s->stack_pointer, addr, sizeof(int) * num);

	return true;
}

// スタックから一つの要素を取り出す
int pop(STACK* s)
{
	if (s == NULL || s->stack_memory == NULL) return false;
	if (s->end <= s->stack_pointer) return 0;

	return *s->stack_pointer++;
}

// addrにスタックからnumの要素を取り出す。取り出せた個数を返す
int pop_array(STACK* s, int* addr, int num)
{
	if (s == NULL || s->stack_memory == NULL) return false;

	int n = s->end - s->stack_pointer;
	if (n <= 0) return 0;
	if (n < num) { num = n; }

	memcpy(addr, s->stack_pointer, sizeof(int) * num);
	s->stack_pointer += num;

	return num;
}