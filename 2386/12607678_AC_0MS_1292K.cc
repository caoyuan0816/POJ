#include <stdio.h>
#include <iostream>
static int N;
static int M;
static char G[105][105];
using namespace std;
void dfs(int x,int y){
	G[x][y]='.';
	int dx,dy;
	for(dx=-1;dx<=1;dx++){
		for (dy = -1; dy <=1 ; dy++)
		{
			int nx=x+dx;
			int ny=y+dy;
			if((0<=nx)&&(nx<N)&&(0<=ny)&&(ny<M)&&(G[nx][ny]=='W')){
				dfs(nx,ny);
			}
		}
	}
	return ;
}
int main(){
    //freopen("/Users/yuan/Documents/test/in", "r+", stdin);
	scanf("%d %d",&N,&M);
	int i=0;
    getchar();
    for(i=0;i<N;i++){
        for(int j=0;j<M;j++){
            G[i][j]=getchar();
        }getchar();
    }
	int res=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(G[i][j]=='W'){
				dfs(i,j);
				res++;
			}
		}
	}
	printf("%d\n",res);
	return 0;
}
