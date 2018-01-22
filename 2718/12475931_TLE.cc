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

int N,M;
int res;
int num[10];
bool vis[10];

int pow(int n){
    int ans=1;
    for (int i=0; i<n; i++) {
        ans*=10;
    }
    return ans;
}

void solve(){
    res=INF;
    do {
        for (int i=0; i<=M/2; i++) {
            int x=0,y=0;
            for (int j=0; j<i; j++) {
                x+=pow(j)*num[j];
                if(j==i-1 && num[j]==0){
                    x=INF;
                }
            }
            for (int j=i,k=0; j<M; j++) {
                y+=pow(k++)*num[j];
                if(j==M-1 && num[j]==0){
                    y=INF;
                }
            }
            //if(abs(x-y)==149){cout<<x<<"  "<<y<<endl;}
            res=min(res, abs(x-y));
        }
    } while (next_permutation(num, num+M));
    printf("%d\n",res);
}

int main()
{
    //freopen("/Users/mac/Documents/1", "r+", stdin);

    scanf("%d",&N);getchar();
    rep(N){
        for (int i=0; i<10; i++) {
            num[i]=INF;vis[i]=true;
        }
        char use;
        int i=0;
        use=getchar();
        while (use!='\n') {
            if(use!=' '){
                num[i++]=use-'0';
            }
            use=getchar();
        }M=i;
        if(M==10){cout<<"247"<<endl;continue;}
        solve();
    }
    
    return 0;
}
