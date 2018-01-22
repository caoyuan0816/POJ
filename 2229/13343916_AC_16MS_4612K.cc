//code by Yuan
//caoyuan0816@gmail.com

#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_N = 1000000;

int N;
int ans[MAX_N];
const int M = 1000000000;

void solve(){
    
    int i=1;
    ans[0] = 1;
    while (i<=N){
    	ans[i++] = ans[i-1];
    	ans[i++] = (ans[i-2]+ans[i>>1])%M;
    }

    printf("%d\n",ans[N]);
}

int main(void){
    
	scanf("%d",&N);

    solve();
    
    return 0;
}