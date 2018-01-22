//code by Yuan
//caoyuan0816@gmail.com

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_N = 1000005;
const int MAX_M = 1005;

int N,M,R;
typedef pair<int, int> P;
struct Point{
	bool is_end;
	P *start;
	int ans;
	int n;
};
Point s[MAX_N];

void solve(){	

	for (int i = 1; i <= N; ++i){
		if(s[i].is_end){
			int use = 0;
			for (int j = 0; j < s[i].n; ++j){
				int begin = s[i].start[j].first;
				(begin-R)<0 ? begin=0 : begin=begin-R;	

				use = max(use, s[begin].ans+s[i].start[j].second);
			}
			s[i].ans = max(s[i-1].ans,use);
		}else{
			s[i].ans = s[i-1].ans;
		}
	}

    printf("%d\n",s[N].ans);
}

int main(void){

	while(scanf("%d %d %d",&N,&M,&R)!=EOF){
		for (int i = 0; i <= N; ++i){
			s[i].is_end = false;
			s[i].n = s[i].ans = 0;
			delete[] s[i].start;
			s[i].start = NULL;
		}

		int begin,end,value;
		for (int i = 0; i < M; ++i){
			scanf("%d %d %d",&begin,&end,&value);
			if(s[end].start == NULL){
				s[end].start = new P[100];
			}
			s[end].start[(s[end].n)++] = P(begin,value);
			s[end].is_end = true;
		}
		solve();
	}

    return 0;
}