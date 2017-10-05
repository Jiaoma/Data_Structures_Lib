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
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
typedef struct node{
    int vex;
    int height;
    int width;
}NODE;

int DirectlyInsertSort(NODE arry[],int len)
{
    if (len>=2) {
        int i,j;
        for (i=2; i<=len; i++) {
            if (LT(arry[i].vex, arry[i-1].vex)) {
                arry[0]=arry[i];
                for (j=i-1; LT(arry[0].vex, arry[j].vex); j--)
                    arry[j+1]=arry[j];
                arry[j+1]=arry[0];
                
            }
        }
        for (i=2; i<=len; i++) {
            if (arry[i].vex==arry[i-1].vex && LT(arry[i].height, arry[i-1].height)) {
                arry[0]=arry[i];
                for (j=i-1;arry[0].vex==arry[j].vex && LT(arry[0].height, arry[j].height); j--)
                    arry[j+1]=arry[j];
                arry[j+1]=arry[0];
                
            }
        }
        for (i=2; i<=len; i++) {
            if (arry[i].vex==arry[i-1].vex && arry[i].height==arry[i-1].height && LT(arry[i].width, arry[i-1].width)) {
                arry[0]=arry[i];
                for (j=i-1;arry[0].vex==arry[j].vex &&
                     arry[0].height==arry[j].height && LT(arry[0].width, arry[j].width); j--)
                    arry[j+1]=arry[j];
                arry[j+1]=arry[0];
                
            }
        }
        
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    struct node s[10001];
    int n,m;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%d",&m);
        for (int j=1; j<=m; j++) {
            scanf("%d",&(s[j].vex));
            int t1,t2;
            scanf("%d%d",&t1,&t2);
            s[j].height=MAX(t1, t2);
            s[j].width=MIN(t1, t2);
        }
        DirectlyInsertSort(s, m);
        int tv,tw,th;
        tv=s[1].vex;
        tw=s[1].width;
        th=s[1].height;
        printf("%d %d %d\n",s[1].vex,s[1].height,s[1].width);
        for (int k=2; k<=m; k++) {
            if (tv!=s[k].vex || tw!=s[k].width || th!=s[k].height) {
                printf("%d %d %d\n",s[k].vex,s[k].height,s[k].width);
            }
            tv=s[k].vex;
            tw=s[k].width;
            th=s[k].height;
        }
    }
    return 0;
}



