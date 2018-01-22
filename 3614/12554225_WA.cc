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

void solve(){
    int ans=0;
    
    while ((!cow.empty()) && (!spf.empty())) {
        if (spf.top()>cow.top().first && spf.top()<cow.top().second) {
            ans++;
            spf.pop();cow.pop();
        }else{
            if (spf.top()<=cow.top().first) {
                spf.pop();
            }
            if (spf.top()>=cow.top().second) {
                cow.pop();
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
