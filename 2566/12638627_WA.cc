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
#define MAX_N 100005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

typedef pair<int, int> P;
int n,k,res,l,r;
P num[MAX_N];

void solve(int t){
    int s=0,e=1,minn=INF;
    
    while (s<=n && e<=n) {
        int use=abs(num[e].first-num[s].first);
        if (abs(use-t)< minn) {
            minn=abs(use-t);
            res=use;
            l=num[s].second;r=num[e].second;
        }
        if (use<t) {
            e++;
        }else if(use>t){
            s++;
        }else{
            break;
        }
        if (e==s) {
            e++;
        }
    }
    if (l>r) {
        swap(l, r);
    }l++;
    printf("%d %d %d\n",res,l,r);
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    while (scanf("%d %d",&n,&k)!=EOF && !(n==0 && k==0)) {
        num[0]=P(0,0);
        for (int i=1; i<=n; i++) {
            scanf("%d",&num[i].first);
            num[i].first+=num[i-1].first;
            num[i].second=i;
        }
        sort(num+1, num+1+n);
        for (int i=0; i<k; i++) {
            int t;
            scanf("%d",&t);
            solve(t);
        }
    }

    return 0;
}