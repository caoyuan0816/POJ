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
const int INF=0x7fffffff;
const int G_INF=0x7fffffff/2;
const long long L_INF=9223372036854775807;

struct edge {
    int L,R,X;
};

typedef long long ll;
int N,Q;
char T[MAX_N];
edge line[MAX_N];

ll bit1[MAX_N+1],bit2[MAX_N+1];

ll sum(ll *b,int i){
    ll s=0;
    while (i>0) {
        s+=b[i];
        i-=i&-i;
    }
    return s;
}

void add(ll *b,int i,int x){
    while (i<=N) {
        b[i]+=x;
        i+=i&-i;
    }
}

void solve(){
    for (int i=0; i<Q; i++) {
        if (T[i]=='C') {
            add(bit1, line[i].L, -1*line[i].X*(line[i].L-1));
            add(bit1, line[i].R+1, line[i].X*line[i].R);
            add(bit2, line[i].L, line[i].X);
            add(bit2, line[i].R+1, -1*line[i].X);
        }else if (T[i]=='Q'){
            ll res=0;
            res+=sum(bit1, line[i].R)+sum(bit2, line[i].R)*line[i].R;
            res-=sum(bit1, line[i].L-1)+sum(bit2, line[i].L-1)*(line[i].L-1);
            printf("%lld\n",res);
        }
    }
}

int main(void){
    
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
    
    scanf("%d %d",&N,&Q);
    int temp;
    for (int i=1; i<=N; i++) {
        scanf("%d",&temp);
        add(bit1, i, temp);
    }
    for (int i=0; i<Q; i++) {
        getchar();
        T[i]=getchar();
        if (T[i]=='Q') {
            scanf("%d %d",&line[i].L,&line[i].R);
        }else if (T[i]=='C'){
            scanf("%d %d %d",&line[i].L,&line[i].R,&line[i].X);
        }
    }
    solve();
    
    return 0;
}
