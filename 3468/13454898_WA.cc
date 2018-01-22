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

int N,C;
struct Node{
	int sum;
	int inc;
};
Node tree[MAX_Tree];


void down(int k, int l, int r){
    
}

void up(int k,int lch,int rch){
    
}

//[l,r]
void init(int k ,int l, int r){

	tree[k].inc = 0;
    if(l == r){
        scanf("%d",&tree[k].sum);
    }else{
        int lch = k<<1 , rch = k<<1|1, mid = (l+r)>>1;
        init(lch, l,   mid);
        init(rch, mid+1, r);
        tree[k].sum = tree[lch].sum + tree[rch].sum;
    }
}

//[a,b] [l,r]
void add(int a, int b, int v, int k, int l, int r){

    int lch = k<<1 , rch = k<<1|1, mid = (l+r)>>1;
   	
   	if(a == l && b == r){
        tree[k].inc += v;
        return;
    }

    if(b <= mid){
        add(a, b, v, lch,  l,  mid);
    }else if(a > mid){
        add(a, b, v, rch, mid+1, r);
    }else{
        add(a,   mid, v, lch,  l,  mid);
        add(mid+1, b, v, rch, mid+1, r);
    }
    return;
}

int query(int a, int b, int k, int l, int r){

    int lch = k<<1 , rch = k<<1|1, mid = (l+r)>>1;

    int sum = tree[k].inc*(b-a+1);
    if(a == l && b == r){
        return sum + tree[k].sum;
    }

    if(b <= mid){
        sum += query(a, b, lch,  l,  mid);
    }else if(a > mid){
        sum += query(a, b, rch, mid+1, r);
    }else{
        sum += query(a,   mid, lch,  l,  mid) + query(mid+1, b, rch, mid+1, r);
    }
    return sum;
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
            	printf("%d\n",query(l, r, 1, 1, N));
            }else{
            	int l,r,v;
            	scanf("%d %d %d",&l,&r,&v);
            	add(l, r, v, 1, 1, N);
            }
        }
    }

   return 0;
}