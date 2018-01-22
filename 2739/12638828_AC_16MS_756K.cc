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
#define MAX_N 10005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

int N;

int prime[10000],tot_p;
bool is_prime[10000];

void make_prime(){
    fill(is_prime, is_prime+10000, true);
    tot_p=0;
    is_prime[0]=is_prime[1]=false;
    for (int i=2; i<10000; i++) {
        if (is_prime[i]) {
            prime[tot_p++]=i;
            for (int j=2*i; j<10000; j+=i) {
                is_prime[j]=false;
            }
        }
    }
}

void solve(){
    int s=0,t=0,sum=0,res=0;
    bool flag=true;
    while (flag) {
        while (sum<N) {
            sum+=prime[t++];
            if (prime[t-1]>N) {
                flag=false;
                break;
            }
        }
        if (sum==N) {
            res++;
        }
        if (sum>=N) {
            sum-=prime[s++];
        }
    }
    printf("%d\n",res);
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    make_prime();
    
    while (scanf("%d",&N)!=EOF && N!=0) {
        solve();
    }

    return 0;
}