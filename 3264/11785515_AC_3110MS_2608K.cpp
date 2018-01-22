#include <iostream>
#include <algorithm>
#include <cstdio>

#define MY_MAX -99999999
#define MY_MIN  99999999

using namespace std;

struct Cnode{
	int L,R;
	int nmin,nmax;
	Cnode *pleft,*pright;
};

int amax,amin;
int nCount=0;
Cnode Tree[500000];

void BuildTree(Cnode *pRoot,int L,int R){
	pRoot->L=L;	pRoot->R=R;
	
	pRoot->nmin=MY_MIN;	pRoot->nmax=MY_MAX;

	if(L!=R){
		nCount++;
		pRoot->pleft=Tree+nCount;
		nCount++;
		pRoot->pright=Tree+nCount;
		BuildTree(pRoot->pleft,L,(L+R)/2);
		BuildTree(pRoot->pright,(L+R)/2+1,R);	}
return;}

void Insert(Cnode *pRoot,int i,int v){
	if(pRoot->L == i && pRoot->R == i)
		{pRoot->nmax=pRoot->nmin=v;return;}

	pRoot->nmin=min(pRoot->nmin,v);
	pRoot->nmax=max(pRoot->nmax,v);

	if(i<=(pRoot->L+pRoot->R)/2)
		Insert(pRoot->pleft,i,v);
	else
		Insert(pRoot->pright,i,v);
return;}

void Query(Cnode *pRoot,int a,int b){
	if((pRoot->nmin >= amin) && (pRoot->nmax <= amax)){return;}
	if(a==pRoot->L && b==pRoot->R){
		amin=min(pRoot->nmin,amin);amax=max(pRoot->nmax,amax);return;}
	if(b<=(pRoot->L+pRoot->R)/2)
		Query(pRoot->pleft,a,b);
	else if(a>=(pRoot->L+pRoot->R)/2+1)
		Query(pRoot->pright,a,b);
	else{	Query(pRoot->pleft,a,(pRoot->L+pRoot->R)/2);
		Query(pRoot->pright,(pRoot->L+pRoot->R)/2+1,b);}return;}

int main(void)
{
	int N,Q,i,u,c,d;
	cin>>N>>Q;
	
	BuildTree(Tree,1,N);

	for(i=1;i<=N;i++){
		scanf("%d",&u);	
		Insert(Tree,i,u);
	}
	
	for(i=0;i<Q;i++)
	{
		scanf("%d %d",&c,&d);
		amax=MY_MAX;amin=MY_MIN;
		Query(Tree,c,d);
		cout<<amax-amin<<endl;
	}
return 0;
}
