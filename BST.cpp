//
//  BST.cpp
//  BST
//
//  Created by Anup Sankarraman on 4/8/17.
//  Copyright © 2017 Anup Sankarraman. All rights reserved.
//


#include <stdio.h>
#include <iostream>
#include <queue>
#include "BST.hpp"
#include "Student.hpp"
#include "Faculty.hpp"

using namespace std;

//Typical operations related to a Binary Search Tree (BST)
template <class T>
BST<T>::BST()
{
    root = NULL;
    numElements = 0;
}

template <class T>
bool BST<T>::insert(T  d)
{
    TreeNode<T>* node = new TreeNode<T>(d);
    bool isDataInserted = true;
    
    if (root == NULL) // emptry tree
    {
        root = node;
        numElements++;
        return true;
    }
    isDataInserted = root->add(d);
    if (isDataInserted == true)
        numElements++;
    return isDataInserted;
}

template <class T>
bool BST<T>::isEmpty()
{
    if (root == NULL)
        return true;
    else
        return false;
}


template <class T>
bool BST<T>::contains(T d)
{
    
    if (root == NULL)
        return false;
    
    if (root->getData() == d)
        return true;
    else
        return root->contains(d);
}

template <class T>
T BST<T>::search(T d)
{
    
    if (root->getData() == d)
        return root->getData();
    else
        return root->search(d);
}


template <class T>
bool BST<T>::deleteV(T d)
{
    TreeNode<T>* parent = NULL;
    TreeNode<T>* current = root;
    bool isLeft = false;
    
    if (current == NULL)
        return false;
    
    while(current->getData() != d)
    {
        parent = current;
        
        if (d.getId() < current->getData().getId())
        {
            isLeft = true;
            current = current->getLeft();
        }
        else
        {
            isLeft = false;
            current = current->getRight();
        }
        if (current == NULL)
            return false;
    }
    
    // we found what needs to be deleted
    //no children
    if (current->getLeft() == NULL && current->getRight() == NULL)
    {
        //cout << " no children " << endl;;
        if (current == root)
            root = NULL;
        else if (isLeft == true)
        {
            parent->setLeft(NULL);
        }
        else
        {
            parent->setRight(NULL);
        }
    }
    
    //has one child
    else if (current->getRight() == NULL) // no right children
    {
        // cout << "no right children " << endl;
        if (current == root)
        {
            root = current->getLeft();
        }
        else if (isLeft == true)
        {
            parent->setLeft(current->getLeft());
        }
        else
        {
            parent->setRight(current->getLeft());
        }
    }
    else if (current->getLeft() == NULL) // no left children
    {
        //cout << " no left children " << endl;
        if (current == root)
        {
            root = current->getRight();
        }
        else if (isLeft == true)
        {
            parent ->setLeft(current->getRight());
        }
        else
        {
            parent->setRight(current->getRight());
        }
    }
    //two children
    else
    {
        //cout << " has two child " << endl;
        TreeNode<T>* minNode = current->getRight();
        parent = current;
        
        while (minNode->getLeft() != NULL)
        {
            parent = minNode;
            minNode = minNode->getLeft();
        }
        current->setData(minNode->getData());
        parent->setRight(minNode->getRight());
    }
    
    numElements--;
    return true;
}

template <class T>
void BST<T>::inOrder()
{
    if (root == NULL)
        return;
    printInOrder(root);
}

template <class T>
void BST<T>::printInOrder(TreeNode<T>* node)
{
    if (node == NULL)
        return;
    printInOrder(node->getLeft());
    node->printNode();
    printInOrder(node->getRight());
}

template <class T>
T *BST<T>::levelOrder()
{
    if (root == NULL)
        return NULL;
    
    int i = 0;
    myTree = new T [numElements ];
    queue<TreeNode<T>*> nodeQ;
    
    nodeQ.push(root);
    while (nodeQ.empty() == false)
    {
        TreeNode<T> *node = nodeQ.front();
        nodeQ.pop();
        myTree[i++] = node->getData();
        if (node->getLeft() != NULL)
            nodeQ.push(node->getLeft());
        if (node->getRight() != NULL)
            nodeQ.push(node->getRight());
    }
    return myTree;
}

template <class T>
int BST<T>::getElements()
{
    return numElements;
}

template <class T>
BST<T>::~BST()
{
    TreeNode<T> *temp = root;
    
    delete temp;
    
}



