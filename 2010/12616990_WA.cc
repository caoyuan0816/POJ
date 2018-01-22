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
const int INF=4294967295;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

typedef long long ll;
typedef pair<int, int> P;
int N,C;
int la,ra;
ll F,use;
P cow[MAX_N];

bool mycmp(const P &a,const P &b){
    return a.second<b.second;
}

bool mycmp1(const P &a,const P &b){
    return a.first>b.first;
}

bool Check(ll x){
    if (x<la || x>ra){
        return false;
    }
    
    int less=0,bigger=0;
    ll sum=0;
    for (int i=0; i<C; i++) {
        if (cow[i].first < x && less<N/2) {
            less++;
            sum+=cow[i].second;
        }
        if (cow[i].first >= x && bigger<N/2+1) {
            bigger++;
            sum+=cow[i].second;
        }
        if (less== N/2 && bigger== N/2+1) {
            break;
        }
    }
    return (less==N/2 && bigger== N/2+1 && sum<=F);
}
void solve(){
 
    sort(cow, cow+C,mycmp);

    if (N==C){
        if(use <=F){
            printf("%d\n",cow[N/2].first);
            return;
        }else{
            printf("-1\n");
            return ;
        }
    }
    
    ll l=0,r=2000000000,mid;
    while (r-l>1) {
        mid=(l+r)/2;
        //cout<<l<<" "<<mid<<" "<<r<<endl;
        if (Check(mid)) {
            l=mid;
        }else{
            r=mid;
        }
    }
    
    if (l==0) {
        printf("-1\n");
    }else{
        printf("%lld\n",l);
    }
}

int main(void){
    
   // freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d %d %lld",&N,&C,&F);
    
    la=INF,ra=0;
    for (int i=0; i<C; i++) {
        scanf("%d %d",&cow[i].first,&cow[i].second);
        la=min(la, cow[i].first);
        ra=max(ra, cow[i].first);
        use+=cow[i].second;
    }
    
    solve();
    
    return 0;
}
