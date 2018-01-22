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
#define MAX_N 100005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int eps=10e-8;

int N,C,F;
typedef pair<int, int> P;
P cow[MAX_N];
int up[MAX_N],down[MAX_N];

void solve(){
    sort(cow, cow+C);
    
    priority_queue<int,vector<int>,greater<int> > pq1;
    priority_queue<int,vector<int>,greater<int> > pq2;
    
    for (int i=C-1; i>=0; i--) {
        if (pq1.size()<N/2) {
            pq1.push(cow[i].second);
        }else{
            queue<int> que;int use=0;
            rep(N/2){
                use+=pq1.top();
                que.push(pq1.top());
                pq1.pop();
            }
            up[i]=use;
            rep(N/2){
                pq1.push(que.front());
                que.pop();
            }
        }
    }
    
    for (int i=0; i<C; i++) {
        if (pq2.size()<N/2) {
            pq2.push(cow[i].second);
        }else{
            queue<int> que;int use=0;
            rep(N/2){
                use+=pq2.top();
                que.push(pq2.top());
                pq2.pop();
            }
            down[i]=use;
            rep(N/2){
                pq2.push(que.front());
                que.pop();
            }
        }
    }
    
    for (int i=C-N/2-1; i>=N/2; i--) {
        if (up[i]+down[i]+cow[i].second<=F) {
            printf("%d\n",cow[i].first);
            return ;
        }
    }
    printf("-1\n");
    
}

int main(void)
{
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d %d %d",&N,&C,&F);
    for (int i=0; i<C; i++) {
        scanf("%d %d",&cow[i].first,&cow[i].second);
    }
    
    solve();
    
    return 0;
}

