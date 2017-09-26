//
//  main.cpp
//  CalculatorWithStack_Table
//
//  Created by 李嘉诚 on 2017/9/24.
//  Copyright © 2017年 李嘉诚. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <stack>
using namespace std;
//全局变量
int posi=0;
char priority[7][7]={
//   '+' '-' '*' '/' '(' ')' '#'
    {'>','>','<','<','<','>','>'},//+
    {'>','>','<','<','<','>','>'},//-
    {'>','>','>','>','<','>','>'},//*
    {'>','>','>','>','<','>','>'},///
    {'<','<','<','<','<','=',' '},//(
    {'>','>','>','>',' ','>','>'},//)
    {'<','<','<','<','<',' ','='},//#
};




//tools
//1.判断是数字还是运算符
bool isNumber(char t)
{
    if (t=='+'||t=='-'||t=='*'||t=='/'||t=='('||t==')'||t=='#') {
        return false;
    }
    else
        return true;
}
//2.把字符转化为数字
int changeToNum(string &exp)
{
    int sum=0;
    while (isNumber(exp[posi])) {
        sum=sum*10+exp[posi++]-'0';
    }
    return sum;
}
//3.运算符转序号
int changeToVex(char oprt)
{
    switch (oprt) {
        case '+':
            return 0;
            break;
        case '-':
            return 1;
            break;
        case '*':
            return 2;
            break;
        case '/':
            return 3;
            break;
        case '(':
            return 4;
            break;
        case ')':
            return 5;
            break;
        case '#':
            return 6;
            break;
        default:
            return 6;
            break;
    }
}
//4.优先级比较
char PriorityCompare(char oprt1,char oprt2)
{
    int vex1=changeToVex(oprt1);
    int vex2=changeToVex(oprt2);
    return priority[vex1][vex2];
}
//5.计算结果
int calculate(int num1,char oprt,int num2)
{
    int result;
    switch (oprt) {
        case '+':
            result=num1+num2;
            break;
        case '-':
            result=num1-num2;
            break;
        case '*':
            result=num1*num2;
            break;
        case '/':
            result=num1/num2;
            break;
        default:
            result=0;
            break;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    string inp;
    stack<int> numbers;
    stack<char> oprts;
    while (cin>>inp) {
        posi=0;
        inp+='#';
        oprts.push('#');
        cout<<"Iknow"<<endl;
        while (posi<inp.length()) {
            if (isNumber(inp[posi])) {
                int temp=changeToNum(inp);
                numbers.push(temp);
            }
            else
            {
                switch (PriorityCompare(oprts.top(), inp[posi])) {
                    case '=':
                        oprts.pop();
                        posi++;
                        break;
                    case '<':
                        oprts.push(inp[posi]);
                        posi++;
                        break;
                    case '>':
                        char oprt=oprts.top();
                        oprts.pop();
                        int num2=numbers.top();
                        numbers.pop();
                        int num1=numbers.top();
                        numbers.pop();
                        int res=calculate(num1, oprt, num2);
                        numbers.push(res);
                        break;
                }
            }
        }
        cout<<numbers.top()<<endl;
    }
    return 0;
}
