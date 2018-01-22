//
//  main.cpp
//  test
//
//  Created by Yuan on 14-1-29.
//  Copyright (c) 2014年 Yuan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>

#define MAX 0x7fffffff
#define MIN (~MAX)
#define MAX_N 50005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)

using namespace std;
const int INF=0x7fffffff;

struct P {
    int first;
    int second;
    int num;
    P(){}
};

bool operator < (P a,P b){
    if (a.first==b.first) {
        return a.second<b.second;
    }
    return a.first<b.first;
}

struct Node{
    int x;
    int y;
    Node(int xx,int yy){
        x=xx;
        y=yy;
    }
};

bool operator < (Node a, Node b){
    return a.x>b.x;
}

int N;
P cow[MAX_N];
int ans[MAX_N];

void solve(){
    sort(cow, cow+N);
    int k=1;
    priority_queue<Node> pq;
    pq.push(Node(cow[0].second,k));ans[cow[0].num]=1;
    for (int i=1; i<N; i++) {
        if (cow[i].first>pq.top().x) {
            int use=pq.top().y;
            pq.pop();
            pq.push(Node(cow[i].second,use));
            ans[cow[i].num]=use;
        }else{
            pq.push(Node(cow[i].second,++k));
            ans[cow[i].num]=k;
        }
    }
    cout<<k<<endl;
    for (int i=0; i<N; i++) {
        printf("%d\n",ans[i]);
    }
}

int main(void)
{
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);

    scanf("%d",&N);
    
    for (int i=0; i<N; i++) {
        scanf("%d %d",&cow[i].first,&cow[i].second);
        cow[i].num=i;
    }
    solve();
    
    return 0;
}
