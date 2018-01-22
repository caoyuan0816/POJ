//
//  main.cpp
//  test
//
//  Created by Yuan on 14-1-29.
//  Copyright (c) 2014年 Yuan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>

#define MAX 0x7fffffff
#define MIN (~MAX)
#define MAX_N 10000

#define rep(n)  for(int repp = 0; repp < (n); ++repp)

using namespace std;
const int INF=0x7fffffff;

int a,b,c,d,e,f;
int ans;

void solve(){
    ans=0;
    while (f!=0) {
        f--;ans++;
    }
    while (e!=0) {
        e--;
        if (a>=11) {
            a-=11;
        }else{
            a=0;
        }
        ans++;
    }
    while (d!=0) {
        d--;
        if (b>=5) {
            b-=5;
        }else{
            int use=20-b*4;
            b=0;
            if (a>=use) {
                a-=use;
            }else{
                a=0;
            }
        }
        ans++;
    }
    while (c!=0) {
        if (c>=4) {
            c-=4;
        }else if(c==1){
            if (b>=5) {
                b-=5;
                if (a>=7) {
                    a-=7;
                }else{
                    a=0;
                }
            }else{
                int use=27-b*4;
                b=0;
                if (a>=use) {
                    a-=use;
                }else{
                    a=0;
                }
            }
            c=0;
        }else if(c==2){
            if (b>=3) {
                b-=3;
                if (a>=6) {
                    a-=6;
                }else{
                    a=0;
                }
            }else{
                int use=18-4*b;
                b=0;
                if (a>=use) {
                    a-=use;
                }else{
                    a=0;
                }
            }
            c=0;
        }else if(c==3){
            if (b>=1) {
                b-=1;
                if (a>=5) {
                    a-=5;
                }else{
                    a=0;
                }
            }else{
                if (a>=9) {
                    a-=9;
                }else{
                    a=0;
                }
            }
            c=0;
        }
        ans++;
    }
    while (b!=0) {
        if (b>=9) {
            b-=9;
        }else{
            int use=36-4*b;
            b=0;
            if (a>=use) {
                a-=use;
            }else{
                a=0;
            }
        }
        ans++;
    }
    while (a!=0) {
        if (a>=36) {
            a-=36;
        }else{
            a=0;
        }
        ans++;
    }
    printf("%d\n",ans);
}

int main(void)
{
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);

    while (scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f)==6 && !(a==0&&b==0&&c==0&&d==0&&e==0&&f==0)) {
        solve();
    }
    
    return 0;
}
