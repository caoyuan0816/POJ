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

#define rep(n)  for(int repp = 0; repp < (n); ++repp)

using namespace std;

int x[1000000];

int main()
{
    //freopen("/Users/mac/Documents/1", "r+", stdin);
    
    int N;
    cin>>N;
    
    rep(N){
        int L,n;
        int maxx=0,minn=0;
        scanf("%d %d",&L,&n);
        for (int i=0; i<n; i++) {
            scanf("%d",&x[i]);
        }
        for (int i=0; i<n; i++) {
            maxx=max(maxx,max(x[i],L-x[i]));
            minn=max(minn,min(x[i],L-x[i]));
        }
        printf("%d %d\n",minn,maxx);
    }
    
    return 0;
}
