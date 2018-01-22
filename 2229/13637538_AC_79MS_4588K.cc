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

typedef long long LL;

const int MAX_N = 1000005;
const double eps = 1e-8;
const int MOD = 1000000000;

int N;
int dp[MAX_N];

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
    
    scanf("%d",&N);
    memset(dp, 0, sizeof(dp));
    
    dp[1] = 1;
    
    for (int i = 2; i <= N; i++) {
        if (i % 2 != 0) {
            dp[i] = dp[i-1] % MOD;
        }else{
            dp[i] = (dp[i-1] + dp[i/2]) % MOD;
        }
    }
    
    printf("%d\n",dp[N]);
    
    return 0;
}