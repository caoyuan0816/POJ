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

#define rep(n)  for(int repp = 0; repp < (n); ++repp)

using namespace std;
const int INF=100000000;

int N;
int L[20005];

void solve(){
    long long ans=0;
    
    while(N>1){
        int left=0,right=1;
        if (L[left]>L[right]) {
            swap(left, right);
        }
        
        for (int i=2; i<N; i++) {
            if(L[i]<L[left]){
                right=left;
                left=i;
            }else if(L[i]<L[right]){
                right=i;
            }
        }
        
        int tot = L[left]+L[right];
        ans+=tot;
        
        if(left==N-1){swap(left, right);}
        
        L[left]=tot;
        L[right]=L[N-1];
        N--;
    }
    printf("%lld\n",ans);
}

int main()
{
    //freopen("/Users/mac/Documents/1", "r+", stdin);
    
    scanf("%d",&N);
    
    for (int i=0; i<N; i++) {
        scanf("%d",&L[i]);
    }
    
    solve();
    
    return 0;
}
