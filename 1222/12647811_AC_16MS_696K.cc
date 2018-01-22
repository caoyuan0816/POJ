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
#define MAX_N 6

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

const int M=5,N=6;
const int dx[5]={-1,0,0,0,1};
const int dy[5]={0,-1,0,1,0};

int grid[MAX_N][MAX_N];

int great[MAX_N][MAX_N];
int flip[MAX_N][MAX_N];

int get_color(int x,int y){
    int c=grid[x][y];
    for (int i=0; i<5; i++) {
        int nx=x+dx[i],ny=y+dy[i];
        if (nx>=0 && nx<M && ny>=0 && ny<N) {
            c+=flip[nx][ny];
        }
    }
    return c%2;
}

int calcu(){
    int res=0;
    for (int i=1; i<M; i++) {
        for (int j=0; j<N; j++) {
            if (get_color(i-1, j)==1) {
                flip[i][j]=1;
                res++;
            }
        }
    }
    
    for (int j=0; j<N; j++) {
        if (get_color(M-1, j)==1) {
            return -1;
        }
    }
    
    for (int j=0; j<N; j++) {
        res+=flip[0][j];
    }
    
    return res;
}

void solve(){
    int res=-1;
    for (int i=0; i<(1<<N); i++) {
        memset(flip, 0, sizeof(flip));
        for (int j=0; j<N; j++) {
            flip[0][N-1-j]=i>>j&1;
        }
        int use=calcu();
        if (use>=0 && (res<0 || res>use)) {
            res=use;
            memcpy(great, flip, sizeof(flip));
        }
    }
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            printf("%d%c",great[i][j],j==N-1?'\n':' ');
        }
    }
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    int T;
    scanf("%d",&T);
    for (int t=0; t<T; t++) {
        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) {
                scanf("%d",&grid[i][j]);
            }
        }
        printf("PUZZLE #%d\n",t+1);
        solve();
    }
 
    return 0;
}
