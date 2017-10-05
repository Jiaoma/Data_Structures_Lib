//
//  main.cpp
//  BinaryTree_Search
//
//  Created by 李嘉诚 on 2017/9/23.
//  Copyright © 2017年 李嘉诚. All rights reserved.
//

#include <iostream>
#include <cstdio>
#define MAX_TREE_SIZE 100
#define Status int
#define OK 1
#define FALS 0
#define TRU 1

using namespace std;
typedef struct BTNode{
    int data;
    struct BTNode *lchild,*rchild;
}BTNode;




Status SearchBT(BTNode *Tree,int key,BTNode *father,BTNode *(&p))
{
    //p为指向目标点的指针，若没找到返回访问的最后一点地址
    if (!Tree) {
        p=father;
        return FALS;
    }
    else if (key==Tree->data){p=Tree; return TRU;}
    else if (key<Tree->data)
        return SearchBT(Tree->lchild, key, Tree, p);
    else
        return SearchBT(Tree->rchild, key, Tree, p);
}
Status InsertBT_Search(BTNode *(&Tree),int tar)
{
    BTNode *newNode=NULL;
    BTNode *p = NULL;
    if (!SearchBT(Tree, tar, NULL, p)) {
        newNode=new BTNode;
        newNode->data=tar;
        newNode->lchild=newNode->rchild=NULL;
        if (!p) Tree=newNode;
        else if (tar<(p->data)) p->lchild=newNode;
        else p->rchild=newNode;
        return OK;
    }
    else return FALS;
}

Status DestroyBT(BTNode *Tree)
{
    if (Tree) {
        DestroyBT(Tree->lchild);
        DestroyBT(Tree->rchild);
        delete Tree;
    }
    return OK;
}

int main(int argc, const char * argv[]) {
    int n,k;
    int input;
    BTNode *Tree=NULL;
    while(cin>>n>>k)
    {
        Tree=NULL;
        for (int i=0; i<n; i++) {
            scanf("%d",&input);
            InsertBT_Search(Tree, input);
        }
        for (int j=0; j<k; j++) {
            int st;
            BTNode *p=NULL;
            scanf("%d",&st);
            if (SearchBT(Tree, st, NULL, p)) {
                cout<<1<<' ';
            }
            else
                cout<<0<<' ';
        }
        cout<<endl;
        DestroyBT(Tree);
    }
    return 0;
}

