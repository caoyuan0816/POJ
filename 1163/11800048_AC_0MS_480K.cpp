#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct point{
	int a;int b;
};

point tri[400][400];

int main(void)
{
	int N,i,j;
	scanf("%d",&N);
	
	for(i=0;i<N;i++)
		for(j=0;j<=i;j++)	{scanf("%d",&(tri[i][j].a));tri[i][j].b=0;}

	for(i=N-2;i>=0;i--){
		
		for(j=0;j<=i;j++)
		tri[i][j].b=max(tri[i+1][j].a+tri[i+1][j].b,tri[i+1][j+1].a+tri[i+1][j+1].b);
		if(i==0){printf("%d\n",tri[i][0].a+tri[i][0].b);}
	}
return 0;
}