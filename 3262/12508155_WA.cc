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

struct Node {
    int T;
    int D;
    double tax;
    Node(int iT,int iD){
        T=iT;
        D=iD;
        tax=(double)D/(double)T;
    }
};

bool operator < (Node a,Node b){
    return a.tax<b.tax;
}

int N;
priority_queue<Node> pq;
int tot;

void solve(){
    int ans=0;
    while (!pq.empty()) {
        ans+=(tot-pq.top().D)*2*(pq.top().T);
        tot-=pq.top().D;
        pq.pop();
    }
    printf("%d\n",ans);
}

int main(void)
{
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d",&N);
    tot=0;
    for (int i=0; i<N; i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        pq.push(Node(a,b));
        tot+=b;
    }
    solve();
    
    return 0;
}
