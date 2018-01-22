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
#define MAX_N 32005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

struct person {
    int dir;
    double loc;
};

int N;
double L,V;
person Per[MAX_N];
char dic[MAX_N][255];

void solve(double time){
    int sum=0;
    for (int i=0; i<N; i++) {
        Per[i].loc+=Per[i].dir*time*V;
        if(Per[i].loc<0){
            sum++;
        }
    }
    printf("%13.2lf %s\n",floor(time*100)/100,dic[sum]);
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    char use[2];double res=-1;
    while (scanf("%d",&N)!=EOF && N!=0) {
        scanf("%lf %lf",&L,&V);
        for (int i=0; i<N; i++) {
            scanf("%s %lf %s",use,&Per[i].loc,dic[i]);
            if (use[0]=='p'||use[0]=='P') {
                Per[i].dir=1;
            }
            if (use[0]=='n'||use[0]=='N') {
                Per[i].dir=-1;
            }
            double temp;
            if (Per[i].dir==1) {
                temp=L-Per[i].loc;
            }else{
                temp=Per[i].loc;
            }
            temp/=V;
            temp>res?res=temp:res;
        }
        solve(res);
    }
    
    return 0;
}
