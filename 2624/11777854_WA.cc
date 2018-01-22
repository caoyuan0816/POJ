#include <iostream>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define eps 1e-6
#define pi acos(-1.0)
#define inf 1e100

using namespace std;

struct Pnt{
	double x,y;
	Pnt(){}
	Pnt(double xx,double yy)
	{
		x=xx;
		y=yy;
	}
};

int Is_same(Pnt a,Pnt b){
	return (a.x==b.x && a.y==b.y)?1:0;
}

int main(void)
{
	int i,j,a,b,judge=0;
	Pnt A,U(0,0),E(0,0);
	vector<Pnt> Set;
	vector<Pnt> ans;

	while(scanf("%lf %lf",&A.x,&A.y)!=EOF)
	{
		Set.push_back(A);

		for(i=1;i!=4;i++)
		{
			scanf("%lf %lf",&A.x,&A.y);
			Set.push_back(A);
		}

		for(i=0;i<4;i++)
		{
			for(j=i+1;j<4;j++)
			{
				if(Is_same(Set[i],Set[j]))
				{
					judge=1;
					break;
				}
			}
			if(judge==1)
			{
				judge=0;
				break;
			}
		}

		a=i;b=j;

		for(i=0;i<4;i++)
		{
			if(i!=a && i!= b)
				ans.push_back(Set[i]);
		}

		ans.push_back(Set[a]);
		ans.push_back(Set[b]);

		U.x=(ans[0].x+ans[1].x)/2.0;
		U.y=(ans[0].y+ans[1].y)/2.0;

		E.x=ans[2].x+2.0*(U.x-ans[2].x);
		E.y=ans[2].y+2.0*(U.y-ans[2].y);

		Set.clear();
		ans.clear();

		printf("%.3lf %.3lf\n",E.x,E.y);
	}
return 0;
}