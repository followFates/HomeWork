/*************************************************************************
	> File Name: fast_scanf.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年09月18日 星期二 19时53分54秒
 ************************************************************************/


#include <stdio.h>

char ss[1<<17], *A = ss, *B = ss; //A为缓冲区的头，B为缓冲区的尾
inline char gc() {
    return A == B && (B = (A = ss) + fread(ss, 1, 1<<17, stdin), A == B) ? -1 : *A++;
}

template<typename T> inline void sdf(T &x) {      //快速读入整型字符
    char c;
    T y = 1;
    while (c = gc(), (c < 48 || c > 57) && c != -1) {
        if (c == '-') y = -1;
    }
    x = c ^ 48;
    while (c = gc(), (c <= 57 && c >= 48)) {
        x = (x << 1) + (x << 3) + (c ^ 48);
    }
    x *= y;
}

int main() {
    for (int i = 48; i < 57; i++) {
        printf("%d ^ 48 = %d\n", i, i ^ 48);
    }
    int n, a;
    sdf(n);
    for (int i = 0; i < n; i++) {
        sdf(a);
    }
    return 0;
}
