#ifndef DATASTRUCTURE_STRING_H
#define DATASTRUCTURE_STRING_H

typedef char *String;

int StrLength(String value);

void StrAssign(String s, String value);

void StrConcat(String s1, String s2, String dest);

String SubStr(String s, int start, int length);

int StrCmp(String s1, String s2);

int StrIndex(String s, String t);

void StrInsert(String s, int i, String t);

void StrDelete(String s, int start, int length);

void StrRep(String s, String t, String r);

#endif //DATASTRUCTURE_STRING_H

