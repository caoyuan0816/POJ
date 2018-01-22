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

const int MAX_N = 355;
const double eps = 1e-8;

int matrix[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int N;
int ans = 0;

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
    cin >> N;
    for (int i = 1 ; i <= N; i ++) {
        for (int j = 1; j <= i; j++) {
            cin >> matrix[i][j];
        }
    }
   
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + matrix[i][j];
        }
    }
    
    for (int i = 1; i <= N; i++) {
        ans = max(ans, dp[N][i]);
    }
    
    cout << ans << endl;
    
    return 0;
}