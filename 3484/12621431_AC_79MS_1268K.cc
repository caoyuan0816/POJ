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
#define MAX_N 100

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

/*
 
 1 2 3 4 5 6 7 8 9 10
   2 3 4 5 6 7 8 9 10
 
 1 2 3 4 5 6 7 8 9 10
 1 2 3 4 5 6 7 8 9 10
 
 1 2 3 4 5 6 7 8 9 10
       4
 1 2 3 4 5
           6 7 8 9 10
 
 */
typedef long long ll;
struct edge {
    int X,Y,Z;
    edge(int xx,int yy, int zz){
        X=xx;Y=yy;Z=zz;
    }
};
vector<edge> data;

ll Check(int n){
    ll sum=0;
    for (int i=0; i<data.size(); i++) {
        if (n>data[i].X) {
            sum+=(min(data[i].Y, n)-data[i].X)/data[i].Z+1;
        }else if(n== data[i].X){
            sum++;
        }
    }
    //cout<<"sum= "<<sum<<endl<<endl;
    return sum;
}

void solve(){
    ll l=0,r=INF,mid;
    while (r-l>1) {
        mid=(l+r)/2;
        //cout<<l<<" "<<mid<<" "<<r<<endl;
        if (Check((int)mid)%2==1) {
            r=mid;
        }else{
            l=mid;
        }
    }
    if (r==INF) {
        printf("no corruption\n");
    }else{
        printf("%lld %lld\n",r,Check((int)r)-Check((int)r-1));
    }
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    char use[MAX_N];
    while (gets(use)) {
        if (use[0]=='\0') {
            if (data.size()!=0) {
                solve();
                data.clear();
            }
        }else{
            int a,b,c;
            sscanf(use, "%d %d %d",&a,&b,&c);
            data.push_back(edge(a,b,c));
        }
    }
    solve();
    
    return 0;
}
