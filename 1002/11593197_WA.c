#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char hehe[24]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','W','X','Y'};
struct tel{
	char num[8];
};
struct tel book[100000];

void deal(char * use);
int comp(const void *p1,const void *p2);

int main(void)
{
	int n,i,j,k=1;
	char use[20];

	memset(use,0,sizeof(use));

	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		gets(use);
		deal(use);
		strcpy(book[i].num,use);
		memset(use,0,sizeof(use));
	}

	qsort(book,n,sizeof(book[0].num),comp);

	for(i=0;i<n;i++)
	{
		if(book[i].num[0]!=0)
			for(j=i+1;j<n;j++)
				if(strcmp(book[i].num,book[j].num)==0)
				{
					k++;
					memset(book[j].num,0,sizeof(book[j].num));
				}
		if(k>1)
		{
			for(j=0;j<3;j++)
				printf("%c",book[i].num[j]);
			putchar('-');
			for(j=3;j<7;j++)
				printf("%c",book[i].num[j]);
			printf(" %d\n",k);
		}
		k=1;
	}
return 0;
}

void deal(char * use)
{
	int i,j;

	for(i=0;i<strlen(use);i++)
	{
		for(j=0;j<24;j++)
		{
			if(hehe[j]==use[i])
			{
				use[i]=j/3+50;
				break;
			}
		}
		if(use[i]=='-')
		{
			for(j=i;j<strlen(use);j++)
				use[j]=use[j+1];
			i--;
		}
	}

return;	
}

int comp(const void *p1,const void *p2)
{
	char * a1 = (char *)p1;
	char * a2 = (char *)p2;
	if(*a1<*a2)
		return -1;
	else if(*a1==*a2)
		return 0;
	else 
		return 1;
}