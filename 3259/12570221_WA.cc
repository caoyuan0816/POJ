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
#define MAX_N 3005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const int eps=10e-8;

int T,N,M,W;
struct edge{
    int from,to,cost;
    edge(){}
    edge(int xx,int yy,int zz){
        from=xx;to=yy;cost=zz;
    }
};
vector<edge> E;
int dist[MAX_N];

bool find_negative_loop(){
    memset(dist, sizeof(dist), 0);
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<E.size(); j++) {
            edge e=E[j];
            if (dist[e.to]>dist[e.from]+e.cost) {
                dist[e.to]=dist[e.from]+e.cost;
                if (i == N-1) {
                    return true;
                }
            }
        }
    }
    return false;
}

void solve(){
    if (!find_negative_loop()) {
        printf("NO\n");
    }else{
        printf("YES\n");
    }
}

int main(void)
{
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d",&T);
    rep(T){
        scanf("%d %d %d",&N,&M,&W);
        int a,b,c;
        for (int i=0; i<M; i++) {
            scanf("%d %d %d",&a,&b,&c);
            E.push_back(edge(a-1,b-1,c));
            E.push_back(edge(b-1,a-1,c));
        }
        for (int i=0; i<W; i++) {
            scanf("%d %d %d",&a,&b,&c);
            E.push_back(edge(a-1,b-1,-1*c));
        }
        solve();
    }
    return 0;
}
