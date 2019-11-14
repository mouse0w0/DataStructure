#include <stdlib.h>
#include <stdio.h>
#include "MyString.h"

String StrCreate(int length) {
    return malloc((length + 1) * sizeof(char));
}

int StrLength(String value) {
    int length = 0;
    while (*(value++)) length++;
    return length;
}

void StrAssign(String s, String value) {
    while (*value) *(s++) = *(value++);
    *s = '\0';
}

void StrConcat(String s1, String s2) {
    while (*s1) s1++;
    while (*s2) *(s1++) = *(s2++);
    *s1 = '\0';
}

String SubStr(String s, int start, int length) {
    String result = StrCreate(length);
    int i;
    for (i = 0; i < length && s[start + i] != '\0'; i++) {
        result[i] = s[start + i];
    }
    result[length] = '\0';
    return result;
}

int StrCmp(String s1, String s2) {
    while (*s1 && *s2) {
        char c1 = *(s1++), c2 = *(s2++);
        if (c1 > c2) return 1;
        else if (c1 < c2) return -1;
    }
    return *s1 == *s2 ? 0 : *s1 > *s2 ? 1 : -1;
}

int StrIndex(String s, String t) {
    return StrIndexWithStart(s, 0, t);
}

int StrIndexWithStart(String s, int start, String t) {
    int tLength = StrLength(t);
    int *f = malloc(tLength * sizeof(int));
    f[0] = -1;
    int i, j;
    for (j = 1; j < tLength; j++) {
        for (i = f[j - 1];; i = f[i]) {
            if (t[j] == t[i + 1]) {
                f[j] = i + 1;
                break;
            } else if (i == -1) {
                f[j] = -1;
                break;
            }
        }
    }

    for (i = start, j = 0; s[i] && t[j];) {
        if (s[i] == t[j]) {
            i++;
            j++;
        } else if (j == 0)
            i++;
        else
            j = f[j - 1] + 1;
    }
    free(f);
    return j == tLength ? i - tLength : -1;
}

void StrInsert(String s, int i, String t) {
    int sLength = StrLength(s);
    int tLength = StrLength(t);
    for (int j = sLength; j >= i; --j) s[tLength + j] = s[j];
    for (int j = 0; j < tLength; ++j) s[i + j] = t[j];
}

void StrDelete(String s, int start, int length) {
    s += start;
    while (*s) {
        *s = *(s + length);
        s++;
    }
    *s = '\0';
}

void StrRep(String s, String t, String r) {
    int tLength = StrLength(t);
    int start = 0;
    int end = 0;
    while ((start = StrIndexWithStart(s, end, t)) != -1) {
        StrDelete(s, start, tLength);
        StrInsert(s, start, r);
        end = start + tLength;
    }
}

int main() {
    String s = StrCreate(100);
    StrAssign(s, "Hello!");
    printf("%s\n", s);
    printf("%d\n", StrLength(s));
    StrConcat(s, "World!");
    printf("%s\n", s);
    printf("%s\n", SubStr(s, 6, 6));
    printf("%d\n", StrCmp(s, "Hello!"));
    printf("%d\n", StrIndex(s, "World!"));
    StrInsert(s, 6, " ");
    printf("%s\n", s);
    StrDelete(s, 5, 1);
    printf("%s\n", s);
    StrRep(s, "World", "world");
    printf("%s\n", s);
}