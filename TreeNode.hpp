//
//  TreeNode.hpp
//  BST
//
//  Created by Anup Sankarraman on 4/8/17.
//  Copyright © 2017 Anup Sankarraman. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>

template <class T>
class TreeNode {
    
private:
    T data;
    TreeNode *left;
    TreeNode *right;
    
public:
    TreeNode();
    TreeNode(T d);
    void setData(T d);
    T getData();
    void setLeft(TreeNode *l);
    TreeNode *getLeft();
    void setRight(TreeNode *r);
    TreeNode *getRight();
    bool add(T d);
    T search (T d);
    bool contains(T d);
    void printNode();
    ~TreeNode();
    
};


#endif /* TreeNode_hpp */
