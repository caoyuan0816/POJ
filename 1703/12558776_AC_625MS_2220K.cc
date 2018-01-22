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
#define MAX_N 100005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int eps=10e-8;

int par[2*MAX_N],Rank[2*MAX_N];
int T,N,M;

void init(int x){
    for (int i=0; i<x; i++) {
        par[i]=i;
        Rank[i]=0;
    }
}

int find(int x){
    if (par[x]==x) {
        return x;
    }else{
        return par[x]=find(par[x]);
    }
}

void unite(int x,int y){
    x = find(x);
    y = find(y);
    
    if (x==y) {
        return ;
    }
    
    if (Rank[x]<Rank[y]) {
        par[x]=y;
    }else{
        par[y]=x;
        if (Rank[x]==Rank[y]) {
            Rank[x]++;
        }
    }
}

bool same(int x,int y){
    return find(x)==find(y);
}

void solve(){
    scanf("%d %d",&N,&M);
    init(2*N);
    
    char ch;
    int a,b;
    for (int i=0; i<M; i++) {
        getchar();
        ch=getchar();
        scanf("%d %d",&a,&b);
        if (ch=='A') {
            if(same(a-1, b-1) && same(a-1+N, b-1+N)){
                printf("In the same gang.\n");
            }else if(same(a-1, b-1+N) && same(a-1+N, b-1)){
                printf("In different gangs.\n");
            }else{
                printf("Not sure yet.\n");
            }
        }else if(ch=='D'){
            unite(a-1, b-1+N);
            unite(a-1+N, b-1);
        }
    }
}

int main(void)
{
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d",&T);
    rep(T){
        solve();
    }
    
    return 0;
}
