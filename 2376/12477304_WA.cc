//
//  main.cpp
//  test1
//
//  Created by mac on 14-1-19.
//  Copyright (c) 2014年 Yuan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
#include <stack>

#define MAX 0x7fffffff
#define MIN (~MAX)
#define MAX_N 25005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)

using namespace std;
const int INF=0x7fffffff;

int N,T;
typedef pair<int, int> P;
vector<P> points;

void solve(){
    sort(points.begin(), points.end());
    
    int t=1,res=0;
    
    while (t<T) {
        int maxx=MIN;
        while (points[0].first<=t && points.size()) {
            if(points[0].second>t){
                maxx=max(maxx,points[0].second);
            }
            points.erase(points.begin());
        }
        if(maxx==MIN){
            printf("-1\n");
            return;
        }
        res++;
        t=maxx;
    }
    printf("%d\n",res);
}

int main()
{
    //freopen("/Users/mac/Documents/1", "r+", stdin);
    
    scanf("%d %d",&N,&T);
    
    for (int i=0; i<N; i++) {
        P p(0,0);
        scanf("%d %d",&p.first,&p.second);
        points.push_back(p);
    }
    
    solve();
    
    return 0;
}
