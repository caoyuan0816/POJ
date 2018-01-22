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
#define MAX_N 1000000

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

struct edge {
    int sum;
    int x,y;
};
int N,S[1000];
edge A[MAX_N],B[MAX_N];
int tot_A,tot_B;
int ans;

bool mycmp(const edge &a,const edge &b){
    return a.sum<b.sum;
}

void solve(){
    tot_A=0;tot_B=0;ans=-1*INF;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (i!=j) {
                A[tot_A].sum=S[i]+S[j];
                A[tot_A].x=i;A[tot_A++].y=j;
            }
        }
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (i!=j) {
                B[tot_B].sum=S[j]-S[i];
                B[tot_B].x=i;B[tot_B++].y=j;
            }
        }
    }
    
    sort(A, A+tot_A,mycmp);
    for (int i=0; i<tot_B; i++) {
        edge *use=lower_bound(A, A+tot_A, B[i],mycmp);
        if ((use->sum)==B[i].sum && B[i].x!=use->x && B[i].y!=use->y && B[i].x!=use->y && B[i].y!=use->x) {
            ans=max(ans,S[B[i].y]);
        }
    }
    if (ans==-1*INF) {
        printf("no solution\n");
    }else{
        printf("%d\n",ans);
    }
}

int main(void){
    
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    while (scanf("%d",&N)!=EOF && N!=0) {
        for (int i=0; i<N; i++) {
            scanf("%d",&S[i]);
        }
        solve();
    }
    
    return 0;
}