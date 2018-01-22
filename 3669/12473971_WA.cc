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

struct P {
    int x;
    int y;
    int t;
};

int N;
int maxT=0;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
vector<P> points;
int d[401][401];
int g[401][401];

bool cmp(const P &a,const P &b){
    return a.t<b.t;
}

void test(){
    for (int i=0; i<=maxT; i++) {
        for (int j=0; j<=maxT; j++) {
            if(d[i][j]==INF){
                cout<<"  I";
            }else if(d[i][j]==INF-1){
                cout<<"  X";
            }else{
                printf("%3d",d[i][j]);
            }
        }cout<<endl;
    }cout<<endl;
}

void refresh(int t){
    while (points.size() && points[0].t==t) {
        d[points[0].x][points[0].y]=INF-1;
        for (int i=0; i<4; i++) {
            int nx=points[0].x+dx[i],ny=points[0].y+dy[i];
            if(nx>=0 && nx<400 && ny>=0 && ny<400){
                d[nx][ny]=INF-1;
            }
        }
        points.erase(points.begin());
    }
}

void bfs(){
    queue<pair<int, int> > que;
    
    que.push(pair<int, int>(0,0));
    d[0][0]=0;g[0][0]=0;
    refresh(0);
    while (que.size()) {
        test();
        pair<int, int> use=que.front();que.pop();
        
        if(d[use.first][use.second]==maxT){
            break;
        }
        
        refresh(d[use.first][use.second]+1);
        
        for (int i=0; i<4; i++) {
            int nx=use.first+dx[i],ny=use.second+dy[i];
            if(nx>=0 && nx<400 && ny>=0 && ny<400 && d[nx][ny]==INF){
                que.push(pair<int, int>(nx,ny));
                d[nx][ny]=g[use.first][use.second]+1;
                g[nx][ny]=d[nx][ny];
            }
        }
    }
    if (!points.empty()) {
        for (int i=0; i<=maxT; i++) {
            refresh(i);
        }
    }
}

void solve(){
    
    for (int i=0; i<400; i++) {
        for (int j=0; j<400; j++) {
            d[i][j]=INF;g[i][j]=0;
        }
    }
    
    sort(points.begin(),points.end(),cmp);
    bfs();
    
    int ans=INF-1,range=min(maxT,401);
    for (int i=0; i<=range; i++) {
        for (int j=0; j<=range; j++) {
            ans=min(ans,d[i][j]);
        }
    }
    if(ans==INF-1){
        printf("-1\n");
    }else{
        printf("%d\n",ans);
    }
    
}

int main()
{
   // freopen("/Users/mac/Documents/1", "r+", stdin);
    
    scanf("%d",&N);
    for (int i=0; i<N; i++) {
        P use;
        scanf("%d %d %d",&use.x,&use.y,&use.t);
        maxT=max(maxT,use.t);
        points.push_back(use);
    }
    solve();
    
    return 0;
}
