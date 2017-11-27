//
//  main.cpp
//  StaticTableBinSearch
//
//  Created by 李嘉诚 on 2017/10/13.
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
    int l = 0;
    int r = T.length;
    int mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (T.array[mid] < tar)
            l = mid + 1;
        else
            r = mid;
    }
    if (T.array[l] == tar)
        return l;
    else
        return -1;
}
int main(int argc, const char * argv[]) {
    int n,k;
    TABLE T;
    T.array=new int[1005];
    while (cin>>n>>k) {
        for (int i=0; i<n; i++) {
            scanf("%d",&(T.array[i]));
        }
        T.length=n;
        for (int j=0; j<k; j++) {
            int temp;
            scanf("%d",&temp);
            printf("%d ",Search(T, temp));
        }
        printf("\n");
    }
    return 0;
}


