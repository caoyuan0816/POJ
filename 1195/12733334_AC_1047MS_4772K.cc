//
//  main.cpp
//  test
//
//  Created by Yuan on 14-1-29.
//  Copyright (c) 2014年 Yuan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>

#define MAX 0x7fffffff
#define MIN (~MAX)
#define MAX_N 1025

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

struct edge {
    int a,b,c,d;
};
int N;
int bit[MAX_N][MAX_N];

void add(int x,int y,int v){
    for (int i=x; i<=N; i+=i&-i) {
        for (int j=y; j<=N; j+=j&-j) {
            bit[i][j]+=v;
        }
    }
}

int sum(int x,int y){
    if (x==0 || y==0) {
        return 0;
    }
    int s=0;
    for (int i=x; i>0; i-=i&-i) {
        for (int j=y; j>0; j-=j&-j) {
            s+=bit[i][j];
        }
    }
    return s;
}

void solve(){
    int use;
    while (scanf("%d",&use)!=EOF) {
        if (use==3) {
            break;
        }
        if (use==0) {
            scanf("%d",&N);
            memset(bit, 0, sizeof(bit));
        }else if (use==1){
            int x,y,a;
            scanf("%d %d %d",&x,&y,&a);
            add(x+1, y+1, a);
        }else if (use==2){
            int l,b,r,t;
            scanf("%d %d %d %d",&l,&b,&r,&t);
            int res=0;
            res+=sum(r+1, t+1);
            res-=sum(r+1, b);
            res-=sum(l, t+1);
            res+=sum(l, b);
            printf("%d\n",res);
        }
    }
}

int main(void){
    
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    solve();
    
    return 0;
}
