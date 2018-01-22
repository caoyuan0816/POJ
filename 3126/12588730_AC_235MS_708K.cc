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

typedef long long ll;
int prime[1061];
bool visited[1061];
bool is_prime[MAX_N];
int dist[1061];
int a,b,ai,bi;
queue<int> que;

void make_prime(){
    int k=0;
    for (int i=0; i<MAX_N; i++) {
        is_prime[i]=true;
    }
    is_prime[0]=is_prime[1]=false;
    for (int i=2; i<10000; i++) {
        if (is_prime[i]) {
            if (i>=1000) {
                prime[k++]=i;
            }
            for (int j=2*i; j<10000; j+=i) {
                is_prime[j]=false;
            }
        }
    }
}

bool check(int x,int y){
    char strx[4],stry[4];
    int k=0;
    while (x) {
        strx[k]=(x%10+'0');
        stry[k++]=(y%10+'0');
        x/=10;y/=10;
    }
    if (strx[0]!=stry[0] && strx[1]==stry[1] && strx[2]==stry[2] && strx[3]==stry[3]) {
        return true;
    }
    if (strx[0]==stry[0] && strx[1]!=stry[1] && strx[2]==stry[2] && strx[3]==stry[3]) {
        return true;
    }
    if (strx[0]==stry[0] && strx[1]==stry[1] && strx[2]!=stry[2] && strx[3]==stry[3]) {
        return true;
    }
    if (strx[0]==stry[0] && strx[1]==stry[1] && strx[2]==stry[2] && strx[3]!=stry[3]) {
        return true;
    }
    return false;
}

void bfs(){
    
    que.push(ai);
    while (!que.empty()) {
        int u=que.front();
        //cout<<prime[u]<<endl;
        que.pop();
        for (int i=0; i<1061; i++) {
            if (!visited[i] && check(prime[u], prime[i])) {
                que.push(i);
                visited[i]=true;
                dist[i]=min(dist[u]+1,dist[i]);
            }
        }
    }
}

void solve(){
    for (int i=0; i<1061; i++) {
        if (prime[i]==a) {
            ai=i;
            visited[i]=true;
            dist[i]=0;
        }else{
            visited[i]=false;
            dist[i]=G_INF;
        }
        if (prime[i]==b) {
            bi=i;
        }
    }
    
    bfs();
    if (dist[bi]!=G_INF) {
        printf("%d\n",dist[bi]);
    }else{
        printf("Impossible\n");
    }
    
}

int main(void)
{
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    make_prime();
    
    int T;
    scanf("%d",&T);
    rep(T){
        scanf("%d %d",&a,&b);
        solve();
    }
    
    return 0;
}
