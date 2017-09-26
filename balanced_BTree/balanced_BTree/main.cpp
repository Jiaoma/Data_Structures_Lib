//
//  main.cpp
//  balanced_BTree
//
//  Created by 李嘉诚 on 2017/9/23.
//  Copyright © 2017年 李嘉诚. All rights reserved.
//

//
//  main.cpp
//  BinaryTree_Search
//
//  Created by 李嘉诚 on 2017/9/23.
//  Copyright © 2017年 李嘉诚. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX_TREE_SIZE 100
#define Status int
#define OK 1
#define FALS 0
#define TRU 1
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;
typedef struct BTNode{
    char data;
    int balance;
    struct BTNode *lchild,*rchild;
}BTNode;


int posi=0;
int len;
int flag;
Status SearchBT(BTNode *Tree,char key,BTNode *father,BTNode *(&p))
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
Status InsertBT_Pre(BTNode *(&Tree),char input[],int hei)
{
    if(posi<len)
    {
        if (input[posi]=='#') {
            posi++;
            return hei;
        }
        else
        {
            BTNode *newNode=new BTNode;
            newNode->data=input[posi++];
            newNode->balance=0;
            newNode->lchild=newNode->rchild=NULL;
            Tree=newNode;
            hei++;
            int ltemp=InsertBT_Pre(Tree->lchild, input,hei);
            int rtemp=InsertBT_Pre(Tree->rchild, input,hei);
            hei=MAX(ltemp, rtemp);
            Tree->balance=rtemp-ltemp;
            return hei;
        }
    }
    return hei;
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
Status PreOrderTraverse(BTNode *Tree)
{
    if(Tree && flag)
    {
        if (Tree->balance==0 || Tree->balance==1 || Tree->balance==-1){}
            else
            {
                flag=0;
            }
        PreOrderTraverse(Tree->lchild);
        PreOrderTraverse(Tree->rchild);
    }
    return OK;
}
int main(int argc, const char * argv[]) {
    char input[2000];
    memset(input, 0, sizeof(input));
    BTNode *Tree=NULL;
    while(scanf("%s",input)!=EOF)
    {
        if (input[0]=='#') {
            cout<<"Yes"<<endl;
        }
        else
        {
            Tree=NULL;
            flag=1;
            posi=0;
            len=int(strlen(input));
            InsertBT_Pre(Tree,input,0);
            PreOrderTraverse(Tree);
            if (flag) {
                cout<<"Yes"<<endl;
            }
            else
                cout<<"No"<<endl;
            DestroyBT(Tree);
        }
    }
    return 0;
}


