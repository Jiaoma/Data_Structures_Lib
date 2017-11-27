//
//  main.cpp
//  BalancedBinaryTree
//
//  Created by 李嘉诚 on 2017/10/13.
//  Copyright © 2017年 李嘉诚. All rights reserved.
// This is my tree ,though stupid,but I have make great effort to let it be correct.


#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define Status int
#define OK 1
#define FALS 0
#define TRU 1
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;
typedef struct BTNode{
    int data;
    int balance;
    int isLeft;//0:root 1:left -1:right
    struct BTNode *lchild,*rchild,*parent;
}BTNode;
int getHeight(BTNode *T)
{
//递归版，时间超限
//    if (T!=NULL) {
//        return 1+MAX(getHeight(T->lchild), getHeight(T->rchild));
//    }
//    else
//        return 0;
    if (T==NULL) {
        return 0;
    }
    int curHeight=0;
    queue<BTNode *>que;
    que.push(T);
    while (!que.empty()) {
        curHeight++;
        int Number_Node_CurLevel=int(que.size());
        int coun=0;
        while (coun<Number_Node_CurLevel) {
            coun++;
            T=que.front();
            que.pop();
            if (T->lchild) {
                que.push(T->lchild);
            }
            if (T->rchild) {
                que.push(T->rchild);
            }
        }
    }
    return curHeight;
}
void twoSon(BTNode *begin,BTNode *ennd,int &isLeft1,int &isLeft2)
{
    BTNode *t1,*t2;
    t1=begin;
    t2=begin->parent;
    while (t2!=NULL &&t2->parent!=ennd) {
        t1=t2;
        t2=t2->parent;
    }
    if (t2!=NULL) {
        isLeft1=t1->isLeft;
        isLeft2=t2->isLeft;
    }
    else
    {
        isLeft2=isLeft1=-2;
    }
    
    
}
void CallDaddy(BTNode *T,BTNode *(&unbalance))
{
    if (T!=NULL) {
        int temp=getHeight(T->lchild)-getHeight(T->rchild);
        if (unbalance==NULL) {
            if (temp>=2 ||temp<=-2) {
                unbalance=T;
            }
        }
        if (T->balance!=temp) {
            T->balance=temp;
            CallDaddy(T->parent, unbalance);
        }
    }
}
void CallZuZong(BTNode *T)
{
    while (T!=NULL) {
        T->balance=getHeight(T->lchild)-getHeight(T->rchild);
        T=T->parent;
    }
}
Status RightRotate(BTNode *(&unBalance),BTNode *(&Tree))
{
    if (unBalance->parent==NULL) {
        Tree=unBalance->lchild;
        if( unBalance->lchild->rchild !=NULL)
        {unBalance->lchild->rchild->parent=unBalance;
            unBalance->lchild->rchild->isLeft=1;}
        unBalance->lchild=unBalance->lchild->rchild;
        Tree->rchild=unBalance;
        unBalance->parent=Tree;
        unBalance->balance-=2;
        unBalance->isLeft=-1;
        Tree->parent=NULL;
        Tree->balance-=1;
        Tree->isLeft=0;
    }
    else
    {
        BTNode *temp=unBalance->parent;
        if (unBalance->isLeft==1) {
            temp->lchild=unBalance->lchild;
            if( unBalance->lchild->rchild !=NULL)
            {unBalance->lchild->rchild->parent=unBalance;
                unBalance->lchild->rchild->isLeft=1;}
            unBalance->lchild=unBalance->lchild->rchild;
            temp->lchild->rchild=unBalance;
            unBalance->parent=temp->lchild;
            unBalance->balance-=2;
            unBalance->isLeft=-1;
            temp->lchild->parent=temp;
            temp->lchild->balance-=1;
            temp->lchild->isLeft=1;
        }
        else
        {
            temp->rchild=unBalance->lchild;
            if( unBalance->lchild->rchild !=NULL)
            {unBalance->lchild->rchild->parent=unBalance;
                unBalance->lchild->rchild->isLeft=1;}
            unBalance->lchild=unBalance->lchild->rchild;
            temp->rchild->rchild=unBalance;
            unBalance->parent=temp->rchild;
            unBalance->balance-=2;
            unBalance->isLeft=-1;
            temp->rchild->parent=temp;
            temp->rchild->balance-=1;
            temp->rchild->isLeft=-1;
        }
        CallZuZong(temp);
    }
    return OK;
}
Status LeftRotate(BTNode *(&unBalance),BTNode *(&Tree))
{
    if (unBalance->parent==NULL) {
        Tree=unBalance->rchild;
        if( unBalance->rchild->lchild !=NULL)
        {unBalance->rchild->lchild->parent=unBalance;
            unBalance->rchild->lchild->isLeft=-1;}
        unBalance->rchild=unBalance->rchild->lchild;
        Tree->lchild=unBalance;
        unBalance->parent=Tree;
        unBalance->balance+=2;
        unBalance->isLeft=1;
        Tree->parent=NULL;
        Tree->balance+=1;
        Tree->isLeft=0;
    }
    else
    {
        BTNode *temp=unBalance->parent;
        if (unBalance->isLeft==1) {
            temp->lchild=unBalance->rchild;
            if( unBalance->rchild->lchild !=NULL)
            {unBalance->rchild->lchild->parent=unBalance;
                unBalance->rchild->lchild->isLeft=-1;}
            unBalance->rchild=unBalance->rchild->lchild;
            temp->lchild->lchild=unBalance;
            unBalance->parent=temp->lchild;
            unBalance->balance+=2;
            unBalance->isLeft=1;
            temp->lchild->parent=temp;
            temp->lchild->balance+=1;
            temp->lchild->isLeft=1;
        }
        else
        {
            temp->rchild=unBalance->rchild;
            if( unBalance->rchild->lchild !=NULL)
            {unBalance->rchild->lchild->parent=unBalance;
                unBalance->rchild->lchild->isLeft=-1;}
            unBalance->rchild=unBalance->rchild->lchild;
            temp->rchild->lchild=unBalance;
            unBalance->parent=temp->rchild;
            unBalance->balance+=2;
            unBalance->isLeft=1;
            temp->rchild->parent=temp;
            temp->rchild->balance+=1;
            temp->rchild->isLeft=-1;
        }
        CallZuZong(temp);
    }
    return OK;
}
Status LeftRightRotate(BTNode *(&unBalance),BTNode *(&Tree))
{
    BTNode *po1=NULL;
    BTNode *po2=NULL;
    if (unBalance->parent==NULL) {
        po1=unBalance->lchild->rchild;//
        po2=unBalance->lchild;//
        if( po1->lchild !=NULL)
        {po1->lchild->parent=po2;
            po1->lchild->isLeft=-1;}
        po2->rchild=po1->lchild;//
        po2->parent=po1;
        po2->balance+=1;
        po2->isLeft=1;
        po1->lchild=po2;
        if( po1->rchild !=NULL)
        {po1->rchild->parent=unBalance;
        po1->rchild->isLeft=1;}
        unBalance->lchild=po1->rchild;//
        po1->rchild=unBalance;
        po1->parent=NULL;
        po1->isLeft=0;
        Tree=po1;
        po1->balance=0;
        unBalance->parent=po1;
        unBalance->isLeft=-1;
        unBalance->balance-=3;
    }
    else
    {
        BTNode *parent=unBalance->parent;
        if (unBalance->isLeft==1) {
            po1=unBalance->lchild->rchild;
            po2=unBalance->lchild;
            if( po1->lchild !=NULL)
            {po1->lchild->parent=po2;
                po1->lchild->isLeft=-1;}
            po2->rchild=po1->lchild;//
            po2->parent=po1;
            po2->balance+=1;
            po2->isLeft=1;
            po1->lchild=po2;
            if( po1->rchild !=NULL)
            {po1->rchild->parent=unBalance;
                po1->rchild->isLeft=1;}
            unBalance->lchild=po1->rchild;
            po1->rchild=unBalance;
            po1->parent=parent;
            po1->isLeft=1;
            parent->lchild=po1;
            po1->balance=0;
            unBalance->parent=po1;
            unBalance->isLeft=-1;
            unBalance->balance-=3;
        }
        else
        {
            po1=unBalance->lchild->rchild;
            po2=unBalance->lchild;
            if( po1->lchild !=NULL)
            {po1->lchild->parent=po2;
                po1->lchild->isLeft=-1;}
            po2->rchild=po1->lchild;
            po2->parent=po1;
            po2->balance+=1;
            po2->isLeft=1;
            po1->lchild=po2;
            if( po1->rchild !=NULL)
            {po1->rchild->parent=unBalance;
            po1->rchild->isLeft=1;}
            unBalance->lchild=po1->rchild;
            po1->rchild=unBalance;
            po1->parent=parent;
            parent->rchild=po1;
            po1->isLeft=-1;
            po1->balance=0;
            unBalance->parent=po1;
            unBalance->isLeft=-1;
            unBalance->balance-=3;
        }
        CallZuZong(parent);
    }
    return OK;
}
Status RightLeftRotate(BTNode *(&unBalance),BTNode *(&Tree))
{
    BTNode *po1=NULL;
    BTNode *po2=NULL;
    if (unBalance->parent==NULL) {
        po1=unBalance->rchild->lchild;
        po2=unBalance->rchild;
        if( po1->rchild !=NULL)
        {po1->rchild->parent=po2;
        po1->rchild->isLeft=1;}
        po2->lchild=po1->rchild;//
        po2->parent=po1;
        po2->balance-=2;
        po2->isLeft=-1;
        if( po1->lchild !=NULL)
        {po1->lchild->parent=unBalance;
        po1->lchild->isLeft=-1;}
        unBalance->rchild=po1->lchild;//
        po1->rchild=po2;
        po1->lchild=unBalance;
        po1->parent=NULL;
        po1->isLeft=0;
        Tree=po1;
        po1->balance=0;
        unBalance->parent=po1;
        unBalance->isLeft=1;
        unBalance->balance+=2;//
    }
    else
    {
        BTNode *parent=unBalance->parent;
        if (unBalance->isLeft==1) {
            po1=unBalance->rchild->lchild;
            po2=unBalance->rchild;
            if( po1->rchild !=NULL)
            {po1->rchild->parent=po2;
                po1->rchild->isLeft=1;}
            po2->lchild=po1->rchild;
            po2->parent=po1;
            po2->balance-=2;
            po2->isLeft=-1;
            if( po1->lchild !=NULL)
            {po1->lchild->parent=unBalance;
            po1->lchild->isLeft=-1;}
            unBalance->rchild=po1->lchild;//
            po1->rchild=po2;
            po1->lchild=unBalance;
            po1->parent=parent;
            po1->isLeft=1;
            parent->lchild=po1;
            po1->balance=0;
            unBalance->parent=po1;
            unBalance->isLeft=1;
            unBalance->balance+=2;
        }
        else
        {
            po1=unBalance->rchild->lchild;
            po2=unBalance->rchild;
            if( po1->rchild !=NULL)
            {po1->rchild->parent=po2;
            po1->rchild->isLeft=1;}
            po2->lchild=po1->rchild;
            po2->parent=po1;
            po2->balance-=2;
            po2->isLeft=-1;
            if( po1->lchild !=NULL)
            {po1->lchild->parent=unBalance;
                po1->lchild->isLeft=-1;}
            unBalance->rchild=po1->lchild;//
            po1->rchild=po2;
            po1->lchild=unBalance;
            po1->parent=parent;
            po1->isLeft=-1;
            parent->rchild=po1;
            po1->balance=0;
            unBalance->parent=po1;
            unBalance->isLeft=1;
            unBalance->balance+=2;
        }
        CallZuZong(parent);
    }
    return OK;
}
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
Status InsertBT_Bal(BTNode *(&Tree),int tar)
{
    BTNode *newNode=NULL;
    BTNode *p = NULL;
    BTNode *unbalance=NULL;
    if (!SearchBT(Tree, tar, NULL, p)) {
        newNode=new BTNode;
        newNode->data=tar;
        newNode->lchild=newNode->rchild=NULL;
        newNode->balance=0;
        newNode->parent=p;
        if (!p) {Tree=newNode;newNode->isLeft=0;}
        else
        {
            if (tar<(p->data))
            {
                p->lchild=newNode;
                newNode->isLeft=1;
                CallDaddy(p,unbalance);
            }
            else
            {
                p->rchild=newNode;
                newNode->isLeft=-1;
                CallDaddy(p,unbalance);
            }
            if (unbalance!=NULL) {
                int isLeft1=-2;
                int isLeft2=-2;
                if (p->parent==unbalance) {
                    twoSon(newNode, unbalance, isLeft1, isLeft2);
                }
                else
                    twoSon(p, unbalance, isLeft1, isLeft2);
                //cout<<"md"<<isLeft1<<' '<<isLeft2<<endl;
                if (isLeft1==1) {
                    if (isLeft2==1)
                        RightRotate(unbalance, Tree);
                    else if(isLeft2==-1)
                        RightLeftRotate(unbalance, Tree);
                }
                else if(isLeft1==-1)
                {
                    if (isLeft2==-1)
                        LeftRotate(unbalance, Tree);
                    else if(isLeft2==1)
                        LeftRightRotate(unbalance, Tree);
                }

            }
        }
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
    int input;
    BTNode *Tree=NULL;
    BTNode *p=NULL;
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        Tree=NULL;
        for (int i=0; i<n; i++) {
            scanf("%d",&input);
            InsertBT_Bal(Tree,input);
        }
        for (int j=0; j<k; j++) {
            scanf("%d",&input);
            if (SearchBT(Tree, input, NULL, p))
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
        DestroyBT(Tree);
    }
    return 0;
}



