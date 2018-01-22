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

#define MAX 0x7fffffff
#define MIN (~MAX)
#define MAX_N 5

#define rep(n)  for(int repp = 0; repp < (n); ++repp)

using namespace std;
const int INF=0x7fffffff;

int grid[MAX_N][MAX_N];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
vector<int> num;

int pow(int n){
    int ans=1;
    for (int i=0; i<n;i++) {
        ans*=10;
    }
    return ans;
}

void dfs(int x,int y,int l,int v){
    
    if (l==5) {
        if (find(num.begin(), num.end(), v)==num.end()) {
            num.push_back(v);
        }
        return ;
    }
    
    for (int i=0; i<4; i++) {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>=0 && nx<MAX_N && ny>=0 && ny<MAX_N){
            dfs(nx, ny, l+1,v+pow(5-l-1)*grid[nx][ny]);
        }
    }
}

void solve(){
    for (int i=0; i<MAX_N; i++) {
        for (int j=0; j<MAX_N; j++) {
            dfs(i, j, 0, pow(5)*grid[i][j]);
        }
    }
    printf("%d\n",num.size());
}

int main()
{
    //freopen("/Users/mac/Documents/1", "r+", stdin);

    for (int i=0; i<MAX_N; i++) {
        for (int j=0; j<MAX_N; j++) {
            scanf("%d",&grid[i][j]);
        }
    }
    
    solve();
    
    return 0;
}
