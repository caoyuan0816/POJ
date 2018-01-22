#include <cstdio>
#include <cmath>

#define pi acos(-1.0)

static double ans[10000];

int main(void)
{
	int i=1;
	double sum=0;

	while(i++)
	{
		sum+=(1.0/i);
		ans[i-2]=sum;
		if(sum>=5.20)
			break;
	}
	while(1)
	{
		scanf("%lf",&sum);
		if(sum==0)
			break;
		i=0;
		for(i=0;ans[i]!=0;i++)
		{
			if(ans[i]>=sum)
			{
				printf("%d card(s)\n",i+1);
				break;
			}
		}
		
	}


return 0;	
}