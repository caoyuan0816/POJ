#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_N = 50005;
const int MAX_M = 105;
const int INF = 2147483647;

int N;
int num[MAX_N];
int first[MAX_N];
int second[MAX_N];

void solve(){

	int ans = -INF;
	int cur = 0;
	for (int i = 1; i <= N; ++i){
		cur += num[i];
		cur < 0 ? cur = 0:cur;
		first[i] = max(first[i-1], cur);
	}

	cur = 0;
	for (int i = N; i >= 0; --i){
		cur += num[i];
		cur < 0 ? cur = 0:cur;
		second[i] = max(second[i+1], cur);
		ans = max(ans, second[i]+first[i-1]);
	}

	printf("%d\n",ans);
	
}

int main(void){

	int T;
	scanf("%d",&T);
	num[0] = first[0] = 0;
	for (int i = 0; i < T; ++i){
		scanf("%d",&N);
		second[N+1] = 0;
		for (int j = 1; j <= N; ++j){
			scanf("%d",&num[j]);
		}
		solve();
	}

   return 0;
}