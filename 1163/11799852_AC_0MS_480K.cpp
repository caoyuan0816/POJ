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

	for(i=N-1;i>=0;i--){
		if(i==0){printf("%d\n",tri[i][0].a+tri[i][0].b);}
		else{
		for(j=0;j<=i;j++){
			if(j!=i && j!=0){
				tri[i-1][j-1].b=max(tri[i][j].a+tri[i][j].b,tri[i-1][j-1].b);
				tri[i-1][j].b=max(tri[i][j].a+tri[i][j].b,tri[i-1][j].b);}
			else if(j==0)    
				tri[i-1][j].b=max(tri[i][j].a+tri[i][j].b,tri[i-1][j].b);
			else 		 
				tri[i-1][j-1].b=max(tri[i][j].a+tri[i][j].b,tri[i-1][j-1].b);}}

	}
return 0;
}