//code by Yuan
//caoyuan0816@gmail.com

#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_N = 355;

int N;
int tri[MAX_N][MAX_N];
int ans[MAX_N][MAX_N];
int res = -1;

void solve(){
    
    res = ans[0][0] = tri[0][0];
	for (int i = 0; i < N-1; ++i){
		for (int j = 0; j <= i; ++j){
			ans[i+1][j] = max(ans[i+1][j], ans[i][j]+tri[i+1][j]);
			ans[i+1][j+1] = max(ans[i+1][j+1], ans[i][j]+tri[i+1][j+1]);
			res = max(res, max(ans[i+1][j], ans[i+1][j+1]));
		}
	}

	cout<<res<<endl;
}
int main(void){
    
	cin>>N;
	for (int i = 0; i < N; ++i){
		for (int j = 0; j <= i; ++j){
			cin>>tri[i][j];
		}
	}

    solve();
    
    return 0;
}