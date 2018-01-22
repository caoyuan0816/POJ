#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Cnode{
	int L,R;
	bool covered;
	Cnode *pleft,*pright;
};

int Count=0;
Cnode Tree[10000010];
int Len=0,Lu=0,num[10000010],use[10000010];
static int aa[10000010];
bool V=false;

void BuildTree(Cnode *pRoot,int L,int R){
	pRoot->L=L;pRoot->R=R;
	pRoot->covered=true;
	if(L!=R){
	Count++;pRoot->pleft =Tree+Count;
	Count++;pRoot->pright=Tree+Count;
	BuildTree(pRoot->pleft,L,(L+R)/2);
	BuildTree(pRoot->pright,(L+R)/2+1,R);}
return;}

void Add(Cnode *pRoot,int b,int a){
	if(a==pRoot->L && b==pRoot->R){if(!V) V=pRoot->covered;pRoot->covered=false;return;}

	if(!pRoot->covered){pRoot->pleft->covered=false;pRoot->pright->covered=false;}

	if(b<=(pRoot->L+pRoot->R)/2)
		Add(pRoot->pleft,b,a);
	else if(a>=(pRoot->L+pRoot->R)/2+1)
		Add(pRoot->pright,b,a);
	else{
		Add(pRoot->pleft,(pRoot->L+pRoot->R)/2,a);
		Add(pRoot->pright,b,(pRoot->L+pRoot->R)/2+1);}
return;}

int main(void)
{
	int N,i;

	scanf("%d",&N);

	for(i=0;i!=N;i++)
	{
		int M,j,Cao=0;

		scanf("%d",&M);

		for(j=0;j!=M;j++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			use[Lu++]=a;num[Len++]=a;use[Lu++]=b;num[Len++]=b;
		}
		
		sort(num,num+Len);
		Len=unique(num,num+Len)-num;

		for(j=0;j<Len;j++)
		{
			aa[num[j]]=j+1;
		}

		BuildTree(Tree,1,Len);Count=0;
		
		Lu--;
		while(Lu>0)
		{	int a,b;
			V=false;
			a=aa[use[Lu--]];b=aa[use[Lu--]];
			Add(Tree,a,b);
			if(V) Cao++;
		}
		printf("%d\n",Cao);Len=0;Lu=0;
	}

return 0;
}
