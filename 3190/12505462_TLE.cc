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
#define MAX_N 50000

#define rep(n)  for(int repp = 0; repp < (n); ++repp)

using namespace std;
const int INF=0x7fffffff;

typedef pair<int, int> P;

int N;
P cow[MAX_N];
P stall[MAX_N];
int ans[MAX_N];

void solve(){
    int k=1;
    for (int i=0; i<N; i++) {
        for (int j=0; j<k; j++) {
            if (cow[i].first>stall[j].second) {
                //cout<<cow[i].first<<" f f "<<stall[j].second<<endl;
                ans[i]=j+1;
                stall[j].second=cow[i].second;
                break;
            }
            if (j==k-1) {
                k++;
            }
        }
    }
    printf("%d\n",k);
    for (int i=0; i<N; i++) {
        printf("%d\n",ans[i]);
    }

}

int main(void)
{
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);

    scanf("%d",&N);
    
    for (int i=0; i<N; i++) {
        scanf("%d %d",&cow[i].first,&cow[i].second);
        stall[i].first=0;stall[i].second=0;
    }
    
    solve();
    
    return 0;
}
