#ifndef DATASTRUCTURE_MYSTRING_H
#define DATASTRUCTURE_MYSTRING_H

typedef char *String;

String StrCreate(int length);

int StrLength(String value);

void StrAssign(String s, String value);

void StrConcat(String s1, String s2);

String SubStr(String s, int start, int length);

int StrCmp(String s1, String s2);

int StrIndex(String s, String t);

int StrIndexWithStart(String s, int start, String t);

void StrInsert(String s, int i, String t);

void StrDelete(String s, int start, int length);

void StrRep(String s, String t, String r);

#endif //DATASTRUCTURE_MYSTRING_H

