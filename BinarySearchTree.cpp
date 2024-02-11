#include "BinarySearchTree.h"

int BinarySearchTree::height(Node<int> *node) {
    return (node != nullptr) ? node->height : 0;
}

Node<int>* BinarySearchTree::insert(Node<int>* parent, int value) { // NOLINT(misc-no-recursion)
    if (parent == nullptr) {
        return new Node(value);
    }

    if (value < parent->data) {
        parent->left = insert(parent->left, value);
    } else if (value > parent->data) {
        parent->right = insert(parent->right, value);
    }

    parent->height = max(height(parent->left), height(parent->right)) + 1;

    return parent;
}

void BinarySearchTree::preorderTraversal(Node<int>* parent) { // NOLINT(misc-no-recursion)
    if (parent != nullptr) {
        cout << parent->data << " ";
        preorderTraversal(parent->left);
        preorderTraversal(parent->right);
    }
}

void BinarySearchTree::inorderTraversal(Node<int>* parent) { // NOLINT(misc-no-recursion)
    if (parent != nullptr) {
        inorderTraversal(parent->left);
        cout << parent->data << " ";
        inorderTraversal(parent->right);
    }
}

void BinarySearchTree::postorderTraversal(Node<int>* parent) { // NOLINT(misc-no-recursion)
    if (parent != nullptr) {
        postorderTraversal(parent->left);
        postorderTraversal(parent->right);
        cout << parent->data << " ";
    }
}

bool BinarySearchTree::searchNode(Node<int>* parent, int value) { // NOLINT(misc-no-recursion)
    if (parent == nullptr) {
        return false;
    }

    if (parent->data == value) {
        return true;
    }

    if (value < parent->data) {
        return searchNode(parent->left, value);
    } else {
        return searchNode(parent->right, value);
    }
}

Node<int> *BinarySearchTree::findMin(Node<int>* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node<int>* BinarySearchTree::removeNode(Node<int>* parent, int value) { // NOLINT(misc-no-recursion)
    if (parent == nullptr) {
        return nullptr;
    }

    if (value < parent->data) {
        parent->left = removeNode(parent->left, value);
    } else if (value > parent->data) {
        parent->right = removeNode(parent->right, value);
    } else {
        if (parent->left == nullptr) {
            Node<int>* temp = parent->right;
            delete parent;
            return temp;
        } else if (parent->right == nullptr) {
            Node<int>* temp = parent->left;
            delete parent;
            return temp;
        } else {
            Node<int>* temp = findMin(parent->right);
            parent->data = temp->data;
            parent->right = removeNode(parent->right, temp->data);
        }
    }

    parent->height = max(height(parent->left), height(parent->right)) + 1;

    return parent;
}

void BinarySearchTree::gotoxy(auto x, auto y) {
    HANDLE hcon;
    hcon=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;
    SetConsoleCursorPosition(hcon,dwPos);
}

void BinarySearchTree::displayVerticalTree(Node<int>* parent, int auxY, int &auxX) { // NOLINT(misc-no-recursion)
    if (parent == nullptr) {
        return;
    }

    auxX += 5;

    displayVerticalTree(parent->left, auxY + 2, auxX);

    gotoxy(10 + auxX - auxY, 14 + auxY);
    cout << parent->data << endl << endl;

    displayVerticalTree(parent->right, auxY + 2, auxX);
}

int BinarySearchTree::getHeight(Node<int> *parent) { // NOLINT(misc-no-recursion)
    if (parent == nullptr) {
        return 0;
    }

    int leftHeight = getHeight(parent->left);
    int rightHeight = getHeight(parent->right);

    return max(leftHeight, rightHeight) + 1;
}

int BinarySearchTree::inorderForLeaf(Node<int>* parent, int &cont) { // NOLINT(misc-no-recursion)
    if(parent == nullptr) {
        return 0;
    }

    inorderForLeaf(parent->left, cont);

    if(parent->left == nullptr && parent->right == nullptr) {
        cont++;
    }

    inorderForLeaf(parent->right, cont);

    return cont;
}

int BinarySearchTree::numberOfLeafs(Node<int> *parent) {
    int cont = 0;
    return inorderForLeaf(parent, cont);
}

int BinarySearchTree::numberOfNodes(Node<int> *parent) { //NOLINT(misc-no-recursion)
    if (parent == nullptr) {
        return 0;
    }

    return numberOfNodes(parent->left) + numberOfNodes(parent->right) + 1;
}

void BinarySearchTree::deleteTree(Node<int> *parent) { //NOLINT(misc-no-recursion)
    if (parent == nullptr) {
        return;
    }

    deleteTree(parent->left);
    deleteTree(parent->right);

    delete parent;
}












void BinarySearchTree::insert(int val) {
    root = insert(root, val);
}

void BinarySearchTree::preorderTraversal() {
    preorderTraversal(root);
    cout << endl;
}

void BinarySearchTree::inorderTraversal() {
    inorderTraversal(root);
    cout << endl;
}

void BinarySearchTree::postorderTraversal() {
    postorderTraversal(root);
    cout << endl;
}

bool BinarySearchTree::searchNode(int val) {
    return searchNode(root, val);
}

void BinarySearchTree::removeNode(int val) {
    root = removeNode(root, val);
}

void BinarySearchTree::breadthTraversal() {
    if (root == nullptr) {
        return;
    }

    queue<Node<int>*> breadthQueue;
    breadthQueue.push(root);

    while (!breadthQueue.empty()) {
        Node<int>* iterator = breadthQueue.front();
        breadthQueue.pop();

        cout << iterator->data << " ";

        if (iterator->left != nullptr) {
            breadthQueue.push(iterator->left);
        }

        if (iterator->right != nullptr) {
            breadthQueue.push(iterator->right);
        }
    }
}

void BinarySearchTree::displayVerticalTree() {
    int auxY = 0;
    int auxX = 0;
    displayVerticalTree(root, auxY, auxX);
}

int BinarySearchTree::getHeight() {
    return getHeight(root) - 1;
}

int BinarySearchTree::numberOfLeafs() {
    return numberOfLeafs(root);
}

int BinarySearchTree::numberOfLevels() {
    return getHeight() + 1;
}

int BinarySearchTree::numberOfNodes() {
    return numberOfNodes(root);
}

void BinarySearchTree::deleteTree() {
    deleteTree(root);
    root = nullptr;
}

