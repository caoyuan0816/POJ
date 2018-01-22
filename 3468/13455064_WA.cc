#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
const int MAX_Tree = (MAX_N <<2);
const double PI = acos(-1.0);

typedef long long ll;
int N,C;
struct Node{
	ll sum;
	ll inc;
};
Node tree[MAX_Tree];


void down(int k, int l, int r){
	int lch = k<<1 , rch = k<<1|1;

	tree[k].sum += tree[k].inc*(r-l+1);
	if(l != r){
		tree[lch].inc += tree[k].inc;
		tree[rch].inc += tree[k].inc;
	}
    tree[k].inc = 0;
}

void up(int k,int l,int r){
	int lch = k<<1 , rch = k<<1|1;
    tree[k].sum = tree[lch].sum + tree[rch].sum;
}

//[l,r]
void init(int k ,int l, int r){

	tree[k].inc = 0;
    if(l == r){
        scanf("%lld",&tree[k].sum);
    }else{
        int lch = k<<1 , rch = k<<1|1, mid = (l+r)>>1;
        init(lch, l,   mid);
        init(rch, mid+1, r);
        up(k, l, r);
    }
}

//[a,b] [l,r]
void add(int a, int b, ll v, int k, int l, int r){

    int lch = k<<1 , rch = k<<1|1, mid = (l+r)>>1;

    down(k, l, r);
	if(a == l && b == r){
		tree[k].inc += v;
		down(k, l, r);
		return;
	}

	if(b <= mid){
		add(a, b, v, lch,  l,  mid);
	}else if(a >= mid+1){
		add(a, b, v, rch, mid+1, r);
	}else{
		add(a,   mid, v, lch,  l,  mid);
		add(mid+1, b, v, rch, mid+1, r);
	}

	if(l != r){
		if(tree[lch].inc != 0){
			down(lch, l, mid);
		}
		if(tree[rch].inc != 0){
			down(rch, mid+1, r);
		}
		up(k, l, r);
	}
}

ll query(int a, int b, int k, int l, int r){

    int lch = k<<1 , rch = k<<1|1, mid = (l+r)>>1;

    if(a == l && b == r){
        return tree[k].sum;
    }

    if(b <= mid){
        return query(a, b, lch,  l,  mid);
    }else if(a > mid){
        return query(a, b, rch, mid+1, r);
    }else{
        return query(a,   mid, lch,  l,  mid) + query(mid+1, b, rch, mid+1, r);
    }
}

int main(void){

    while(scanf("%d %d",&N,&C) != EOF){
        
    	init(1, 1, N);
    	char ch;
        for(int i=0; i<C; i++){
            getchar();
            ch = getchar();
            if(ch == 'Q'){
            	int l,r;
            	scanf("%d %d",&l,&r);
            	printf("%lld\n",query(l, r, 1, 1, N));
            }else{
            	int l,r,v;
            	scanf("%d %d %d",&l,&r,&v);
            	add(l, r, v, 1, 1, N);
            }
        }
    }

   return 0;
}