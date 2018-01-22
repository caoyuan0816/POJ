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
#include <set>
#include <map>

#define MAX 0x7fffffff
#define MIN (~MAX)
#define MAX_N 1000005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

int P;
int A[MAX_N];

void solve(){
    set<int> data;
    for (int i=0; i<P; i++) {
        data.insert(A[i]);
    }
    int N=data.size();
    
    int s=0,t=0,sum=0,res=P;
    map<int, int> Count;
    while (true) {
        while (t<P && sum<N) {
            if (Count[A[t++]]++ == 0) {
                sum++;
            }
        }
        if (sum<N) {
            break;
        }
        res=min(res, t-s);
        if (--Count[A[s++]] == 0) {
            sum--;
        }
    }
    
    printf("%d\n",res);
}

int main(void){
    
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    while (scanf("%d",&P)!=EOF) {
        for (int i=0; i<P; i++) {
            scanf("%d",&A[i]);
        }
        solve();
    }

    return 0;
}
