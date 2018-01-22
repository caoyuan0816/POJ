#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_N = 105;
const int MAX_M = 105;
const int INF = 2147483647;

int N;
int matrix[MAX_N][MAX_N];
int arr[MAX_N];
int ans;

void cal(int m){

	int count = 0;
	for (int i = 0; i < N; ++i){
		if (arr[i]>0){
			count++;
		}
	}
	if(count < 2){
		int temp[MAX_N];
		for (int i = 0; i < N; ++i)	{
			temp[i] = matrix[m][i];
		}
		sort(temp, temp+N);
		ans = max(ans, temp[N-2]+temp[N-1]);
		return;
	}

	int cur = 0;
	for (int i = 0; i < N; ++i){
		cur += arr[i];
		cur < 0? cur = 0:cur;
		ans = max(ans, cur);
	}
}

void solve(){
	
	ans = -INF;

	for (int k = 0; k < N; ++k){
		memset(arr, 0, sizeof(arr));
		for (int i = k; i < N; ++i){
			for (int j = 0; j < N; ++j){
				arr[j] += matrix[i][j];
			}
			cal(i);
		}
	}

	printf("%d\n",ans);
}

int main(void){

	while(scanf("%d",&N) != EOF){

		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				scanf("%d",&matrix[i][j]);
			}
		}
		solve();
	}

   return 0;
}