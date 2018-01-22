#include <cstdio>

int main(void)
{
	int i;
	double sum=0;
	double a;
	for(i=0;i<12;i++)
	{
		scanf("%lf",&a);
		sum+=a;
	}

	printf("$%.2lf\n",sum/12.0);

return 0;	
}