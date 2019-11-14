#include <stdlib.h>
#include <stdio.h>
#include "includes/String.h"

String StrCreate(char *value) {
    String s;
    StrAssign(&s, value);
    return s;
}

int StrLength(String value) {
    int length = 0;
    while (*(value++)) length++;
    return length;
}

void StrAssign(StringRef ref, String value) {
    String s = *ref = malloc((StrLength(value) + 1) * sizeof(char));
    while (*value) *(s++) = *(value++);
    *s = '\0';
}

void StrConcat(StringRef ref, String s2) {
    String s1 = *ref;
    String s = *ref = malloc((StrLength(s) + StrLength(s2) + 1) * sizeof(char));
    while (*s1) *(s++) = *(s1++);
    while (*s2) *(s++) = *(s2++);
    *s = '\0';
}

String SubStr(String s, int start, int length) {
    String result = malloc((length + 1) * sizeof(char));
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
    return 0;
}

int StrIndex(String s, String t) {
    int tLength = StrLength(t);
    int *f = (int *) malloc(tLength * sizeof(int));
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

    for (i = 0, j = 0; s[i] && t[j];) {
        if (s[i] == t[j]) {
            i++;
            j++;
        } else if (j == 0)
            i++;
        else
            j = f[j - 1] + 1;
    }
    return j == tLength ? i - tLength : -1;
}

int StrIndexWithStart(String s, int start, String t) {
    int tLength = StrLength(t);
    int *f = (int *) malloc(tLength * sizeof(int));
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
    return j == tLength ? i - tLength : -1;
}

void StrInsert(StringRef ref, int i, String t) {
    String s = *ref;
    int sLen = StrLength(s), tLen = StrLength(t);
    *ref = malloc((sLen + tLen + 1) * sizeof(char));
    for (int j = 0; j < i && j < sLen; ++j) (*ref)[j] = s[j];
    for (int j = 0; j < tLen; ++j) (*ref)[i + j] = t[j];
    for (int j = i; j < sLen; ++j) (*ref)[tLen + j] = s[j];
}

void StrDelete(StringRef ref, int start, int length) {
    String oldString = *ref;
    int oldLength = StrLength(oldString);
    if (oldLength > start + length) {
        int newLength = oldLength - length;
        *ref = malloc((newLength + 1) * sizeof(char));
        int i;
        for (i = 0; i < start; ++i) (*ref)[i] = oldString[i];
        for (i = start; i < newLength; ++i) (*ref)[i] = oldString[i + length];
        (*ref)[newLength] = '\0';
    } else {
        *ref = SubStr(*ref, 0, start);
    }
}

void StrRep(StringRef ref, String t, String r) {

}

int main() {
    String s = "Hello World!";
    StrDelete(&s, 6, 5);
    printf("%s", s);
}
