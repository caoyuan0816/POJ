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
#define MAX_N 400

#define rep(n)  for(int repp = 0; repp < (n); ++repp)

using namespace std;
const int INF=0x7fffffff;

struct Node{
    int x,y,t;
    Node(int xx,int yy,int tt){x=xx;y=yy;t=tt;}
};

int N;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int map[MAX_N][MAX_N];
bool flag[MAX_N][MAX_N];

void des(int x,int y,int t){
    for (int i=0; i<4; i++) {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>=0 && nx<MAX_N && ny>=0 && ny<MAX_N){
            map[nx][ny]=min(map[nx][ny],t);
        }
    }
}

int bfs(){
    queue<Node> que;
    
    que.push(Node(0,0,0));flag[0][0]=true;
    
    while (que.size()) {
        Node use=que.front();que.pop();
        if(map[use.x][use.y]==INF){return use.t;}
        for (int i=0; i<4; i++) {
            int nx=use.x+dx[i],ny=use.y+dy[i],nt=use.t+1;
            if(!flag[nx][ny] && nx>=0 && nx<MAX_N && ny>=0 && ny<MAX_N && nt<map[nx][ny]){
                que.push(Node(nx,ny,nt));flag[nx][ny]=true;
            }
        }
    }
    return -1;
}

void solve(){
    printf("%d\n",bfs());
}

int main()
{
    //freopen("/Users/mac/Documents/1", "r+", stdin);
    
    for (int i=0; i<MAX_N; i++) {
        for (int j=0; j<MAX_N; j++) {
            map[i][j]=INF;flag[i][j]=false;
        }
    }
    
    scanf("%d",&N);
    
    for (int i=0; i<N; i++) {
        int x,y,t;
        scanf("%d %d %d",&x,&y,&t);
        map[x][y]=min(map[x][y],t);
        des(x,y,t);
    }
    
    solve();
    
    return 0;
}
