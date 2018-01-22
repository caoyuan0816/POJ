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
P points[MAX_N];

void solve(){
    sort(points, points+N);
    
    int t=0,res=0,i=0;
    
    while (t<T) {
        int maxx=MIN;
        
        while (points[i].first<=t+1 && i!=N) {
            if(points[i].second>t){
                maxx=max(maxx,points[i].second);
            }
            i++;
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
    ／／freopen("/Users/mac/Documents/1", "r+", stdin);
    
    scanf("%d %d",&N,&T);
    
    for (int i=0; i<N; i++) {
        scanf("%d %d",&points[i].first,&points[i].second);
    }
    
    solve();
    
    return 0;
}
