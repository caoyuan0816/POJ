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

int N;
priority_queue<int,vector<int>,greater<int> > pq;

void solve(){
    long long ans=0;
    while (pq.size()>=2) {
        int a,b;
        a=pq.top();pq.pop();
        b=pq.top();pq.pop();
        ans+=a+b;
        pq.push(a+b);
    }
    printf("%lld\n",ans);
}

int main(void)
{
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d",&N);
    for (int i=0; i<N; i++) {
        int use;
        scanf("%d",&use);
        pq.push(use);
    }
    solve();
    
    return 0;
}
