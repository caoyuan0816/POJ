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

int N;
int X[MAX_N],Y[MAX_N];
int x_size,y_size;
int bit[MAX_N][MAX_N];

void compress(){
    vector<int> cx;
    vector<int> cy;
    
    for (int i=1; i<=N; i++) {
        cx.push_back(X[i]);
        cy.push_back(Y[i]);
    }
    
    sort(cx.begin(), cx.end());
    cx.erase(unique(cx.begin(),cx.end()),cx.end());
    sort(cy.begin(), cy.end());
    cy.erase(unique(cy.begin(),cy.end()),cy.end());
    
    for (int i=1; i<=N; i++) {
        X[i]=(int)(find(cx.begin(), cx.end(),X[i])-cx.begin())+1;
        Y[i]=(int)(find(cy.begin(), cy.end(),Y[i])-cy.begin())+1;
    }
    x_size=(int)cx.size();
    y_size=(int)cy.size();
}

void add(){
    
}

void solve(){
    compress();

    
    
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d",&N);
    for (int i=1; i<=N; i++) {
        scanf("%d %d",&X[i],&Y[i]);
    }
    
    solve();
    
    return 0;
}
