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
int num[12];
bool vis[12];

int pow(int n){
    int ans=1;
    for (int i=0; i<n; i++) {
        ans*=10;
    }
    return ans;
}

void calcu(int x){
    int k=0;
    int num2[12];
    for (int i=0; i<M; i++) {
        if(!vis[i]){
            num2[k++]=num[i];
        }
    }
    do {
        int y=0;
        if(num2[0]!=0){
            for (int i=0; i<k; i++) {
                y+=num2[i]*pow(k-1-i);
            }
        }else{
            y=INF;
        }
        res=min(res,abs(x-y));
    } while (next_permutation(num2, num2+k));
    
}

void dfs(int l,int v){
    
    if(l==M/2){
        calcu(v);
        return ;
    }
    
    for (int i=0; i<M; i++) {
        if(!vis[i]){
            if(l==0 && num[i]==0){continue;}
            vis[i]=true;
            dfs(l+1, v+num[i]*pow(M/2-1-l));
            vis[i]=false;
        }
    }
    
}

void solve(){
    if(M==2){
        printf("%d\n",abs(num[0]-num[1]));
    }else{
        res=INF;
        dfs(0,0);
        printf("%d\n",res);
    }
}

int main()
{
    //freopen("/Users/mac/Documents/1", "r+", stdin);

    scanf("%d",&N);getchar();
    rep(N){
        
        for (int i=0; i<10; i++) {
            num[i]=INF;vis[i]=false;
        }
        char use;
        M=0;
        
        use=getchar();
        while (use!='\n') {
            if(use!=' '){
                num[M++]=use-'0';
            }
            use=getchar();
        }
        
        solve();
    }
    
    return 0;
}
