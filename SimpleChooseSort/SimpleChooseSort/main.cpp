//
//  main.cpp
//  SimpleChooseSort
//
//  Created by 李嘉诚 on 2017/11/4.
//  Copyright © 2017年 李嘉诚. All rights reserved.
//

#include <iostream>
#include<cstdio>
bool SimpleChooseSort(int a[],int len)
{
    int i,j,k;
    int min;
    for (i=1; i<len; i++) {
        min=a[i];
        k=i;
        for (j=i+1; j<=len; j++) {
            if (min>a[j]) {
                min=a[j];
                k=j;
            }
        }
        if (i!=k) {
            int temp=a[i];
            a[i]=a[k];
            a[k]=temp;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    int num;
    int input[100005];
    while (scanf("%d",&num)!=EOF) {
        input[0]=0;
        for (int i=1; i<=num; i++) {
            scanf("%d",&(input[i]));
        }
        if (SimpleChooseSort(input,num)) {
            for (int j=1; j<=num; j++) {
                printf("%d ",input[j]);
            }
            printf("\n");
        }
        else
            printf("\n");
    }
    return 0;
}
