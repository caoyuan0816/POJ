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
#define MAX_N 105

#define rep(n)  for(int repp = 0; repp < (n); ++repp)

using namespace std;
const int INF=0x7fffffff;

int N;
priority_queue<float> pq;

void solve(){
    float ans=pq.top();
    pq.pop();
    
    while (!pq.empty()) {
        ans=2*sqrt(ans*pq.top());
        pq.pop();
    }
    printf("%.3f\n",ans);
}

int main(void)
{
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    scanf("%d",&N);
    for (int i=0; i<N; i++) {
        float use;
        scanf("%f",&use);
        pq.push(use);
    }
    solve();
    
    return 0;
}
