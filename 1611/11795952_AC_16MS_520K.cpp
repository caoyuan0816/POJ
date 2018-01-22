#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
struct Cnode{
	int n;
	Cnode *father;
};

Cnode Tree[1000000];

void BuildTree(Cnode *p,int a,int b){
	int i;for(i=a;i<=b;i++){(p+i)->n=i;(p+i)->father=(p+i);}
return;}

Cnode * Get_father(Cnode * p){
	if(p->father != p)
		p->father=Get_father(p->father);
	return p->father;
}

void Merge(Cnode *p,int a,int b){
	Get_father(p+b)->father=Get_father(p+a);
return;}

int main(void)
{
	while(1)
	{
		int n,m,i,Fuck=0;int num[30020];
		scanf("%d%d",&n,&m);
		if(n==0 && m==0)return 0;
		BuildTree(Tree,0,n-1);

		for(i=0;i!=m;i++)
		{
			int a,j;
			scanf("%d",&a);
			for(j=0;j<a;j++)
			{	
				scanf("%d",&num[j]);
			}
			for(j=0;j<a-1;j++)
			{
				Merge(Tree,num[j],num[j+1]);
			}
		}

		//cout<<"1's Father is  "<<Get_father(Tree+1)->father->n<<endl;		

		for(i=0;i<n;i++)
		{
			if(Get_father(Tree)==Get_father(Tree+i))
				Fuck++;
		}
		printf("%d\n",Fuck);
	}
return 0;
}