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
#define MAX_N 2505

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int eps=10e-8;

typedef pair<int, int> range;
int C,L;
priority_queue<range,vector<range>,greater<range> > cow;
priority_queue<int,vector<int>,greater<int> > spf;
priority_queue<int,vector<int>,greater<int> > pq;

void solve(){
    int ans=0;
    
    while (!spf.empty()) {
        int use=spf.top();
        spf.pop();
        
        while (!cow.empty()) {
            if (cow.top().first<=use) {
                pq.push(cow.top().second);
                cow.pop();
            }else{
                break;
            }
        }
        
        while (!pq.empty()) {
            if (use<=pq.top()) {
                ans++;
                pq.pop();
                break;
            }else{
                pq.pop();
            }
        }

    }
    printf("%d\n",ans);
}

int main(void)
{
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d %d",&C,&L);
    for (int i=0; i<C; i++) {
        range use;
        scanf("%d %d",&use.first,&use.second);
        cow.push(use);
    }
    for (int i=0; i<L; i++) {
        int use,n;
        scanf("%d %d",&use,&n);
        for (int j=0; j<n; j++) {
            spf.push(use);
        }
    }
    
    solve();
    
    return 0;
}
