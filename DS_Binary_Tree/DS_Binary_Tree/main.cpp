//
//  main.cpp
//  DS_Binary_Tree
//
//  Created by 李嘉诚 on 2017/9/22.
//  Copyright © 2017年 李嘉诚. All rights reserved.
//

#include <iostream>
#include <cstdio>
#define MAX_TREE_SIZE 100
#define Status int
#define OK 1
//用顺序存储结构建立树建个卵
//链式存储结构
using namespace std;
template<typename T>struct BTNode{
    T data;
    struct BTNode *lchild,*rchild;
};

typedef BTNode<int> BTNode_int,*BT_int;
typedef BTNode<double> BTNode_double,*BT_double;
typedef BTNode<char> BTNode_char,*BT_char;

template<typename T> Status CreateBT_Pre(BTNode<T> *Tree)
{
    T input;
    cin>>input;
    if (input==-1) Tree=nullptr;
    else
    {
        Tree->data=input;
        CreateBT_Pre(Tree->lchild);
        CreateBT_Pre(Tree->rchild);
    }
    return OK;
}
template<typename T> Status CreateBT_In(BTNode<T> *Tree)
{
    T input;
    cin>>input;
    if (input==-1) Tree=nullptr;
    else
    {
        CreateBT_In(Tree->lchild);
        Tree->data=input;
        CreateBT_In(Tree->rchild);
    }
    return OK;
}
template<typename T> Status CreateBT_Post(BTNode<T> *Tree)
{
    T input;
    cin>>input;
    if (input==-1) Tree=nullptr;
    else
    {
        CreateBT_Post(Tree->lchild);
        CreateBT_Post(Tree->rchild);
        Tree->data=input;
    }
    return OK;
}
template<typename T> Status PreOrderTraverse(BTNode<T> *Tree,Status (*visit)(BTNode<T> *node))
{
    if(Tree)
    {
        visit(Tree->data);
        PreOrderTraverse(Tree->lchild, visit);
        PreOrderTraverse(Tree->rchild, visit);
    }
    return OK;
}
template<typename T> Status InOrderTraverse(BTNode<T> *Tree,Status (*visit)(BTNode<T> *node))
{
    if(Tree)
    {
        PreOrderTraverse(Tree->lchild, visit);
        visit(Tree->data);
        PreOrderTraverse(Tree->rchild, visit);
    }
    return OK;
}
template<typename T> Status PostOrderTraverse(BTNode<T> *Tree,Status (*visit)(BTNode<T> *node))
{
    if(Tree)
    {
        PostOrderTraverse(Tree->lchild, visit);
        PostOrderTraverse(Tree->rchild, visit);
        visit(Tree->data);
    }
    return OK;
}
template<typename T> Status DestroyBT(BTNode<T> *Tree)
{
    if (Tree) {
        DestroyBT(Tree->lchild);
        DestroyBT(Tree->rchild);
        delete Tree;
    }
    return OK;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
