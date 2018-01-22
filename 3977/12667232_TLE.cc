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
#include <map>

#define MAX 0x7fffffff
#define MIN (~MAX)
#define MAX_N 262150

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

typedef long long ll;
int N;
ll A[35],B[35];
ll set_A[MAX_N];
int size_A;
int a,b;
map<ll,int> dic;

ll myabs(ll n){
    return n<0?-1*n:n;
}

void solve(){
    memset(set_A, 0, sizeof(set_A));
    size_A=0,dic.clear();
    for (int i=0; i<(1<<a); i++) {
        ll sum=0;int num=0;
        for (int j=0; j<a; j++) {
            if (1&(i>>j)) {
                sum+=A[j];
                num++;
            }
            if (sum==0 && num==0) {
                continue;
            }
            if (dic[sum]==0) {
                dic[sum]=num;
                set_A[size_A++]=sum;
            }else{
                dic[sum]<num?1:dic[sum]=num;
            }
        }
    }
    if (dic[0]!=0) {
        printf("0 %d\n",dic[0]);
        return ;
    }
    sort(set_A, set_A+size_A);

    ll ans_sum=L_INF;
    int ans_num=INF;
    for (int i=0; i<(1<<b); i++) {
        ll sum=0;int num=0;
        for (int j=0; j<b; j++) {
            if (1&(i>>j)) {
                sum+=B[j];
                num++;
            }
        }
        if (num!=0 && myabs(sum)<ans_sum) {
            ans_sum=myabs(sum);
            ans_num=num;
        }
        ll *k=lower_bound(set_A, set_A+size_A, -1*sum);
        if ((k-set_A)>=0 && (k-set_A)<size_A) {
            ll absv=myabs(*k+sum);
            if (absv<ans_sum) {
                ans_sum=absv;
                ans_num=dic[*k]+num;
            }
        }
        k++;
        if ((k-set_A)>=0 && (k-set_A)<size_A) {
            ll absv=myabs(*k+sum);
            if (absv<ans_sum) {
                ans_sum=absv;
                ans_num=dic[*k]+num;
            }
        }
    }
    printf("%lld %d\n",ans_sum,ans_num);
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    while (scanf("%d",&N)!=EOF && N!=0) {
        a=N/2+1;
        b=N-a;
        for (int i=0; i<a; i++) {
            scanf("%lld",&A[i]);
        }
        for (int i=0; i<b; i++) {
            scanf("%lld",&B[i]);
        }
        solve();
    }
    
    return 0;
}
