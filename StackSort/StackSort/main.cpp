//
//  main.cpp
//  StackSort
//
//  Created by 李嘉诚 on 2017/9/27.
//  Copyright © 2017年 李嘉诚. All rights reserved.
//

#include <iostream>
void  HeapAdjust(long int H[],long int s,long int m)
{
    long int j;
    long int rc;
    rc=H[s];
    for (j=2*s; j<=m; j*=2) {
        if (j<m && H[j]<H[j+1]) ++j;
        if (rc>=H[j]) break;
        H[s]=H[j]; s=j;
    }
    H[s]=rc;
}
int HeapSort(long int H[],long int len)
{
    long int i;
    long int temp;
    for (i=len/2; i>0; --i) {
        HeapAdjust(H, i, len);
    }
    for (i=len; i>1; --i) {
        temp=H[i];
        H[i]=H[1];
        H[1]=temp;
        HeapAdjust(H, 1, i-1);
    }
    return 1;
}
int main(int argc, const char * argv[]) {
    long int num;
    long int input[100005];
    while (scanf("%ld",&num)!=EOF) {
        input[0]=0;
        for (long int i=1; i<=num; i++) {
            scanf("%ld",&(input[i]));
        }
        if (HeapSort(input,num)) {
            for (long int j=1; j<=num; j++) {
                printf("%ld ",input[j]);
            }
            printf("\n");
        }
        else
            printf("\n");
    }
    return 0;
}
