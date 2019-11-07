#ifndef DATASTRUCTURE_STRING_H
#define DATASTRUCTURE_STRING_H

typedef char *String;
typedef String *StringRef;

String StrCreate(char *value);

int StrLength(String value);

void StrAssign(StringRef s, String value);

void StrConcat(StringRef s1, String s2);

String SubStr(String s, int start, int length);

int StrCmp(String s1, String s2);

int StrIndex(String s, String t);

void StrInsert(StringRef s, int i, String t);

void StrDelete(StringRef s, int start, int length);

void StrRep(StringRef s, String t, String r);

#endif //DATASTRUCTURE_STRING_H

