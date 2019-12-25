//
// Created by Mouse on 2019/12/12.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define SIZE 100

using namespace std;

typedef struct HTNode *HTree;
typedef struct HTNode {
    char c;
    int weight;
    HTree left, right;
} HTNode;

void CreateHTree(HTree &tree);

char **CreateHCode(HTree tree);

char *Encode(char **code, char *s);

char *Decode(HTree tree, char *data);

int main() {
    HTree tree;
    CreateHTree(tree);
    char **code = CreateHCode(tree);
    char *s = (char *) malloc(sizeof(char) * SIZE);
    cin >> s;
    s = Encode(code, s);
    cout << s << endl;
    cout << Decode(tree, s) << endl;
    return 0;
}

int Compare(const void *o1, const void *o2) { // 按非递增顺序排列
    return (*(HTree *) o2)->weight - (*(HTree *) o1)->weight;
}

void CreateHTree(HTree &tree) {
    int n;
    cin >> n;
    HTree *nodes = (HTree *) malloc(sizeof(HTree) * n);
    for (int i = 0; i < n; ++i) { // 读入数据
        HTree node = (HTree) malloc(sizeof(HTNode));
        cin >> node->c >> node->weight;
        node->left = nullptr;
        node->right = nullptr;
        nodes[i] = node;
    }

    while (n > 1) {
        qsort(nodes, n, sizeof(HTree), Compare); // 按非递增顺序排列节点
        HTree node = (HTree) malloc(sizeof(HTNode));
        node->weight = nodes[n - 1]->weight + nodes[n - 2]->weight; // 取权重最小的两个节点，将权重相加
        node->left = nodes[n - 1];
        node->right = nodes[n - 2];
        nodes[n - 2] = node; // 将新结点添加到列表中
        n--; // 列表大小减一
    }

    tree = nodes[0]; // 返回根节点
    free(nodes);
}

void CreateHCode(HTree tree, char *bits, int depth, char **result) {
    if (tree->left == nullptr) {
        char *code = (char *) malloc(sizeof(char) * (depth + 1));
        memcpy(code, bits, depth);
        code[depth] = '\0';
        result[tree->c] = code;
        return;
    }
    bits[depth] = '0';
    CreateHCode(tree->left, bits, depth + 1, result);
    bits[depth] = '1';
    CreateHCode(tree->right, bits, depth + 1, result);
}

char **CreateHCode(HTree tree) {
    char **result = (char **) malloc(sizeof(char *) * 256);
    char *bits = (char *) malloc(sizeof(char) * 10);
    CreateHCode(tree, bits, 0, result);
    return result;
}

char *Encode(char **code, char *s) {
    char *bits = (char *) malloc(sizeof(char) * SIZE);
    bits[0] = '\0';
    while (*s) {
        strcat(bits, code[*s]);
        s++;
    }
    return bits;
}

char *Decode(HTree tree, char *data) {
    char *s = (char *) malloc(sizeof(char) * SIZE);
    char *c = s;
    HTree node = tree;
    while (*data) {
        if (*data == '1') { // 1为右孩子，0为左孩子
            node = node->right;
        } else {
            node = node->left;
        }

        if (node->left == nullptr) { // 找到叶节点
            *c = node->c;
            node = tree;
            c++;
        }

        data++;
    }
    *c = '\0';
    return s;
}
