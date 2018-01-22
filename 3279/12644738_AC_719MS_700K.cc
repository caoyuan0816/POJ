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
#define MAX_N 20

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

const int dx[5] = {-1,0,0,0,1};
const int dy[5] = {0,-1,0,1,0};

int M,N;

int grid[MAX_N][MAX_N];

int great[MAX_N][MAX_N];
int flip[MAX_N][MAX_N];

int get_color(int x, int y){
    int c=grid[x][y];
    for (int i=0; i<5; i++) {
        int nx=x+dx[i],ny=y+dy[i];
        if (nx>=0 && nx<M && ny>=0 && ny<N) {
            c+=flip[nx][ny];
        }
    }
    return c%2;
}

int clacu(){
    for (int i=1; i<M; i++) {
        for (int j=0; j<N; j++) {
            if (get_color(i-1, j)!=0) {
                flip[i][j]=1;
            }
        }
    }
    for (int j=0; j<N; j++) {
        if (get_color(M-1, j)!=0) {
            return -1;
        }
    }
    int res=0;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            res+=flip[i][j];
        }
    }
    return res;
}

void solve(){
    int res=-1;
    
    for (int i=0; i<(1<<N); i++) {
        memset(flip, 0, sizeof(flip));
        for (int j=0; j<N; j++) {
            flip[0][N-j-1]=i>>j&1;
        }
        int use=clacu();
        if (use>=0 && (res<0 || res>use)) {
            res=use;
            memcpy(great, flip, sizeof(flip));
        }
    }
    if (res==-1) {
        printf("IMPOSSIBLE\n");
    }else{
        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) {
                printf("%d%c",great[i][j],j==N-1?'\n':' ');
            }
        }
    }
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d %d",&M,&N);
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d",&grid[i][j]);
        }
    }
    
    solve();
    
    return 0;
}
