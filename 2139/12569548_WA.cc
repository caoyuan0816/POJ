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
#define MAX_N 305

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff/2;
const int eps=10e-8;

int N,M;
int d[MAX_N][MAX_N];

void solve(){
    for (int k=0; k<N; k++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    int ans=INF;
    for (int i=0; i<N; i++) {
        int use=0;
        for (int j=0; j<N; j++) {
            use+=d[i][j];
        }
        ans=min(ans, use);
    }
    double res=(double)ans;
    res/=N-1;
    cout<<(int)res*100<<endl;
}

int main(void)
{
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d %d",&N,&M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (i==j) {
                d[i][j]=0;
            }else{
                d[i][j]=INF;
            }
        }
    }
    for (int i=0; i<M; i++) {
        int a;
        scanf("%d",&a);
        vector<int> vec;
        for (int j=0; j<a; j++) {
            int use;
            scanf("%d",&use);
            vec.push_back(use);
        }
        for (int j=0; j<a; j++) {
            for (int k=0; k<a; k++) {
                if (j!=k) {
                    d[vec[j]-1][vec[k]-1]=1;
                    d[vec[k]-1][vec[j]-1]=1;
                }
            }
        }
    }
    
    solve();
    
    return 0;
}
