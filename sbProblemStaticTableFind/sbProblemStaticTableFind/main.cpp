//
//  main.cpp
//  sbProblemStaticTableFind
//
//  Created by 李嘉诚 on 2017/10/13.
//  Copyright © 2017年 李嘉诚. All rights reserved.
//

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,k;
    int mbele;
    int inp[1005];
    while (cin>>n>>k) {
        for (int i=1; i<=n; i++) {
            cin>>inp[i];
        }
        for (int j=0; j<k; j++) {
            int temp;
            cin>>temp;
            inp[k]=-1;
            mbele=find(&inp[0], &inp[k], temp);
            cout<<mbele;
        }
        cout<<endl;
    }
    return 0;
}
