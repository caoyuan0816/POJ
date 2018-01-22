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

int N,M;
int res;
int num[10];
bool vis[10];

int pow(int n){
    int ans=1;
    for (int i=0; i<n; i++) {
        ans*=10;
    }
    return ans;
}

void calcu(){
    int num1[10],num2[10],a=0,b=0;
    for (int i=0; i<M; i++) {
        if(vis[i]){
            num1[a++]=num[i];
        }else{
            num2[b++]=num[i];
        }
    }
    do {
        do {
            int x=0,y=0;
            for (int i=0; i<a; i++) {
                x+=num1[i]*pow(i);
            }
            for (int i=0; i<b; i++) {
                y+=num2[i]*pow(i);
            }
            res=min(res,abs(x-y));
        } while (next_permutation(num2, num2+b));
    } while (next_permutation(num1, num1+a));
    
}

void dfs(int l){
    
    if(l==M){
        calcu();
        return;
    }
    
    vis[l]=true;
    dfs(l+1);
    vis[l]=false;
    dfs(l+1);
    
}

void solve(){
    res=INF;
    dfs(0);
    printf("%d\n",res);
}

int main()
{
   // freopen("/Users/mac/Documents/1", "r+", stdin);

    scanf("%d",&N);getchar();
    rep(N){
        for (int i=0; i<10; i++) {
            num[i]=INF;vis[i]=true;
        }
        char use;
        int i=0;
        use=getchar();
        while (use!='\n') {
            if(use!=' '){
                num[i++]=use-'0';
            }
            use=getchar();
        }M=i;
        solve();
    }
    
    return 0;
}
