//
// Created by Mouse on 2019/12/11.
//
#include <BiTree.hpp>
#include <iostream>

using namespace std;

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

