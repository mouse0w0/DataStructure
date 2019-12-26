//
// Created by Mouse on 2019/12/23.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define MAX 100

using namespace std;

typedef struct {
    char name[51];
    char phone[12];
} Element;

typedef Element **LinearMap;

typedef struct Entry Entry;
typedef Entry *PtrEntry;
struct Entry {
    Element *element;
    Entry *next;
};

typedef Entry **LinkedMap;

int Hash(char *s);

LinearMap CreateLinearMap();

LinkedMap CreateLinkedMap();

void Put(LinearMap map, Element *element);

void Put(LinkedMap map, Element *element);

Element *Get(LinearMap map, char *phone);

Element *Get(LinkedMap map, char *name);

int main() {
    int n;
    cin >> n;
    LinearMap linearMap = CreateLinearMap();
    LinkedMap linkedMap = CreateLinkedMap();
    for (int i = 0; i < n; ++i) {
        Element *element = (Element *) malloc(sizeof(Element));
        cin >> element->name >> element->phone;
        Put(linearMap, element);
        Put(linkedMap, element);
    }

    char s[100];
    cout << "Enter a name:";
    cin >> s;
    Element *element = Get(linkedMap, s);
    if (element == nullptr) {
        cout << "Not found." << endl;
    } else {
        cout << "Found: " << element->name << " " << element->phone << endl;
    }

    cout << "Enter a phone:";
    cin >> s;
    element = Get(linearMap, s);
    if (element == nullptr) {
        cout << "Not found." << endl;
    } else {
        cout << "Found: " << element->name << " " << element->phone << endl;
    }
    return 0;
}

int Hash(char *s) {
    int hash = 0;
    while (*s) {
        hash = hash * 37 + *(s++);
    }
    return abs(hash);
}

LinearMap CreateLinearMap() {
    LinearMap map = (LinearMap) malloc(sizeof(Element *) * MAX);
    for (int i = 0; i < MAX; ++i) map[i] = nullptr;
    return map;
}

LinkedMap CreateLinkedMap() {
    LinkedMap map = (LinkedMap) malloc(sizeof(Entry *) * MAX);
    for (int i = 0; i < MAX; ++i) map[i] = nullptr;
    return map;
}

void Put(LinearMap map, Element *element) {
    int hash = Hash(element->phone) % MAX;
    for (int i = 1;; ++i) {
        int j = i / 2;
        int next = hash + j * j * (i & 1 ? -1 : 1); // 二次散列探查法
        if (next < 0 || next >= MAX) return; // 越界，结束循环
        if (map[next] == nullptr) {
            map[next] = element;
            return;
        }
    }
}

void PutEntry(Entry **entry, Element *element) {
    while (*entry != nullptr) {
        entry = &(*entry)->next; // 获取链表尾节点的下一个节点的引用
    }
    *entry = (Entry *) malloc(sizeof(Entry)); // 创建新节点
    (*entry)->element = element;
    (*entry)->next = nullptr;
}

void Put(LinkedMap map, Element *element) {
    int hash = Hash(element->name) % MAX;
    PutEntry(&map[hash], element);
}

Element *Get(LinearMap map, char *phone) {
    int hash = Hash(phone) % MAX;
    for (int i = 1;; ++i) {
        int j = i / 2;
        int next = hash + j * j * (i & 1 ? -1 : 1); // 二次散列探查法
        if (next < 0 || next >= MAX) return nullptr; // 越界，结束循环
        if (map[next] != nullptr && strcmp(map[next]->phone, phone) == 0) {
            return map[next];
        }
    }
}

Element *Get(LinkedMap map, char *name) {
    int hash = Hash(name) % MAX;
    Entry *entry = map[hash];
    while (entry != nullptr) {
        if (strcmp(entry->element->name, name) == 0) return entry->element; // 找到元素
        entry = entry->next;
    }
    return nullptr; // 未找到元素
}