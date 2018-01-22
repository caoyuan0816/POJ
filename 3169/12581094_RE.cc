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

int N,ML,MD;
int AL[MAX_N],BL[MAX_N],DL[MAX_N];
int AD[MAX_N],BD[MAX_N],DD[MAX_N];
int dist[MAX_N];

void solve(){
    fill(dist, dist+N, G_INF);
    dist[0]=0;
    
    for (int k=0; k<N; k++) {
        for (int i=0; i<N-1; i++) {
            if (dist[i+1]!=G_INF) {
                dist[i]=min(dist[i],dist[i+1]);
            }
        }
        for (int i=0; i<ML; i++) {
            if (dist[AL[i]-1]!=G_INF) {
                dist[BL[i]-1]=min(dist[BL[i]-1],dist[AL[i]-1]+DL[i]);
            }
        }
        for (int i=0; i<MD; i++) {
            if (dist[BD[i]-1]!=G_INF) {
                dist[AD[i]-1]=min(dist[AD[i]-1],dist[BD[i]-1]-DD[i]);
            }
        }
    }
    
    int res=dist[N-1];
    if (dist[0]<0) {
        printf("-1\n");
    }else if(res==G_INF){
        printf("-2\n");
    }else{
        printf("%d\n",res);
    }
}

int main(void)
{
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d %d %d",&N,&ML,&MD);
    for (int i=0; i<ML; i++) {
        scanf("%d %d %d",&AL[i],&BL[i],&DL[i]);
    }
    for (int i=0; i<MD; i++) {
        scanf("%d %d %d",&AD[i],&BD[i],&DD[i]);
    }
    
    solve();
    
    return 0;
}
