//
// Created by Mouse on 2019/12/22.
//

#include <Status.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX 10

typedef int BiTElement;
typedef struct BiTNode *PtrBiTNode;
typedef struct BiTNode {
    BiTElement data;
    PtrBiTNode left;
    PtrBiTNode right;
} BiTNode;
typedef struct BiTNode *BiTree;

void GenerateRandomData();

void Create(BiTree &tree);

PtrBiTNode Find(BiTree tree, int value);

Status Insert(BiTree &tree, int value);

void Remove(BiTree &tree, int value);

void InOrderTraverse(BiTree tree);

int main() {
    GenerateRandomData();
    BiTree tree = nullptr;
    Create(tree);
    InOrderTraverse(tree);
    cout << endl;
    int value;
    cin >> value;
    cout << (Find(tree, value) != nullptr ? "Found" : "No found") << endl;
    cin >> value;
    Remove(tree, value);
    InOrderTraverse(tree);
    return 0;
}

void GenerateRandomData() {
    FILE *file = fopen("test5-2.txt", "w");
    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        fprintf(file, "%d\n", rand() % 100);
    }
    fclose(file);
}

void Create(BiTree &tree) {
    FILE *file = fopen("test5-2.txt", "r");
    int k;
    for (int i = 0; i < MAX; ++i) {
        fscanf(file, "%d", &k);
        Insert(tree, k);
    }
    fclose(file);
}

PtrBiTNode Find(BiTree tree, int value) {
    if (tree == nullptr) return nullptr; // 未找到节点
    if (tree->data == value) return tree; // 找到节点
    if (tree->data > value) return Find(tree->left, value); // 节点值大于目标值，在左孩子中查找
    else return Find(tree->right, value); // 节点值小于目标值，在右孩子中查找
}

Status Insert(BiTree &tree, int value) {
    if (tree == nullptr) {
        tree = (PtrBiTNode) malloc(sizeof(BiTNode));
        tree->data = value;
        tree->left = nullptr;
        tree->right = nullptr;
        return OK;
    }
    if (tree->data > value) return Insert(tree->left, value); // 节点值大于插入值，向左孩子插入
    else if (tree->data < value) return Insert(tree->right, value); // 节点值小于插入值，向右孩子插入
    else return ERROR; // 不能向树中插入相同的元素
}

void Remove(BiTree &tree, int value) {
    if (tree == nullptr) return;

    if (tree->data == value) {
        if (tree->left == nullptr && tree->right == nullptr) { // 无孩子节点
            tree = nullptr;
        } else if (tree->left == nullptr) { // 只有右孩子
            tree = tree->right;
        } else if (tree->right == nullptr) { // 只有左孩子
            tree = tree->left;
        } else { // 左右孩子都存在，将右孩子添加到左孩子的右子叶节点的右孩子上
            BiTree leaf = tree;
            BiTree right = leaf->right;
            while (right != nullptr) {
                leaf = right;
                right = leaf->right;
            }
            leaf->right = tree->right;
        }
        free(tree);
        return;
    }

    if (tree->data > value) Remove(tree->left, value);
    else Remove(tree->right, value);
}

void InOrderTraverse(BiTree tree) {
    if (tree == nullptr) return;
    InOrderTraverse(tree->left); // 先遍历左孩子
    cout << tree->data << " ";
    InOrderTraverse(tree->right);
}