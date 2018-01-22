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
struct Point{
	bool is_end;
	vector<int> start;
	vector<int> value;
	int ans;
};
Point s[MAX_N];

void solve(){	

	for (int i = 1; i <= N; ++i){
		if(s[i].is_end){
			int use = 0;
			for (int j = 0; j < s[i].start.size(); ++j){
				int begin = s[i].start[j];
				(begin-R)<0 ? begin=0 : begin=begin-R;	

				use = max(use, s[begin].ans+s[i].value[j]);
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
			s[i].value.clear();
			s[i].start.clear();
			s[i].ans = 0;
		}

		int begin,end,value;
		for (int i = 0; i < M; ++i){
			scanf("%d %d %d",&begin,&end,&value);
			s[end].start.push_back(begin);
			s[end].is_end = true;
			s[end].value.push_back(value);
		}
		solve();
	}

    return 0;
}