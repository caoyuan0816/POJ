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
int dist[MAX_N][MAX_N];

void solve(){
    for (int k=0; k<N; k++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    int res=0;
    for (int i=0; i<N; i++) {
        if (dist[i][X-1]+dist[X-1][i]<G_INF) {
            res=max(res, dist[i][X-1]+dist[X-1][i]);
        }
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
                dist[i][j]=G_INF;
            }else{
                dist[i][j]=0;
            }
        }
    }
    
    for (int i=0; i<M; i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        dist[a-1][b-1]=c;
    }
    
    solve();
    
    return 0;
}
