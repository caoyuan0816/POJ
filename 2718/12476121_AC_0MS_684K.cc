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

void solve(){
    if (M==2) {
        printf("%d\n",abs(num[0]-num[1]));
    }else{
        if (M%2==0) {
            int minn=MAX;
            for (int i=1; i<M; i++) {
                if(num[i-1]!=0){
                    minn=min(minn,num[i]-num[i-1]);
                }
            }
            int res=INF;
            for (int i=1; i<M; i++) {
                int x=0,y=0;
                if(num[i]-num[i-1]==minn && num[i-1]!=0){
                    x+=pow(M/2-1)*num[i];
                    y+=pow(M/2-1)*num[i-1];
                    for (int j=0,k=M/2-2; k>=0; j++) {
                        if(j!=i-1 && j!=i){
                            x+=pow(k--)*num[j];
                        }
                    }
                    for (int j=M-1,k=M/2-2; k>=0; j--) {
                        if(j!=i-1 && j!=i){
                            y+=pow(k--)*num[j];
                        }
                    }
                }else{
                    x=INF;
                }
                res=min(res,abs(x-y));
            }
            printf("%d\n",res);
        }
        if (M%2!=0) {
            int x=0,y=0;
            if (num[0]!=0) {
                x+=pow(M/2)*num[0];
                for (int i=0,k=M/2-1; k>=0; i++) {
                    if(i!=0){
                        x+=pow(k--)*num[i];
                    }
                }
                for (int i=M-1,k=M/2-1; k>=0; i--) {
                    if(i!=0){
                        y+=pow(k--)*num[i];
                    }
                }
                printf("%d\n",abs(x-y));
            }else{
                x+=pow(M/2)*num[1];
                for (int i=0,k=M/2-1; k>=0; i++) {
                    if(i!=1){
                        x+=pow(k--)*num[i];
                    }
                }
                for (int i=M-1,k=M/2-1; k>=0; i--) {
                    if(i!=1){
                        y+=pow(k--)*num[i];
                    }
                }
                printf("%d\n",abs(x-y));
            }
        }
    }
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
