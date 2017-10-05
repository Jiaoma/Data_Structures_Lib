//
//  main.cpp
//  QuickSort
//
//  Created by 李嘉诚 on 2017/9/26.
//  Copyright © 2017年 李嘉诚. All rights reserved.
//

<<<<<<< HEAD
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
=======
#include <iostream>
void print(long int input[])
{
    for (int i=1; i<=10; i++) {
        std::cout<<input[i];
    }
    std::cout<<std::endl;
}
int QuickSort(long int a[],long int left,long int right)
{
    long int tlf=left;
    long int trt=right;
    if (left<right) {
        long int key=a[tlf];
        while (left<right) {
            while (a[right]>key && right>left)
                right--;
            
            a[0]=a[right];
            while (a[left]<key && left<right )
                left++;
            a[right]=a[left];
            if (right>left) {
                a[left]=a[0];
            }
        }
        a[left]=key;
        print(a);
        QuickSort(a, tlf,left-1);
        QuickSort(a, left+1,trt);
>>>>>>> 46a4c72d6cba90b5892ea941865651cd822b4713
    }
    return 1;
}
int main(int argc, const char * argv[]) {
    long int num;
    long int input[100005];
<<<<<<< HEAD
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
=======
    while (std::cin>>num) {
        input[0]=0;
        for (long int i=1; i<=num; i++) {
            std::cin>>input[i];
        }
        if (QuickSort(input, 1,num)) {
            for (long int j=1; j<=num; j++) {
                std::cout<<input[j]<<' ';
            }
            std::cout<<std::endl;
        }
        else
            std::cout<<std::endl;
>>>>>>> 46a4c72d6cba90b5892ea941865651cd822b4713
    }
    return 0;
}

