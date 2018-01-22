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
#define MAX_N 1005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int eps=10e-8;

int N;
double D;
int par[MAX_N],Rank[MAX_N];
typedef pair<int , int> point;
point points[MAX_N];

void init(){
    memset(par, -1, sizeof(par));
    memset(Rank, 0, sizeof(Rank));
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

double dist(point x, point y){
    return sqrt((double)(x.first-y.first)*(x.first-y.first)+(double)(x.second-y.second)*(x.second-y.second));
}

void solve(){
    init();
    
    char ch;
    while ((ch=getchar())!=EOF) {
        if (ch=='S') {
            int a,b;
            scanf("%d %d",&a,&b);
            if (par[a-1]==-1 || par[b-1]==-1) {
                printf("FAIL\n");
            }else{
                if (same(a-1, b-1)) {
                    printf("SUCCESS\n");
                }else{
                    printf("FAIL\n");
                }
            }
        }else if(ch=='O'){
            int a;
            scanf("%d",&a);
            par[a-1]=a-1;
            for (int i=0; i<N; i++) {
                if (i!=a-1 && dist(points[i],points[a-1])-D<=eps && par[i]!=-1) {
                    unite(a-1, i);
                }
            }
        }
    }
}

int main(void)
{
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d %lf",&N,&D);
    for (int i=0; i<N; i++) {
        scanf("%d %d",&points[i].first,&points[i].second);
    }
    
    solve();
    
    return 0;
}
