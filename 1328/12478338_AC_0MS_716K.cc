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

int solve(){
    sort(points, points+n);
    int ans=1;
    
    for (int i=0; i<n-1; i++) {
        if (points[i+1].first-points[i].second<=eps) {
            points[i+1].first=max(points[i].first,points[i+1].first);
            points[i+1].second=min(points[i].second,points[i+1].second);
        }else{
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
        
        if(d<=eps){flag=false;}
        
        for (int i=0; i<n; i++) {
            scanf("%lf %lf",&points[i].first,&points[i].second);
            
            if(points[i].second<eps){flag=false;}
            if(d*d-points[i].second*points[i].second>=eps && flag){
                double use=sqrt(d*d-points[i].second*points[i].second);
                double first=points[i].first;
                points[i].first=first-use;
                points[i].second=first+use;
            }else{
                flag=false;
            }
        }
        
        if (!flag) {
            printf("Case %d: -1\n",cas);
        }else{
            printf("Case %d: %d\n",cas,solve());
        }
        
    }
    
    return 0;
}
