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

const int MAX_N = 2005;
const double eps = 1e-8;

int N,M;
char str[MAX_N];
int cost[27];
int dp[MAX_N][MAX_N];

int fun(int i, int j){
    
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    if (i >= j) {
        dp[i][j] = 0;
        return 0;
    }
    
    if (str[i] == str[j]) {
        dp[i][j] = fun(i+1, j-1);
        
    }else{
        dp[i][j] = min(fun(i+1, j)+cost[str[i]-'a'] , fun(i, j-1)+cost[str[j]-'a']);
    }
    
    return dp[i][j];
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
    
    memset(dp, -1, sizeof(dp));
    
    scanf("%d %d",&N,&M);
    scanf("%s",str);
    char ch;
    int a,b;
    for (int i = 0; i < N; i++) {
        getchar();
        ch = getchar();
        scanf("%d %d",&a,&b);
        cost[ch-'a'] = min(a,b);
    }
   
    printf("%d\n",fun(0,M-1));
    
    return 0;
}