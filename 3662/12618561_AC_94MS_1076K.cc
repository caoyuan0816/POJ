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
const long long L_INF=9223372036854775807;
const int eps=10e-8;

int N,E,K;
typedef pair<int, int> P; // first:dist second:num->[0,N)
struct edge{
    int to,cost;
    edge(int xx,int yy){
        to=xx;cost=yy;
    }
};
vector<edge> G[MAX_N];
int dist[MAX_N];
priority_queue<P,vector<P>,greater<P> > pq;

int dijkstra(int s,int x){
    while (!pq.empty()) {
        pq.pop();
    }

    fill(dist,dist+N, INF);
    dist[s]=0;
    pq.push(P(0,s));
    
    while (!pq.empty()) {
        P p=pq.top();pq.pop();
        int v=p.second;
        if (dist[v]<p.first) {
            continue;
        }
        for (int i=0; i<G[v].size(); i++) {
            edge e=G[v][i];
            
            if (dist[e.to]>dist[v]+(e.cost<=x?0:1)) {
                dist[e.to]=dist[v]+(e.cost<=x?0:1);
                pq.push(P(dist[e.to],e.to));
            }
        }
    }
    //cout<<dist[N-1]<<endl;
    if (dist[N-1]==INF) {
        return -1;
    }else if (dist[N-1]<=K) {
        return 1;
    }else{
        return 0;
    }
}

void solve(){
    
    int l=-1,r=1000005,mid;
    while (r-l>1) {
        mid=(l+r)/2;
        //cout<<l<<" "<<mid<<" "<<r<<endl;
        switch (dijkstra(0, mid)) {
            case -1:
                printf("-1\n");
                return;
                break;
            case 1:
                r=mid;
                break;
            case 0:
                l=mid;
                break;
        }
    }
    
    printf("%d\n",r);

}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d %d %d",&N,&E,&K);
    for (int i=0; i<E; i++) {
        int from,to,cost;
        scanf("%d %d %d",&from,&to,&cost);
        from--;to--;
        G[from].push_back(edge(to,cost));
        G[to].push_back(edge(from,cost));
    }
    solve();
    
    return 0;
}