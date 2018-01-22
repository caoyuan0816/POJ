#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
const int MAX_BIT = (MAX_N <<2);

//******Important: 每次重新读取数据都要初始化
//******Important: 使用时注意BIT数据范围为int还是long long，并且注意求和是否会溢出
typedef long long ll;
int N,C;
int bit1[MAX_N + 1];
int bit2[MAX_N + 1];

//两个函数适用于多组BIT共存，第一个参数处传入BIT数组名称即可
//[1,N]
ll sum(int* BIT,int i){
	ll s = 0;
	while(i > 0){
		s += BIT[i];
		i -= i&-i;
	}
	return s;
}

void add(int* BIT,int i, int x){
	while(i <= N){
		BIT[i] += x;
		i += i&-i;
	}
}

int main(void){

    while(scanf("%d %d",&N,&C) != EOF){
        
        memset(bit1, 0, sizeof(bit1));
        memset(bit2, 0, sizeof(bit2));
        int temp;
        for (int i = 1; i <= N; ++i){
        	scanf("%d",&temp);
        	add(bit2, i, temp);
        }

    	char ch;
        for(int i=0; i<C; i++){
            getchar();
            ch = getchar();
            if(ch == 'Q'){
            	int l,r;
            	scanf("%d %d",&l,&r);
            	printf("%lld\n",sum(bit1, r)*r+sum(bit2, r)-sum(bit1, l-1)*(l-1)-sum(bit2, l-1));
            }else{
            	int l,r,v;
            	scanf("%d %d %d",&l,&r,&v);
            	add(bit1, l, v);
            	add(bit1, r+1, -v);
            	add(bit2, l, -v*(l-1));
            	add(bit2, r+1, v*r);
            }
        }
    }

   return 0;
}