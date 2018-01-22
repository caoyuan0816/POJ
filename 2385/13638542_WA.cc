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

const int MAX_N = 1005;
const double eps = 1e-8;

int T,W;
int arr[MAX_N];
int dp[MAX_N][35];

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
    
    scanf("%d %d",&T,&W);
    int use, cur, k = 0;
    int s = 1;
    
    scanf("%d",&use);
    if (use == 1) {
        s = 0;
    }

    for (int j = 0; j <= W; j++) {
        if (j % 2 == s % 2) {
            dp[0][j] = 1;
        }else{
            dp[0][j] = 0;
        }
    }
    
    for (int i = 1; i < T; i++) {
        scanf("%d",&cur);
        if (cur == use) {
            for (int j = 0; j <= W; j++) {
                dp[i][j] = dp[i-1][j] + 1;
            }
        }else{
            k++;
            for (int j = 0; j <= W; j++) {
                if (j == 0) {
                    dp[i][j] = dp[i-1][j] + ((j % 2) == (k + s) % 2 ? 1:0);
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + ((j % 2) == (k + s) % 2 ? 1:0);
                }
            }
            use = cur;
        }
    }
//    for (int i = 0; i < T; i++) {
//        for (int j = 0; j <= W; j++) {
//            cout << dp[i][j] <<" ";
//        }cout <<endl;
//    }
    
    int ans = 0;
    for (int j = 0; j <= W; j++) {
        ans = max(ans, dp[T-1][j]);
    }
    
    printf("%d\n",ans);
    
    return 0;
}