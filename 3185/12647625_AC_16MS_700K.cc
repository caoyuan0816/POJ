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
#define MAX_N 25

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

int bowl[MAX_N];
int bowl2[MAX_N];

void solve(){
    int res1=0,res2=0;
    memcpy(bowl2, bowl, sizeof(bowl));

    for (int i=1; i<20; i++) {
        if (bowl[i-1]%2==1) {
            bowl[i-1]++;
            bowl[i]++;
            if (i+1<20) {
                bowl[i+1]++;
            }
            res1++;
        }
    }

    bowl2[0]++;bowl2[1]++;res2++;
    for (int i=1; i<20; i++) {
        if (bowl2[i-1]%2==1) {
            bowl2[i-1]++;
            bowl2[i]++;
            if (i+1<20) {
                bowl2[i+1]++;
            }
            res2++;
        }
    }

    printf("%d\n",min(res1, res2));
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    for (int i=0; i<20; i++) {
        scanf("%d",&bowl[i]);
        bowl2[i]=bowl[i];
    }
    
    solve();
    
    return 0;
}
