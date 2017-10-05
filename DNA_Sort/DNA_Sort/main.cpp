//
//  main.cpp
//  DNA_Sort
//
//  Created by 李嘉诚 on 2017/9/27.
//  Copyright © 2017年 李嘉诚. All rights reserved.
//

#include <cstdio>
#define LT(a,b) (((a)<(b))?(1):(0))
#define RT(a,b) (((a)>(b))?(1):(0))

typedef struct node{
    int key;
    int value;
}NODE;

int DirectlyInsertSort(NODE arry[],int len)
{
    if (len>=2) {
        int i,j;
        for (i=2; i<=len; i++) {
            if (LT(arry[i].value, arry[i-1].value)) {
                arry[0]=arry[i];
                for (j=i-1; LT(arry[0].value, arry[j].value); j--)
                    arry[j+1]=arry[j];
                arry[j+1]=arry[0];

            }
        }
    }
    return 1;
}
int Calculate(char inp[],int n)
{
    int sum=0;
    for (int i=1; i<=n-1; i++) {
        for (int j=i+1; j<=n; j++) {
            if (inp[j]<inp[i]) {
                sum++;
            }
        }
    }
    return sum;
}
int main(int argc, const char * argv[]) {
    char inp[101][50];
    struct node s[101];
    int n,m;
    scanf("%d%d",&n,&m);
        for (int i=1; i<=m; i++) {
            scanf("%s",inp[i]);
            s[i].key=i;
            s[i].value=Calculate(inp[i], n);
        }
        DirectlyInsertSort(s, m);
        for (int i=1; i<=m; i++) {
            printf("%s",inp[s[i].key]);
            if (i!=m) {
                printf("\n");
            }
        }
    return 0;
}


