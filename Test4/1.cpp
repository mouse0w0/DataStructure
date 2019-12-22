//
// Created by Mouse on 2019/12/11.
//
#include <iostream>

using namespace std;

typedef char BiTElement;
typedef struct BiTNode *PtrBiTNode;
typedef struct BiTNode {
    BiTElement data;
    PtrBiTNode left;
    PtrBiTNode right;
} BiTNode;
typedef struct BiTNode *BiTree;

Status CreateBiTree(BiTree &tree);

void PreOrderTraverse(BiTree tree, void (*visitor)(BiTElement));

void InOrderTraverse(BiTree tree, void (*visitor)(BiTElement));

void PostOrderTraverse(BiTree tree, void (*visitor)(BiTElement));

void visitor(BiTElement data) {
    cout << data << " ";
}

int main() {
    BiTree tree;
    CreateBiTree(tree);

    cout << "Pre Order: ";
    PreOrderTraverse(tree, visitor);
    cout << endl;

    cout << "In Order: ";
    InOrderTraverse(tree, visitor);
    cout << endl;

    cout << "Post Order: ";
    PostOrderTraverse(tree, visitor);
    cout << endl;
    return 0;
}

Status CreateBiTree(BiTree &tree) {
    char ch;
    scanf("%c", &ch);
    if (ch == '.') tree = nullptr;
    else {
        if (!(tree = (BiTree) malloc(sizeof(BiTNode))))
            exit(OVERFLOW);
        tree->data = ch;
        CreateBiTree(tree->left);
        CreateBiTree(tree->right);
    }
    return OK;
}

void PreOrderTraverse(BiTree tree, void (*visitor)(BiTElement)) {
    if (tree == nullptr) return;
    visitor(tree->data);
    PreOrderTraverse(tree->left, visitor);
    PreOrderTraverse(tree->right, visitor);
}

void InOrderTraverse(BiTree tree, void (*visitor)(BiTElement)) {
    if (tree == nullptr) return;
    InOrderTraverse(tree->left, visitor);
    visitor(tree->data);
    InOrderTraverse(tree->right, visitor);
}

void PostOrderTraverse(BiTree tree, void (*visitor)(BiTElement)) {
    if (tree == nullptr) return;
    PostOrderTraverse(tree->left, visitor);
    PostOrderTraverse(tree->right, visitor);
    visitor(tree->data);
}

