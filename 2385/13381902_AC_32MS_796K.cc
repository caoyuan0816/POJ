//code by Yuan
//caoyuan0816@gmail.com

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_T = 1001;
const int MAX_W = 35;

int T,W,N;
int sum[MAX_T][MAX_W];
int v[MAX_T];
bool is_one_first = false;

void solve(){

	memset(sum, 0, sizeof(sum));
	int ans = v[0], k;

	if(is_one_first){
		for (int j = 0; j <= W; j+=2){
			sum[0][j] = v[0];
		}
		k = 0;
	}else{
		for (int j = 1; j <= W; j+=2){
			sum[0][j] = v[0];
		}
		k = 1;
	}

	for (int i = 1; i < N; ++i){
    	if(((i+k)%2) == 0){
    		sum[i][0] = sum[(i-1)][0]+v[i];
    	}else{
    		sum[i][0] = sum[(i-1)][0];
    	}
    	ans = max(ans,sum[i][0]);

    	for(int j = 1; j <= W; ++j){
    		if((j%2) == ((i+k)%2)){
    			sum[i][j] = max(sum[(i-1)][j], sum[(i-1)][j-1])+v[i];
    		}else{
    			sum[i][j] = max(sum[(i-1)][j], sum[(i-1)][j-1]);
    		}
    		ans = max(ans,sum[i][j]);
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