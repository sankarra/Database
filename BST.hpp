//
//  BST.hpp
//  BST
//
//  Created by Anup Sankarraman on 4/8/17.
//  Copyright © 2017 Anup Sankarraman. All rights reserved.
//

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>
#include "TreeNode.hpp"

template <class T>
class BST
{
private:
    TreeNode<T> *root;
    int numElements;
    T *myTree;
public:
    BST();
    bool insert(T d);
    bool contains (T d);
    T search (T d);
    void printData(T d);
    bool deleteV (T d);
    bool isEmpty();
    void inOrder();
    T* levelOrder();
    void printInOrder(TreeNode<T>* node);
    int getMin();
    int getMax();
    int getElements();
    ~BST();
    
};

#endif /* BST_hpp */
