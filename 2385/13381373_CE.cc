//code by Yuan
//caoyuan0816@gmail.com

#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_T = 1001;
const int MAX_W = 35;

int T,W,N;
int sum[MAX_T][MAX_W];
int v[MAX_T];

void solve(){

	int ans = 0;

    sum[0][W] = v[0];
    sum[1][W] = v[1];

    for (int i = 1; i < N; ++i){
    	for (int j = W; j >= 0; --j){
    		if(j >= W-i){
    			if(j == W && i >= 2){
    				sum[i][j] = sum[i-2][j]+v[i];
    			}else{
    				sum[i][j] = sum[i-1][j+1]+v[i];
    			}
    			ans = max(ans, sum[i][j]);
    		}else{
    			break;
    		}
    	}
    }

    printf("%d\n",ans);
}

int main(void){
	
	scanf("%d %d",&T,&W);

	memset(v, 0, sizeof(v));

	int rec,cur,j=0;
	scanf("%d",&rec);
	v[j]++;
	for (int i = 1; i < T; ++i){
		scanf("%d",&cur);
		if(cur == rec){
			v[j]++;
		}else{
			v[++j]++;
		}
		rec = cur;
	}
	N = j+1;

    solve();
    
    return 0;
}