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
#define MAX_N 1005

#define rep(n)  for(int repp = 0; repp < (n); ++repp)
using namespace std;
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;
const int eps=10e-8;

struct edge {
    int a,b,c,d;
};
int N,T;
int bit[MAX_N][MAX_N];
char Q[50005];
edge L[50005];

void add(int x,int y,int v){
    if (x>N || y>N) {
        return;
    }
    for (int i=x; i<=N; i+=i&-i) {
        for (int j=y; j<=N; j+=j&-j) {
            bit[i][j]+=v;
        }
    }
}

int sum(int x,int y){
    int s=0;
    for (int i=x; i>0; i-=i&-i) {
        for (int j=y; j>0; j-=j&-j) {
            s+=bit[i][j];
        }
    }
    return s;
}

void solve(){
    memset(bit, 0, sizeof(bit));
    for (int i=0; i<T; i++) {
        if (Q[i]=='C') {
            int a=L[i].a,b=L[i].b,c=L[i].c,d=L[i].d;
            if (a>c) {
                swap(a, c);
            }
            if (b>d) {
                swap(b, d);
            }
            
            add(a, b, 1);
            add(c+1, b, 1);
            add(a, d+1, 1);
            add(c+1, d+1, 1);
            
        }else if (Q[i]=='Q'){
            int a=L[i].a,b=L[i].b;
            
            printf("%d\n",sum(a, b)%2);
        }
    }
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    int Case;
    scanf("%d",&Case);
    for (int i=0; i<Case; i++) {
        if (i!=0) {
            puts("");
        }
        scanf("%d %d",&N,&T);
        for (int i=0; i<T; i++) {
            getchar();
            Q[i]=getchar();
            if (Q[i]=='C') {
                scanf("%d %d %d %d",&L[i].a,&L[i].b,&L[i].c,&L[i].d);
            }else if (Q[i]=='Q'){
                scanf("%d %d",&L[i].a,&L[i].b);
            }
        }
        solve();
    }
    
    return 0;
}