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

typedef pair<int , double> P;
int n,k;
double v[MAX_N],w[MAX_N];
P c[MAX_N];
int ans[MAX_N],tot_ans;

bool mycmp(const P &a,const P &b){
    return a.second>b.second;
}

bool Check(double x){
    for (int i=0; i<n; i++) {
        c[i].first=i+1;
        c[i].second=v[i]-x*w[i];
    }
    sort(c, c+n, mycmp);
    double sum=0;
    for (int i=0; i<k; i++) {
        sum+=c[i].second;
    }
    if (sum>=0) {
        tot_ans=0;
        for (int i=0; i<k; i++) {
            ans[tot_ans++]=c[i].first;
        }
        return true;
    }
    return false;
}

void solve(){
    double l=0,r=G_INF,mid;
    rep(100){
        mid=(l+r)/2;
        //cout<<l<<" "<<mid<<" "<<r<<endl;
        if (Check(mid)) {
            l=mid;
        }else{
            r=mid;
        }
    }
    for (int i=0; i<tot_ans; i++) {
        if (i==0) {
            printf("%d",ans[i]);
        }else{
            printf(" %d",ans[i]);
        }
    }puts("");
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d %d",&n,&k);
    for (int i=0; i<n; i++) {
        scanf("%lf %lf",&v[i],&w[i]);
    }
    
    solve();
    
    return 0;
}
