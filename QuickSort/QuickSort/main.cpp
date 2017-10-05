//
//  main.cpp
//  QuickSort
//
//  Created by 李嘉诚 on 2017/9/26.
//  Copyright © 2017年 李嘉诚. All rights reserved.
//

#include <cstdio>
long int Partition(long int ary[],long int low,long int high)
{
    long int p;
    ary[0]=ary[low];
    p=ary[low];
    while (low<high) {
        while (low<high && ary[high]>=p) --high;
        ary[low]=ary[high];
        while (low<high && ary[low]<=p) ++low;
        ary[high]=ary[low];
    }
    ary[low]=ary[0];
    return low;
}
int QuickSort(long int ary[],long int low,long int high)
{
    long int p;
    if (low<high) {
        p=Partition(ary, low, high);
        QuickSort(ary, low, p-1);
        QuickSort(ary, p+1, high);
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
        if (QuickSort(input, 1,num)) {
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

