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

int N,M;
char field[105][105];

void dfs(int x,int y){
    field[x][y]='.';
    
    for (int dx=-1; dx<=1; dx++) {
        for (int dy=-1; dy<=1; dy++) {
            int nx=x+dx,ny=y+dy;
            if(nx>=0 && ny>=0 && nx<N && ny<M && field[nx][ny]=='W'){
                dfs(nx,ny);
            }
        }
    }
    return ;
}

void solve(){
    int res=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if(field[i][j]=='W'){
                dfs(i,j);
                res++;
            }
        }
    }
    printf("%d\n",res);
    
    return ;
}

int main()
{
   // freopen("/Users/mac/Documents/1", "r+", stdin);
    
    memset(field, 0, sizeof(field));
    
    scanf("%d %d",&N,&M);
    getchar();
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%c",&field[i][j]);
        }getchar();
    }
    
    solve();
    
    return 0;
}
