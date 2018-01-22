//code by Yuan
//caoyuan0816@gmail.com

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX_N = 27;
const int MAX_M = 2005;

int N,M;
char str[MAX_M];
int cost[MAX_N];
int ans[MAX_M][MAX_M];

void solve(){

	for (int i = M-1; i >= 0; --i){
		for (int j = i+1; j < M; ++j){
			if(str[i] == str[j]){
				ans[i][j] = ans[i+1][j-1];
			}else{
				ans[i][j] = min(ans[i+1][j]+cost[str[i]-'a'],ans[i][j-1]+cost[str[j]-'a']);
			}
		}
	}

	printf("%d\n",ans[0][M-1]);
}

int main(void){

	memset(ans, 0, sizeof(ans));
	scanf("%d %d",&N,&M);
	scanf("%s",str);

	char ch;
	int add,del;
	for (int i = 0; i < N; ++i){
		getchar();
		ch = getchar();
		scanf("%d %d",&add,&del);
		cost[ch-'a'] = min(add,del);
	}

	solve();

    return 0;
}