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
#define MAX_N 10005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const int eps=10e-8;

int N;
struct edge {
    int from,to,cost;
    edge(){}
    edge(int xx,int yy,int zz){
        from=xx;to=yy;cost=zz;
    }
};
vector<edge> E;
int par[MAX_N],Rank[MAX_N];

void init(int x){
    for (int i=0; i<x; i++) {
        par[i]=i;
        Rank[i]=INF;
    }
}

int find(int x){
    if (par[x]==x) {
        return x;
    }else{
        return par[x]=find(par[x]);
    }
}

void unite(int x, int y){
    x=find(x);
    y=find(y);
    
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

bool cmp(const edge &a,const edge &b){
    return a.cost<b.cost;
}

void solve(){
    sort(E.begin(), E.end(), cmp);
    
    init((int)E.size());
    int ans=0;
    for (int i=0; i<E.size(); i++) {
        if (!same(E[i].from,E[i].to)) {
            ans+=E[i].cost;
            unite(E[i].from, E[i].to);
        }
    }
    printf("%d\n",ans);
}

int main(void)
{
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    while (scanf("%d",&N)!=EOF) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                int use;
                scanf("%d",&use);
                E.push_back(edge(i,j,use));
            }
        }
        solve();
        E.clear();
    }

    return 0;
}
