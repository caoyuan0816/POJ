#include <stdio.h>
#include <string.h>

static char use1[101],num1[101],num2[500],ans[500],coco[500];

void fun(char *num2,char *num1,int l);
int len(char *num);

int main(void)
{
	int i,j,k,a,b,c,n,m=-1,l,judge=0;

	
	while(scanf("%s %d",use1,&n)==2)
{

	l=strlen(use1);

	for(i=strlen(use1)-1,j=0;i>=0;i--,j++)
	{
		if(use1[i]=='.')
		{
			m=j;
			j--;
			l--;
			continue;
		}
		else
			num1[j]=use1[i]-'0';
	}

	for(i=0;i<l;i++)
	{
		num2[i]=num1[i];
	}

	for(i=0;i<n-1;i++)
	{
		memset(ans,0,len(ans));
		fun(num2,num1,l);	
	}

	for(i=499;i>=0;i--)
		if(ans[i]!=0)
		{
			k=0;
			if(i<m*n)
			{
				coco[k]='0';
				coco[k+1]='.';
				k+=2;
				judge=1;
				for(j=i+1;j<m*n;j++)
				{
					coco[k]='0';
					k++;
				}
			}
			for(j=i;j>=0;j--)
			{
				if(j==m*n)
				{
					coco[k]=ans[j]+'0';
					coco[k+1]='.';
					k+=2;
					judge=1;
				}
				else
				{
					coco[k]=ans[j]+'0';
					k++;
				}
			}	
			break;
		}

	if(judge==1)
	{
		for(j=strlen(coco)-1;j>=0;j--)
		{
			if(coco[j]=='0')
				coco[j]=0;
			else
				break;
		}
	}
	judge=0;
	printf("%s\n",coco);
	
	memset(num1,0,len(num1));
	memset(num2,0,len(num2));
	memset(coco,0,len(coco));
}

return 0;
}

void fun(char *num2,char *num1,int l)
{
	int i,j,k,a,b,c;
	for(i=0;i<len(num2);i++)
	{
		k=i;
		for(j=0;j<l;j++)
		{
			a=num1[j];
			b=num2[i];

			c=a*b;

			if(c>=10)
			{
				ans[k]+=c%10;
				ans[k+1]+=c/10;
			}
			else
				ans[k]+=c;
			k++;
		}
		for(k=0;k<len(ans);k++)
		{
                        while((ans[k])>=10)
			{
				c=ans[k];

				ans[k+1]+=c/10;
				ans[k]=c-10*(c/10);
			}
		}
	}
	for(i=0;i<len(ans);i++)
		num2[i]=ans[i];
return;
}

int len(char *num)
{
	int i;

	for(i=499;i>=0;i--)
	{
		if(num[i]!=0)
			break;
	}

return i+1;
}