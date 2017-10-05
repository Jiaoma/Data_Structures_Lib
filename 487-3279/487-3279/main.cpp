//
//  main.cpp
//  487-3279
//
//  Created by 李嘉诚 on 2017/9/29.
//  Copyright © 2017年 李嘉诚. All rights anserved.
//


#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
using namespace std;
char change(char input){
    if(input <= 'C') return '2';
    else if(input <= 'F') return '3';
    else if(input <= 'I') return '4';
    else if(input <= 'L') return '5';
    else if(input <= 'O') return '6';
    else if(input <= 'S') return '7';
    else if(input <= 'V') return '8';
    else if(input <= 'Y') return '9';
    else return ' ';
}
int main()
{
    int N;
    bool flag = false;
    cin >> N;
    map<string,int> counter;
    while(N--){
        string s,ans;
        cin >> s;
        for(string::iterator s_it = s.begin();s_it != s.end();++s_it){
            if(*s_it >= '0' && *s_it <= '9') ans.push_back(*s_it);
            if(*s_it >= 'A' && *s_it <= 'Z') ans.push_back(change(*s_it));
        }
        ans.insert(3,1,'-');
        ++counter[ans];
    }
    map<string,int>::iterator map_it = counter.begin();
    for(;map_it != counter.end();++map_it)
        if(map_it->second >= 2){
            flag = true;
            cout << map_it->first << " " << map_it->second << endl;
        }
    if(!flag)
        cout << "No duplicates." << endl;
    return 0;
}
