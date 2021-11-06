#include <iostream>
#include "../include/lib_func.h"

int main()
{
    STACK s;
    initialize(&s, sizeof(int) * 2);

    int a[2] = { 5, 7 };
    push_array(&s, a, 2);
    finalize(&s);
    /*
    STACK s;

    initialize(&s, sizeof(int) * 100);

    // 文章を反対から表示する
    const char str[] = "Was it a cat I saw?";// 英語の回文

    const char *p = str;
    while (*p) {
        push(&s, (int)*p++);
    }

    int a = pop(&s);
    while (a) {
        printf_s("%c", (char)a);
        a = pop(&s);
    }

    finalize(&s);
    */
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー
