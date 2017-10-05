//
//  main.cpp
//  Special_BalancedBinaryTree
//
//  Created by 李嘉诚 on 2017/9/23.
//  Copyright © 2017年 李嘉诚. All rights reserved.


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
    int data;
    int hei;
    struct BTNode *lchild,*rchild;
}BTNode;


int posi=0;
int len;
int maxhei=0;
Status swap(int &a,int &b)
{
    if (a!=b) {
        int temp=a;
        a=b;
        b=temp;
    }
    return OK;
}
Status SORT(int key[],int len,int value[])
{
    //from small to big
    int min=32767;
    int k=-1;
    for (int j=0; j<len; j++) {
        for (int i=j; i<len; i++) {
            if (key[i]<min) {
                min=key[i];
                k=i;
            }
        }
        swap(key[j], key[k]);
        swap(value[j], value[k]);
        min=32767;
    }
    return OK;
}

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

Status InsertBT_Search(BTNode *(&Tree),int input[])
{
    if (posi<len) {
        BTNode *newNode=NULL;
        BTNode *p = NULL;
        if (!SearchBT(Tree, input[posi], NULL, p)) {
            newNode=new BTNode;
            newNode->data=input[posi];
            newNode->lchild=newNode->rchild=NULL;
            if (!p) {Tree=newNode; newNode->hei=1;}//p为空，则原树为空树
            else if (input[posi]<(p->data)) {p->lchild=newNode;newNode->hei=p->hei+1;}
            else {p->rchild=newNode;newNode->hei=p->hei+1;}
            maxhei=MAX(maxhei, newNode->hei);
            posi++;
            return OK;
        }
    }
    return OK;
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
    int case_num;
    int node_num;
    int keys[105];
    int values[105];
    memset(keys, 0, sizeof(keys));
    memset(values, 0, sizeof(values));
    BTNode *Tree=NULL;
    while(cin>>case_num)
    {
        for (int i=0; i<case_num; i++) {
            maxhei=0;
            cin>>node_num;
            for (int i=0; i<node_num; i++) {
                cin>>values[i];
            }
            for (int i=0; i<node_num; i++) {
                cin>>keys[i];
            }
            SORT(keys, node_num, values);
            Tree=NULL;
            posi=0;
            len=node_num;
            for (int k=0; k<node_num; k++) {
                InsertBT_Search(Tree,values);
            }
            cout<<maxhei<<endl;
            DestroyBT(Tree);
        }
    }
    return 0;
}



