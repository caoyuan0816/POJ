/*
 ID: Cao Yuan
 PROG: wormhole
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>

#define OUTFILE "wormhole.out"
#define INFILE "wormhole.in"
#define MAX_INT 0x7fffffff
#define MAX_LL 9223372036854775807L;

using namespace std;

const int MAX_N = 1000005;
const double eps = 1e-8;

int N,M,R;
int dp[MAX_N];
struct Node{
    int s,e;
    int v;
    Node(){}
};
Node arr[1005];

bool mycmp(const Node& a, const Node& b){
    return a.e < b.e;
}

int main() {
    
    //    /*Submit in USACO*/
    //    /*
    //    ofstream fout(OUTFILE);
    //    ofstream *out = &fout;
    //    ifstream fin (INFILE);
    //    ifstream *in = &fin;
    //    /*/
    //    ostream *out = &cout;
    //    istream *in = &cin;
    //    /**/
    
    memset(dp, 0, sizeof(dp));
    
    scanf("%d %d %d",&N,&M,&R);
    for (int i = 0 ; i < M; i++) {
        scanf("%d %d %d",&arr[i].s, &arr[i].e, &arr[i].v);
    }
    arr[M].e = N+1;
    
    sort(arr, arr+M+1, mycmp);
    for (int i = 0; i < M-1; i++) {
        if (arr[i].e == arr[i+1].e) {
            while (1) {
                
            }
        }
    }
    for (int i = 0, k = 0; i <= N; i++) {
        while (i == arr[k].e) {
            int u = arr[k].s-R;
            dp[i] = max(max(dp[i-1], dp[i]), (u >= 0 ? dp[u] : 0)+arr[k].v);
            k++;
        }
        dp[i] = max(dp[i], dp[i-1]);
    }
    
    printf("%d\n",dp[N]);
    
    return 0;
}