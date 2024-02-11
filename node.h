#ifndef ESTRUCTURAAS_NODE_H
#define ESTRUCTURAAS_NODE_H


template <typename T>
class Node {
public:
    T data;
    Node* right;
    Node* left;
    int height;

    explicit Node(const T& value) : data(value), left(nullptr), right(nullptr) , height(1) {}
};


#endif //ESTRUCTURAAS_NODE_H
