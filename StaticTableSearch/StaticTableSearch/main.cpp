//
//  main.cpp
//  StaticTableSearch
//
//  Created by 李嘉诚 on 2017/10/12.
//  Copyright © 2017年 李嘉诚. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
typedef struct table
{
    int length;
    int *array;
}TABLE;
int Search(TABLE &T,int tar)
{
    T.array[0]=tar;
    int i;
    for (i=T.length; T.array[i]!=tar; --i);
    return i;
}
int main(int argc, const char * argv[]) {
    int n,k;
    TABLE T;
    T.array=new int[505];
    while (cin>>n>>k) {
        for (int i=1; i<=n; i++) {
            scanf("%d",&(T.array[i]));
        }
        T.length=n;
        for (int j=0; j<k; j++) {
            int temp;
            scanf("%d",&temp);
            printf("%d ",Search(T, temp)-1);
        }
        printf("\n");
    }
    return 0;
}
