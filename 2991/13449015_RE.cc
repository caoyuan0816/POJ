#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_N = 30;
const int MAX_Tree = 30;
const double PI = acos(-1.0);

int N,C;
int len[MAX_N];
double cur_angle[MAX_N];
struct Node{
	double x;
	double y;
	double angle;
};
Node tree[MAX_Tree];

//[l,r]
void init(int k ,int l, int r){

	tree[k].x = tree[k].angle = 0.0;
	if(l == r){
		tree[k].y = len[l];
	}else{
		int lch = k<<1 , rch = k<<1|1, mid = (l+r)>>1;
		init(lch, l,   mid);
		init(rch, mid+1, r);
		tree[k].y = tree[lch].y+tree[rch].y;
	}
}

void rotate(int k, double ang){
	double a = tree[k].x, b = tree[k].y;
	tree[k].x = a*cos(ang)+b*sin(ang);
	tree[k].y = b*cos(ang)-a*sin(ang);
}

void down(int k, int l, int r){
	int lch = k<<1 , rch = k<<1|1;

	rotate(k, tree[k].angle);
	if(l!=r){
		tree[lch].angle += tree[k].angle;
		tree[rch].angle += tree[k].angle;
	}
	tree[k].angle = 0.0;
}

//[a,b] [l,r]
void add(int a,int b, double ang, int k, int l, int r){

	int lch = k<<1 , rch = k<<1|1, mid = (l+r)>>1;

	down(k, l, r);

	if(a == l && b == r){

		tree[k].angle = ang;
		down(k, l, r);
		return;
	}

	if(b <= mid){
		add(a, b, ang, lch,  l,  mid);
	}else if(a >= mid+1){
		add(a, b, ang, rch, mid+1, r);
	}else{
		add(a,   mid, ang, lch,  l,  mid);
		add(mid+1, b, ang, rch, mid+1, r);
	}

	if(l != r){
		if(tree[lch].angle != 0.0){
			down(lch, l, mid);
		}
		if(tree[rch].angle != 0.0){
			down(rch, mid+1, r);
		}
		tree[k].x = tree[lch].x+tree[rch].x;
		tree[k].y = tree[lch].y+tree[rch].y;
	}
	
	return;
}

int main(void){

	bool first = true;
	while(scanf("%d %d",&N,&C) != EOF){
		if(!first){
			puts("");
		}
		first = false;
		for (int i = 1; i <= N; ++i){
			scanf("%d",&len[i]);
		}
		init(1,1,N);
		for (int i = 0; i <= N; ++i){
			cur_angle[i] = 180;
		}
		int p;double angle;
		for (int i = 0; i < C; ++i){
			scanf("%d %lf",&p,&angle);

			add(p+1, N, (cur_angle[p]-angle)/180*PI, 1, 1, N);

			cur_angle[p] = angle;
			printf("%.2f %.2f\n",tree[1].x,tree[1].y);
		}
	}

   return 0;
}

/*
   88  0 23
   88  0 9
   88  -7.37237 -5.16219
   */