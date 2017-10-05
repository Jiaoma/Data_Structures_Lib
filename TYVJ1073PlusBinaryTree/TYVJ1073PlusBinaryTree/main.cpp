//
//  main.cpp
//  TYVJ1073PlusBinaryTree
//
//  Created by 李嘉诚 on 2017/9/25.
//  Copyright © 2017年 李嘉诚. All rights reserved.
//

#include <iostream>
using namespace std;
int num;
long long input[50];
long long tree[50][50];
int result[50][50];
int counter;

int printTree(int lchild,int rchild)
{
    if (lchild>rchild) {
        return 0;
    }
    int k=result[lchild][rchild];
    cout<<k;
    counter++;
    if (counter<num) {
        cout<<' ';
    }
    printTree(lchild,k-1);
    printTree(k+1,rchild);
    return 1;
}
int main(int argc, const char * argv[]) {
    while (cin>>num) {
        counter=0;
        for (int i=1; i<=num; i++) {
            cin>>input[i];
            tree[i][i]=input[i];
            result[i][i]=i;
        }
        for (int i=num; i>0; i--) {
            for (int j=i+1; j<=num; j++) {
                for (int k=i; k<=j; k++) {
                    long long x=tree[i][k-1];
                    long long y=tree[k+1][j];
                    if (x==0) {
                        x=1;
                    }
                    if (y==0) {
                        y=1;
                    }
                    if (tree[i][j]<(x*y+input[k])) {
                        tree[i][j]=x*y+input[k];
                        result[i][j]=k;
                    }
                }
            }
        }
        cout<<tree[1][num]<<endl;
        printTree(1, num);
        cout<<endl;
    }
    return 0;
}
