//code by Yuan
//caoyuan0816@gmail.com

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_T = 1001;
const int MAX_W = 35;

int T,W,N;
int sum[2][MAX_W];
int v[MAX_T];
bool is_one_first = false;

void solve(){

	memset(sum, -1, sizeof(sum));
	int ans = 0;

	if(is_one_first){
		sum[0][W] = v[0];
		sum[1][W-1] = v[1];
	}else{
		sum[0][W-1] = v[0];
		sum[1][W] = v[1];
	}

    for (int i = 1; i < N; ++i){
    	for (int j = 0; j < W; ++j){
    		if(sum[(i+1)&1][j+1] != -1){
    			sum[i&1][j] = sum[(i+1)&1][j+1]+v[i];
    			ans = max(ans,sum[i&1][j]);
    		}
    	}
    	if((i&1) == 0){
    		sum[0][W] += v[i];
    		ans = max(ans,sum[i&1][W]);
    	}
    }

    printf("%d\n",ans);
}

int main(void){

	while(scanf("%d %d",&T,&W)!=EOF){
		memset(v, 0, sizeof(v));
		int rec,cur,j=0;

		scanf("%d",&rec);
		rec == 1? is_one_first = true: is_one_first = false;
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
	}

    return 0;
}