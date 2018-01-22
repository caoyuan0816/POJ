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
const int eps=10e-8;

typedef pair<int, int> pp;
int N,L,P;
pp A[MAX_N];

void solve(){
    sort(A, A+N);
    priority_queue<int> pq;
    
    int ans=0,pos=0,gas=P;
    
    for (int i=0; i<=N; i++) {
        int dis=A[i].first-pos;
        while (dis>gas) {
            if (pq.empty()) {
                printf("-1\n");
                return ;
            }else{
                gas+=pq.top();
                //cout<<i<<"  "<<pq.top()<<endl;
                pq.pop();
                ans++;
            }
        }
        gas-=dis;
        pos=A[i].first;
        pq.push(A[i].second);
    }
    printf("%d\n",ans);
    return ;
}

int main(void)
{
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);

    scanf("%d",&N);
    for (int i=0; i<N; i++) {
        scanf("%d %d",&A[i].first,&A[i].second);
    }
    scanf("%d %d",&L,&P);
    for (int i=0; i<N; i++) {
        A[i].first=P-A[i].first;
    }
    A[N].first=L,A[N].second=0;
    
    solve();
    
    return 0;
}
