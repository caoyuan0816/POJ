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
typedef pair<int, int> P;
map<int, P> mymap;

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
    mymap.clear();
    
    scanf("%d %d %d",&N,&M,&R);
    int s,e,v;
    for (int i = 0 ; i < M; i++) {
        scanf("%d %d %d",&s,&e,&v);
        mymap[e] = P(s,v);
    }
    
    for (int i = 0; i <= N; i++) {
        if (mymap.count(i) != 0) {
            dp[i] = max(dp[i-1], dp[mymap[i].first-R >= 0? mymap[i].first-R : 0]+mymap[i].second);
        }else{
            dp[i] = dp[i-1];
        }
    }
    
    printf("%d\n",dp[N]);
    
    return 0;
}