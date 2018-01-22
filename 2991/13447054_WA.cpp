#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_N = 10005;
const int MAX_Tree = (1<<15) -1;
const double PI = acos(-1.0);

int N,C;
int len[MAX_N];
struct Node{
	double x;
	double y;
	double angle;
};
Node tree[MAX_Tree];

//l,r 对应 [l,r) 区间
void init(int k ,int l, int r){

	tree[k].x = tree[k].angle = 0.0;
	if(r-l == 1){
		//是叶子节点
		tree[k].y = len[l];
	}else{
		//非叶子节点
		init(k*2+1, l, (l+r)/2);
		init(k*2+2, (l+r)/2, r);
		tree[k].y = tree[k*2+1].y+tree[k*2+2].y;
	}
}

void update(int s, double ang, int k, int l, int r){

	if(s == l){
		double a = tree[k].x;
		double b = tree[k].y;
		tree[k].x = a*cos(ang)+b*sin(ang);
		tree[k].y = b*cos(ang)-a*sin(ang);
		tree[k].angle += ang;
		return ;
	}
	if(s>l && s<r){
		double a1 = tree[k*2+1].x,a2 = tree[k*2+2].x;
		double b1 = tree[k*2+1].y,b2 = tree[k*2+2].y;
		tree[k*2+1].x = a1*cos(tree[k].angle)+b1*sin(tree[k].angle);
		tree[k*2+2].x = a2*cos(tree[k].angle)+b2*sin(tree[k].angle);
		tree[k*2+1].y = b1*cos(tree[k].angle)-a1*sin(tree[k].angle);
		tree[k*2+2].y = b2*cos(tree[k].angle)-a2*sin(tree[k].angle);
		tree[k].angle = 0.0;

		update(s, ang, k*2+1, l, (l+r)/2);
		update(s, ang, k*2+2, (l+r)/2, r);

		tree[k].x = tree[k*2+1].x+tree[k*2+2].x;
		tree[k].y = tree[k*2+1].y+tree[k*2+2].y;
	}
	return ;
}

int main(void){

	bool first = true;
	while(scanf("%d %d",&N,&C) != EOF){
		if(!first){
			puts("");
		}
		first = false;
		for (int i = 0; i < N; ++i){
			scanf("%d",&len[i]);
		}
		init(0,0,N);
		int p;double angle;
		for (int i = 0; i < C; ++i){
			scanf("%d %lf",&p,&angle);

			update(p, PI-angle/180*PI, 0, 0, N);
			printf("%.2f %.2f\n",tree[0].x,tree[0].y);
		}
	}

   return 0;
}