//
//  main.cpp
//  QuickSort
//
//  Created by 李嘉诚 on 2017/9/26.
//  Copyright © 2017年 李嘉诚. All rights reserved.
//


#include <cstdio>

int QuickSort(int a[],int left,int right)
{
    int tlf=left;
    int trt=right;
    if (left<right) {
        a[0]=a[tlf];
        while (left<right) {
            while (a[right]>a[0] && right>left)
                right--;
            
            a[left]=a[right];
            while (a[left]<=a[0] && left<right )
                left++;
            a[right]=a[left];
        }
        a[left]=a[0];
        QuickSort(a, tlf,left-1);
        QuickSort(a, left+1,trt);
    }
    return 1;
}
int main(int argc, const char * argv[]) {
    int num;
    int input[100005];
    while (scanf("%d",&num)!=EOF) {
        input[0]=0;
        for (int i=1; i<=num; i++) {
            scanf("%d",&(input[i]));
        }
        if (QuickSort(input, 1,num)) {
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

