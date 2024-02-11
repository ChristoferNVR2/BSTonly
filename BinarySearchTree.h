#ifndef ESTRUCTURAAS_BINARYSEARCHTREE_H
#define ESTRUCTURAAS_BINARYSEARCHTREE_H

#include <iostream>
#include "Node.h"
#include <queue>
#include <windows.h>

using namespace std;

class BinarySearchTree {
private:
    Node<int>* root;

    static int height (Node<int>* node);
    Node<int>* insert(Node<int>* parent, int value);

    void preorderTraversal(Node<int>* parent);
    void inorderTraversal(Node<int>* parent);
    void postorderTraversal(Node<int>* parent);

    bool searchNode(Node<int>* parent,int value);
    static Node<int>* findMin(Node<int>* node);
    Node<int>* removeNode(Node<int>* parent, int value);

    void gotoxy(auto x, auto y);
    void displayVerticalTree(Node<int>* parent, int auxY, int& auxX);

    int getHeight(Node<int>* parent);

    int inorderForLeaf(Node<int>* parent, int& cont);
    int numberOfLeafs(Node<int>* parent);

    int numberOfNodes(Node<int>* parent);

    void deleteTree(Node<int>* parent);

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int val);

    void preorderTraversal();
    void inorderTraversal();
    void postorderTraversal();

    bool searchNode(int val);
    void removeNode(int val);

    void breadthTraversal(); //solo public porque con queue evita la recursividad

    void displayVerticalTree();

    int getHeight();

    int numberOfLeafs();

    int numberOfLevels();
    int numberOfNodes();

    void deleteTree();

    ~BinarySearchTree() {
        deleteTree(root);
    }
};


#endif //ESTRUCTURAAS_BINARYSEARCHTREE_H
