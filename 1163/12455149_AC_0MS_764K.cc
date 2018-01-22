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

#define rep(n)  for(int repp = 0; repp < (n); ++repp)

using namespace std;

static int s[105][105];

int main()
{
   // freopen("/Users/mac/Documents/1", "r+", stdin);
    
    int N;
    
    scanf("%d",&N);
    
    int i,j;
    for (i=1; i<=N; i++) {
        for (j=1; j<=i; j++) {
            scanf("%d",&s[i][j]);
        }
    }
    
    int ans=0;
    
    for (i=2; i<=N; i++) {
        for (j=1; j<=i; j++) {
            s[i][j]=max(s[i-1][j]+s[i][j],s[i-1][j-1]+s[i][j]);
            ans=max(s[i][j],ans);
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}
