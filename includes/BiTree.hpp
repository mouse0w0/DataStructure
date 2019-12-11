#ifndef DATASTRUCTURE_BITREE_HPP
#define DATASTRUCTURE_BITREE_HPP

#include <Status.h>

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

#endif //DATASTRUCTURE_BITREE_HPP
