//
//  main.cpp
//  test1
//
//  Created by mac on 14-1-19.
//  Copyright (c) 2014年 Yuan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>

#define MAX 0x7fffffff
#define MIN (~MAX)
#define MAX_N 400

#define rep(n)  for(int repp = 0; repp < (n); ++repp)

using namespace std;
const int INF=0x7fffffff;

int N,sum;
int num[10];

bool calcu(){
    bool flag=true;
    int num1[10];
    int use[10];
    
    for (int i=0; i<N;i++) {
        num1[i]=num[i];
    }
    memset(use, 0, sizeof(use));
    
    for (int i=1; i<N; i++) {
        for (int j=i;j<N; j++) {
            if(flag){
                use[j]=num1[j-1]+num1[j];
            }else{
                num1[j]=use[j-1]+use[j];
            }
        }
        flag=!flag;
    }
    
    if(!flag){
        return use[N-1]==sum;
    }else{
        return num1[N-1]==sum;
    }
}

void solve(){
    for (int i=0; i<N; i++) {
        num[i]=i+1;
    }
    do {
        if(calcu()){
            printf("%d",num[0]);
            for (int i=1; i<N; i++) {
                printf(" %d",num[i]);
            }putchar('\n');
            break;
        }
    } while (next_permutation(num, num+N));
}

int main()
{
    //freopen("/Users/mac/Documents/1", "r+", stdin);

    scanf("%d %d",&N,&sum);
    
    solve();
    
    return 0;
}
