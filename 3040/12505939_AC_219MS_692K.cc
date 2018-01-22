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
#define MAX_N 25

#define rep(n)  for(int repp = 0; repp < (n); ++repp)

using namespace std;
const int INF=0x7fffffff;

typedef pair<int , int> P;

int N,C;
P coin[MAX_N];
int ans;
bool flag=false;

void solve(){
    sort(coin,coin+N);
    ans=0;
    
    for (int i=0; i<N; i++) {
        if (coin[i].first>=C) {
            ans+=coin[i].second;
            coin[i].second=0;
        }
    }
    
    while (!flag) {
        int use=C;
        for (int i=N-1; i>=0; i--) {
            while (coin[i].second>0 && use>=coin[i].first) {
                use-=coin[i].first;
                coin[i].second--;
            }
        }
        if (use==0) {
            ans++;
        }else{
            for (int i=0; i<N && use>0; i++) {
                while (coin[i].second>0 && use>0) {
                    use-=coin[i].first;
                    coin[i].second--;
                }
            }
            if (use<=0) {
                ans++;
            }
        }
        flag=true;
        for (int i=0; i<N; i++) {
            if (coin[i].second!=0) {
                flag=false;
                break;
            }
        }
    }
    
    printf("%d\n",ans);
    
}

int main(void)
{
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);

    scanf("%d %d",&N,&C);
    for (int i=0; i<N; i++) {
        scanf("%d %d",&coin[i].first,&coin[i].second);
    }
    solve();
    
    return 0;
}
