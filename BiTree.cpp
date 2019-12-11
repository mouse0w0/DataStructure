#include "BiTree.hpp"
#include <stdio.h>
#include <stdlib.h>

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
