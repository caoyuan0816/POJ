#include <cstdio>
#include <cmath>

#define pi acos(-1.0)

int main(void)
{
	int N,i,j;
	double a=0,r,x,y;

	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%lf%lf",&x,&y);
		j=0;
		while(1)
		{
			j++;
			a+=50;
			r=sqrt((2*a)/pi);
			if(sqrt(x*x+y*y)<r)
			{
				printf("Property %d: This property will begin eroding in year %d.\n",i+1,j);
				break;
			}
		}
	}
	printf("END OF OUTPUT.\n");

return 0;	
}