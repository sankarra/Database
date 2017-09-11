//
//  TreeNode.cpp
//  BST
//
//  Created by Anup Sankarraman on 4/8/17.
//  Copyright © 2017 Anup Sankarraman. All rights reserved.
//

#include "TreeNode.hpp"
#include "Student.hpp"
#include "Faculty.hpp"

//Typical operators related to a TreeNode (a node in a tree)
template <class T>
TreeNode<T>::TreeNode()
{
    data = 0;
    left = right = NULL;
    
}

template <class T>
TreeNode<T>::TreeNode(T d)
{
    data = d;
    left = NULL;
    right = NULL;
}

template <class T>
void TreeNode<T>::setData(T d)
{
    data = d;
}

template <class T>
T TreeNode<T>::getData()
{
    return data;
}

template <class T>
void TreeNode<T>::setLeft(TreeNode *l)
{
    left = l;
}

template <class T>
TreeNode<T>* TreeNode<T>::getLeft()
{
    return left;
}

template <class T>
void TreeNode<T>::setRight(TreeNode *r)
{
    right = r;
}

template <class T>
TreeNode<T>* TreeNode<T>::getRight()
{
    return right;
}

template <class T>
bool TreeNode<T>::contains(T d)
{
    if (d == data)
        return true;
    //else if (d < data)
    else if (d.getId() < data.getId())
    {
        if (left == NULL)
            return false;
        else
            return left->contains(d);
    }
    else if (d > data)
    {
        if (right == NULL)
            return false;
        else
            return right->contains(d);
    }
    return false;
    
}

template <class T>
T TreeNode<T>::search(T d)
{
    T *dummy = new T ();
    
    if (d == data)
        return data;
    //else if (d < data)
    else if (d.getId() < data.getId())
    {
        if (left != NULL)
            return left->search(d);
    }
    else if (d > data)
    {
        if (right != NULL)
            return right->search(d);
    }
    
    return *dummy;
}


template <class T>
bool TreeNode<T>::add(T d)
{
    if (d == data)
        return false;
    else if (d.getId() < data.getId())
        //else if (d < this->data)
    {
        if (left == NULL)
        {
            left = new TreeNode<T>(d);
            return true;
        }
        else
            return left->add(d);
    }
    else if (d > data)
    {
        if (right == NULL)
        {
            right = new TreeNode<T>(d);
            return true;
        }
        else
            return right->add(d);
    }
    return false;
    
}

template <class T>
void TreeNode<T>::printNode()
{
    this->data.printData();
}


template <class T>
TreeNode<T>::~TreeNode()
{
    delete this;
}


