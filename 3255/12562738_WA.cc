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
#define MAX_N 5005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int eps=10e-8;

int N,R;
typedef pair<int, int> P;
struct edge{
    int to,cost;
    edge(int x,int y){
        to=x;
        cost=y;
    }
};
vector<edge> G[MAX_N];
int dist[MAX_N];
int dist2[MAX_N];

void solve(){
    priority_queue<P,vector<P>,greater<P> > pq;
    
    fill(dist, dist+N, INF);
    fill(dist2,dist2+N,INF);
    dist[0]=0;
    pq.push(P(0,0));
    
    while (!pq.empty()) {
        P p=pq.top();pq.pop();
        int v=p.second,d=p.first;
        if (dist2[v]<d) {
            continue;
        }
        for (int i=0; i<G[v].size(); i++) {
            edge e = G[v][i];
            int d2=d+e.cost;
            if (dist[e.to]>d2) {
                swap(dist[e.to], d2);
                pq.push(P(dist[e.to],e.to));
            }
            if (dist2[e.to]>d2 && d2>dist[e.to]) {
                dist2[e.to]=d2;
                pq.push(P(dist2[e.to],e.to));
            }
        }
    }
    printf("%d\n",dist2[N-1]);
}

int main(void)
{
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d %d",&N,&R);
    int a,b,cost;
    for (int i=0; i<R; i++) {
        scanf("%d %d %d",&a,&b,&cost);
        G[a-1].push_back(edge(b-1,cost));
    }
    
    solve();
    
    return 0;
}
