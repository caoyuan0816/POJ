//code by Yuan
//caoyuan0816@gmail.com

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 1000005;
const int MAX_M = 1005;

int N,M,R;
struct Point{
	bool is_end;
	int start;
	int v;
	Point(){
		is_end = false;
		start = v = 0;
	}
};
Point s[MAX_N];

void solve(){

	for (int i = 1; i <= N; ++i){
		if(s[i].is_end){
			int begin = s[i].start;
			(begin-R)<0?begin=0:begin = begin - R;			
			s[i].v = max(s[i-1].v,s[begin].v+s[i].v);
		}else{
			s[i].v = s[i-1].v;
		}
	}
	
    printf("%d\n",s[N].v);
}

int main(void){

	while(scanf("%d %d %d",&N,&M,&R)!=EOF){
		int begin,end,value;
		for (int i = 0; i < M; ++i){
			scanf("%d %d %d",&begin,&end,&value);
			s[end].start = begin;
			s[end].is_end = true;
			s[end].v = value;
		}
		solve();
	}

    return 0;
}