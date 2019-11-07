#include <stdlib.h>
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

}

void StrInsert(StringRef ref, int i, String t) {

}

void StrDelete(StringRef ref, int start, int length) {

}

void StrRep(StringRef ref, String t, String r) {

}
