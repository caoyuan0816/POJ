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
#define MAX_N 10005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

typedef long long ll;
string str;

ll gcd(ll a, ll b){
    if (b==0) {
        return a;
    }else{
        return gcd(b, a%b);
    }
}

void solve(){
    int l=2,r=(int)str.length()-4;
    ll ans_up=L_INF,ans_down=L_INF;
    
    for (int i=l-1; i<=r; i++) {
        ll up1=0,down1=0,up2=0,down2=0;
        int k1=0,k2=0;
        
        if (str[i]!='.') {
            for (int j=i; j>=l; j--) {
                up1+=(str[j]-'0')*pow(10,k1);
                k1++;
            }
        }
        down1=pow(10, k1);
        
        for (int j=r; j>i; j--) {
            up2+=(str[j]-'0')*pow(10, k2);
            down2+=9*pow(10, k2);
            k2++;
        }
        down2*=pow(10, k1);
        
        if (down1==0 || down2==0) {
            continue;
        }
        
        ll up=up1*down2+up2*down1;
        ll down=down1*down2;
        
        ll use=gcd(up, down);
        
        up/=use;
        down/=use;

        if (ans_down>down) {
            ans_up=up;ans_down=down;
        }
    }
    printf("%lld/%lld\n",ans_up,ans_down);
}

int main(void)
{
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    while (cin>>str) {
        if (str == "0") {
            return 0;
        }
        solve();
    }
    
    return 0;
}
