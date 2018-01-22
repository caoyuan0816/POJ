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
const int G_INF=0x7fffffff/2;
const int eps=10e-8;

int N,M,X;
int cost[MAX_N][MAX_N];
int dist[MAX_N];
int dist2[MAX_N];
typedef pair<int, int> P;

void dij(){
    priority_queue<P> pq;
    fill(dist, dist+N, G_INF);
    dist[X-1]=0;
    pq.push(P(0,X-1));
    
    while (!pq.empty()) {
        P p=pq.top(); pq.pop();
        int visit=p.second;
        if (dist[visit]>p.first) {
            continue;
        }
        for (int i=0; i<N; i++) {
            if (dist[visit]!=G_INF && dist[visit]+cost[visit][i]<dist[i]) {
                dist[i]=dist[visit]+cost[visit][i];
                pq.push(P(dist[i],i));
            }
        }
    }
}

void solve(){
    dij();
    for (int i=0; i<N; i++) {
        dist2[i]=dist[i];
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<i; j++) {
            swap(cost[i][j], cost[j][i]);
        }
    }
    dij();
    int res=-1;
    for (int i=0; i<N; i++) {
        res=max(res,dist[i]+dist2[i]);
    }
    printf("%d\n",res);
}

int main(void)
{
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d %d %d",&N,&M,&X);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (i!=j) {
                cost[i][j]=G_INF;
            }else{
                cost[i][j]=0;
            }
        }
    }
    for (int i=0; i<M; i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        cost[a-1][b-1]=c;
    }
    
    solve();
    
    return 0;
}
