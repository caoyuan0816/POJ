/*线段树--区间求和*/
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Cnode{
	int L,R;
	long long sum;
	long long inc;
	Cnode *pleft,*pright;
};

int Count=0;
long long  Lsum=0;
Cnode Tree[500000];

void BuildTree(Cnode *pRoot,int L,int R){
	pRoot->L=L;pRoot->R=R;
	pRoot->sum=0;pRoot->inc=0;
	if(L!=R){
	Count++;pRoot->pleft =Tree+Count;
	Count++;pRoot->pright=Tree+Count;
	BuildTree(pRoot->pleft,L,(L+R)/2);
	BuildTree(pRoot->pright,(L+R)/2+1,R);}
return;}

void Insert(Cnode *pRoot,int i,int v){
	pRoot->sum+=v;

	if(i==pRoot->L && i==pRoot->R){return;}
	if(i<=(pRoot->L+pRoot->R)/2)
		Insert(pRoot->pleft,i,v);
	else 	Insert(pRoot->pright,i,v);
return;}

void Add(Cnode *pRoot,int a,int b,int v){
	if(a==pRoot->L && b==pRoot->R){pRoot->inc+=v;return;}
	pRoot->sum+=v*(b-a+1);
	if(b<=(pRoot->L+pRoot->R)/2)
		Add(pRoot->pleft,a,b,v);
	else if(a>=(pRoot->L+pRoot->R)/2+1)
		Add(pRoot->pright,a,b,v);
	else{	Add(pRoot->pleft,a,(pRoot->L+pRoot->R)/2,v);
		Add(pRoot->pright,(pRoot->L+pRoot->R)/2+1,b,v);}
return;}

void  Query(Cnode *pRoot,int a,int b){
	if(a==pRoot->L && b==pRoot->R){Lsum+=pRoot->sum+pRoot->inc*(pRoot->R-pRoot->L+1);return;}
	pRoot->sum+=pRoot->inc*(pRoot->R-pRoot->L+1);
	pRoot->pleft->inc+=pRoot->inc;pRoot->pright->inc+=pRoot->inc;
	pRoot->inc=0;
	if(b<=(pRoot->L+pRoot->R)/2)
		Query(pRoot->pleft,a,b);
	else if(a>=(pRoot->L+pRoot->R)/2+1)
		Query(pRoot->pright,a,b);
	else{
		Query(pRoot->pleft,a,(pRoot->L+pRoot->R)/2);
		Query(pRoot->pright,(pRoot->L+pRoot->R)/2+1,b);}
return;}

int main(void)
{
	int N,Q,i,a,c,d;
	char ch;
	cin>>N>>Q;
	BuildTree(Tree,1,N);
	for(i=0;i!=N;i++){
		scanf("%d",&a);
		Insert(Tree,i+1,a);}

	for(i=0;i!=Q;i++)
	{
		getchar();
		scanf("%s %d %d",&ch,&c,&d);

		if(ch=='Q'){
			Lsum=0;
			Query(Tree,c,d);
			printf("%lld\n",Lsum);}
		else if(ch=='C'){
			scanf("%d",&a);
			Add(Tree,c,d,a);}
	}
return 0;
}
