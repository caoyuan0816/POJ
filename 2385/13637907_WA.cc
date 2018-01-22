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
    
    memset(arr, 0, sizeof(arr));
    memset(dp, 0, sizeof(dp));
    
    scanf("%d %d",&T,&W);
    int k = 0, use, cur;
    int start_with = 1;
    
    scanf("%d",&use);
    if (use == 1) {
        start_with = 0;
    }
    
    int count = 1;
    for (int i = 0; i < T-1 ; i++) {
        scanf("%d",&cur);
        if (cur != use) {
            arr[k++] = count;
            use = cur;
            count = 1;
        }else{
            count ++;
        }
    }
    arr[k++] = count;

    for (int i = 0; i < k; i++) {
        if (i % 2 == start_with) {
            if (i == 0 || i == 1) {
                dp[i][0] = arr[i];
            }else{
               dp[i][0] = dp[i-2][0] + arr[i];
            }
        }
    }
    
    for (int j = 0; j <= W; j++) {
        if (j % 2 == start_with) {
            dp[0][j] = arr[0];
        }
    }
    
    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= W; j++) {
            dp[i][j] = max(dp[i-1][j]+((i+j) % 2 == 0? arr[i]:0), dp[i-1][j-1]+((i+j+1) % 2 == 0? arr[i]:0));
        }
    }
    
//    for (int i = 0; i < k; i++) {
//        for (int j = 0; j <= W; j++) {
//            cout<<dp[i][j]<<" ";
//        }
//        cout <<endl;
//    }
   
    int ans = 0;
    for (int i = 0; i <= W; i++) {
        ans = max(ans, dp[k-1][i]);
    }
    
    printf("%d\n",ans);
    
    return 0;
}