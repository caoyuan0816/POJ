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

int W,H;
int sx,sy;
int gx,gy;
int res;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int maze[21][21];

void dfs(int x,int y,int l){
    int level=l;
    if(level>=10){return ;}//剪枝
    for (int i=0; i<4; i++) {
        int nx=x+dx[i],ny=y+dy[i];
        bool flag=false;
        while(nx>=0 && nx<H && ny>=0 && ny<W && maze[nx][ny]==0){
            flag=true;
            if(nx==gx && ny==gy){
                res=min(res,level+1);
            }
            nx+=dx[i];ny+=dy[i];
        }
        if(flag && nx>=0 && nx<H && ny>=0 && ny<W && maze[nx][ny]==1){
            maze[nx][ny]=0;
            dfs(nx-dx[i], ny-dy[i], level+1);
            maze[nx][ny]=1;
        }
    }
}

void solve(){
    res=INF;
    dfs(sx, sy, 0);
    if(res==INF){
        printf("-1\n");
    }else{
        printf("%d\n",res);
    }
}

int main()
{
    //freopen("/Users/mac/Documents/1", "r+", stdin);
   
    while (scanf("%d %d",&W,&H) && !(W==0 && H==0)) {
        for (int i=0; i<H; i++) {
            for (int j=0; j<W; j++) {
                scanf("%d",&maze[i][j]);
                if(maze[i][j]==2){
                    sx=i;sy=j;maze[i][j]=0;
                }
                if(maze[i][j]==3){
                    gx=i;gy=j;maze[i][j]=0;
                }
            }
        }
        solve();
    }
    
    
    return 0;
}
