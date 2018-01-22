#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char hehe[24]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','W','X','Y'};
struct tel{
	char num[8];
};
struct tel book[100010];
static int t=0;

void deal(char * use);
int comp(const void *p1,const void *p2);
void put(char * a,int b);

int main(void)
{
	int n,i,j,ca=0;
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

	qsort(book->num,n,sizeof(book[0].num),comp);

	for(i=0,j=1;i<n;i++)
	{
		if(strcmp(book[i].num,book[i+1].num)==0)
		{
			j++;
			continue;
		}
		else if(j!=1)
		{
			put(book[i].num,j);
			j=1;
			ca++;
		}
	}
	if(ca==0)
		printf("No duplicates.\n");
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
	
	return strcmp(a1,a2);
}

void put(char * a,int b)
{
	int i;
	for(i=0;i<3;i++)
		printf("%c",a[i]);
	putchar('-');
	for(;i<7;i++)
		printf("%c",a[i]);
	printf(" %d\n",b);
return;
}