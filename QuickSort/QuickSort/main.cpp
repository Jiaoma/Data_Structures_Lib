//
//  main.cpp
//  QuickSort
//
//  Created by 李嘉诚 on 2017/9/26.
//  Copyright © 2017年 李嘉诚. All rights reserved.
//

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
    }
    return 1;
}
int main(int argc, const char * argv[]) {
    long int num;
    long int input[100005];
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
    }
    return 0;
}

