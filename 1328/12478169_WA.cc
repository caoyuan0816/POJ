//
//  main.cpp
//  test1
//
//  Created by mac on 14-1-19.
//  Copyright (c) 2014年 Yuan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
#include <stack>
#include <math.h>

#define MAX 0x7fffffff
#define MIN (~MAX)
#define MAX_N 1005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)

using namespace std;
const int INF=0x7fffffff;
const int eps=1e-8;

int n;
double d;
typedef pair<double , double> P;
P points[MAX_N];
bool vis[MAX_N];

bool comp(const P &a,const P &b){
    return a.second>b.second;
}

void del(int m){
    vis[m]=true;
    double o=points[m].first-(sqrt(d*d-points[m].second*points[m].second));
    
    for (int i=0; i<n; i++) {
        if (!vis[i] && sqrt((points[i].first-o)*(points[i].first-o)+points[i].second*points[i].second)-d<=eps ) {
            vis[i]=true;
        }
    }
}

int solve(){
    sort(points, points+n, comp);
    int ans=0;
    
    for (int i=0; i<n; i++) {
        if(!vis[i]){
            del(i);
            //cout<<points[i].first<<"  "<<points[i].second<<endl;
            ans++;
        }
    }
    return ans;
}

int main()
{
    //freopen("/Users/mac/Documents/1", "r+", stdin);
    
    int cas=0;
    while (scanf("%d %lf",&n,&d)==2 && !(n==0 && d==0)) {
        cas++;
        bool flag=true;
        for (int i=0; i<n; i++) {
            vis[i]=false;
            scanf("%lf %lf",&points[i].first,&points[i].second);
            if (points[i].second<=eps || points[i].second-d>eps) {
                flag=false;
            }
        }
        if (d<=eps || !flag) {
            printf("Case %d: -1\n",cas);
            continue;
        }else{
            printf("Case %d: %d\n",cas,solve());
        }
    }
    
    return 0;
}
