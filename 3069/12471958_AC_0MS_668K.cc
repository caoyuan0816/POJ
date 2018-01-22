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

#define rep(n)  for(int repp = 0; repp < (n); ++repp)

using namespace std;
const int INF=100000000;

int R,n;
int x[1005];

void solve(){
    sort(x, x+n);
    
    int i=0,ans=0;
    while (i<n) {
        int left = x[i++];
        while (i<n && left+R>=x[i]){
            i++;
        }
        int mark = x[i-1];
        while (i<n && mark+R>=x[i]) {
            i++;
        }
    
        ans++;
    }
    printf("%d\n",ans);
    
}

int main()
{
   // freopen("/Users/mac/Documents/1", "r+", stdin);
    
    while(scanf("%d %d",&R,&n)==2 && !(R==-1 && n==-1)){
        for (int i=0; i<n; i++) {
            scanf("%d",&x[i]);
        }
        solve();
    }
    
    return 0;
}
