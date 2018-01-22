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
#define MAX_N 10000

#define rep(n)  for(int repp = 0; repp < (n); ++repp)

using namespace std;
const int INF=0x7fffffff;

int N,S;
pair<int , int> week[MAX_N];
long long ans;

void solve(){
    ans=0;
    for (int i=0; i<N; i++) {
        ans+=week[i].first*week[i].second;
        int j=i;
        while (week[j].first+S<week[j+1].first && j<N-1) {
            ans+=(week[i].first+S)*week[i+1].second;
            j++;
        }
        i=j;
    }
}

int main(void)
{
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);

    scanf("%d %d",&N,&S);
    
    for (int i=0; i<N; i++) {
        scanf("%d %d",&week[i].first,&week[i].second);
    }
    solve();
    printf("%lld\n",ans);
    
    return 0;
}
