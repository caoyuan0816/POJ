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

int T;
int N,M,R;
int par[20005],Rank[20005];
struct edge{
    int from,to,cost;
    edge(){
    }
    edge(int xx,int yy,int zz){
        from=xx;to=yy;cost=zz;
    }
};
edge es[MAX_N];

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
    x = find(x);y = find(y);
    if (x==y) {
        return ;
    }
    if (Rank[x]<Rank[y]) {
        par[x]=y;
    }else{
        par[y]=x;
        if (Rank[x]==Rank[y]) {
            x++;
        }
    }
}

bool same(int x,int y){
    return find(x)==find(y);
}

bool cmp(const edge &a,const edge &b){
    return a.cost<b.cost;
}

int kruskal(){
    sort(es, es+R, cmp);
    init(N+M);
    int res=0;
    for (int i=0; i<R; i++) {
        if (!same(es[i].from, es[i].to)) {
            unite(es[i].from,es[i].to);
            res+=es[i].cost;
        }
    }
    return res;
}

void solve(){
    printf("%d\n",10000*(M+N)+kruskal());
}

int main(void)
{
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d",&T);
    rep(T){
        scanf("%d %d %d",&N,&M,&R);
        for (int i=0; i<R; i++) {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            es[i]=edge(a,N+b,-1*c);
        }
        solve();
    }
    
    return 0;
}
