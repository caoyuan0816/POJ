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

int N,M;
int sx,sy;
int ans;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char maze[21][21];

void dfs(int x,int y){
    ans++;maze[x][y]='#';
    for (int i=0; i<4; i++) {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>=0 && nx<N && ny>=0 && ny<M && maze[nx][ny]=='.'){
            dfs(nx,ny);
        }
    }
}

void solve(){
    ans=0;
    dfs(sx,sy);
    printf("%d\n",ans);
}

int main()
{
   // freopen("/Users/mac/Documents/1", "r+", stdin);
    
    while (scanf("%d %d",&M,&N)==2 && !(N==0 && M==0)) {
        getchar();
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                scanf("%c",&maze[i][j]);
                if(maze[i][j]=='@'){
                    sx=i;sy=j;
                }
            }getchar();
        }
        solve();
    }
    
    return 0;
}
