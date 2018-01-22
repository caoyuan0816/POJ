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
char str[2005];

void solve(){
    int a=0,b=N-1;
    bool left=false;
    int k=0;
    
    while (a<=b) {
        for (int i=0; a+i<=b; i++) {
            if(str[a+i]<str[b-i]){
                left=true;
                break;
            }else if(str[a+i]>str[b-i]){
                left=false;
                break;
            }
        }
        if(left){
            putchar(str[a++]);
        }else{
            putchar(str[b--]);
        }k++;
        if(k%80==0){putchar('\n');}
    }
    if(k%80!=0)putchar('\n');
}

int main()
{
    //freopen("/Users/mac/Documents/1", "r+", stdin);
   
    scanf("%d",&N);getchar();
    
    for (int i=0; i<N; i++) {
        scanf("%c",&str[i]);getchar();
    }
    
    solve();
    
    return 0;
}
