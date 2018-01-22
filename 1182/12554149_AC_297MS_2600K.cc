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
#define MAX_N 50005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int eps=10e-8;

int N,K;
int par[3*MAX_N];
int Rank[3*MAX_N];
int T[100005],X[100005],Y[100005];

void init(int n){
    for (int i=0; i<n; i++) {
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
    x =find(x);
    y =find(y);
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
    init(3*N);
    
    int ans=0;
    for (int i=0; i<K; i++) {
        int t=T[i],x=X[i]-1,y=Y[i]-1;
        
        if(x<0 || x>N-1 || y<0 || y>N-1){
            ans++;
            continue;
        }
        
        if (t==1) {
            if (same(x, y+N) || same(x, y+2*N)) {
                ans++;
            }else{
                unite(x, y);
                unite(x+N, y+N);
                unite(x+2*N, y+2*N);
            }
        }else{
            if (same(x, y) || same(x, y+2*N)) {
                ans++;
            }else{
                unite(x, y+N);
                unite(x+N, y+2*N);
                unite(x+2*N, y);
            }
        }
    }
    printf("%d\n",ans);
}

int main(void)
{
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);

    scanf("%d %d",&N,&K);
    for (int i=0; i<K; i++) {
        scanf("%d %d %d",&T[i],&X[i],&Y[i]);
    }
    
    solve();
    
    return 0;
}
