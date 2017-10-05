//
//  main.cpp
//  DirectlyInsertSort
//
//  Created by 李嘉诚 on 2017/9/26.
//  Copyright © 2017年 李嘉诚. All rights reserved.
//

#include <iostream>
#define Status int
#define OK 1
#define LT(a,b) (((a)<(b))?(1):(0))
#define RT(a,b) (((a)>(b))?(1):(0))

Status DirectlyInsertSort(int arry[],int len)
{
    if (len>=2) {
        int i,j;
        for (i=2; i<=len; i++) {
            if (LT(arry[i], arry[i-1])) {
                arry[0]=arry[i];
                for (j=i-1; LT(arry[0], arry[j]); j--)
                    arry[j+1]=arry[j];
                arry[j+1]=arry[0];
                
            }
        }
    }
    return OK;
}
int main(int argc, const char * argv[]) {
    int num;
    int input[1005];
    while (std::cin>>num) {
        input[0]=0;
        for (int i=1; i<=num; i++) {
            std::cin>>input[i];
        }
        if (DirectlyInsertSort(input, num)) {
            for (int j=1; j<=num; j++) {
                std::cout<<input[j]<<' ';
            }
            std::cout<<std::endl;
        }
        else
            std::cout<<std::endl;
    }
    return 0;
}
