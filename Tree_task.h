#include <cstdio>
#include <iostream>

#ifndef LABA2_2_1_3VAR_AISD_TREE_TASK1_H
#define LABA2_2_1_3VAR_AISD_TREE_TASK1_H

template <class T>
struct Node_1
{
    T _data;
    Node_1* _father;
    Node_1* _left;
    Node_1* _right;
    explicit Node_1(T data = 0, Node_1* father = nullptr, Node_1* left = nullptr, Node_1* right = nullptr)
    {
        _data = data;
        _father = father;
        _left = left;
        _right = right;
    }
};

template <class T>
class Tree_task1 {
private:
    Node_1<T>* root;
public:
    Node_1<T>* return_root();
    void recursion_destructor(Node_1<T>* obj);
    void recursion_copy(const Node_1<T>* obj);

    Tree_task1();
    ~Tree_task1();
    Tree_task1(const Tree_task1& obj);

    void print_Tree(const Node_1<T>* p,int level)const;
    Node_1<T>* insert(struct Node_1<T>* _root , int key);
    Node_1<T>* search(int key,const Node_1<T>* obj);
    bool contains(int key);
    Node_1<T>* erase(int key, Node_1<T>* obj);
    Node_1<T>* erase_duplicate(int key, Node_1<T>* obj);


    Tree_task1& operator=(const Tree_task1<T>& obj);
    Node_1<T>* minNode(Node_1<T>* obj);
    size_t count(int x, Node_1<T>* obj);
};



#endif //LABA2_2_1_3VAR_AISD_TREE_TASK1_H
