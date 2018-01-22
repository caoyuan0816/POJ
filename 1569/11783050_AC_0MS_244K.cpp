#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdio>

#define eps 1e-6
#define pi acos(-1.0)
#define inf 1e20
#define O Pnt(0,0);

using namespace std;
struct Pnt{double x,y;Pnt(){}Pnt(double xx,double yy){x=xx;y=yy;}};
struct Vec{double x,y;Vec(){}Vec(double xx,double yy){x=xx;y=yy;}};
struct Seg{Pnt x,y;Seg(){}Seg(Pnt xx,Pnt yy){x=xx;y=yy;}};
struct use{double x;int a,b,c;use(){};use(double xx){x=xx;}};

int    dbsgn(double a){return a<-eps?-1:a>+eps?+1:0;}
int    dbcmp(double a,double b){return dbsgn(a-b);}
double operator *(Vec a,Vec b){return a.x*b.x+a.y*b.y;}
double operator ^(Vec a,Vec b){return a.x*b.y-a.y*b.x;}
Vec    operator +(Vec a,Vec b){return Vec(a.x+b.x,a.y+b.y);}
Pnt    operator +(Pnt a,Vec b){return Pnt(a.x+b.x,a.y+b.y);}
Vec    operator -(Pnt a,Pnt b){return Vec(a.x-b.x,a.y-b.y);}
int    operator ==(Pnt a,Pnt b){return a.x==b.x && a.y==b.y;}
int    Is_left (Vec a,Vec b){return dbsgn(a^b);}
int    Is_right(Vec a,Vec b){return !Is_left(a,b);}
int    Is_front(Vec a,Vec b){return dbsgn(a*b);}
int    Is_back (Vec a,Vec b){return !Is_front(a,b);} 
int    Is_cross(Seg a,Seg b){
	if(((a.y-a.x)^(b.y-a.x))==0 && ((a.y-a.x)^(b.x-a.x))==0){
		return dbsgn((a.x-b.x)*(a.x-b.y))<=0;}
	return ((a.y-a.x)^(b.y-a.x))*((a.y-a.x)^(b.x-a.x))<=0
		&& ((b.y-b.x)^(a.y-b.x))*((b.y-b.x)^(a.x-b.x))<=0;}
int    Is_beside(Seg a,Seg b,Seg c){
	return ((a.y-a.x)^(b.y-b.x))*((a.y-a.x)^(c.y-c.x))<=0;
}
int    Is_intri(Pnt a,Pnt b,Pnt c,Pnt d){
	Seg l1(a,c),l2(a,b),l3(c,a),l4(c,b),l5(b,a),l6(b,c),lx(a,d),ly(c,d),lz(b,d);
	return Is_beside(lx,l1,l2)&&Is_beside(ly,l3,l4)&&Is_beside(lz,l5,l6);}

int main(void)
{
	int N;
	while(cin>>N)
	{
		if(N==0)return 0;
		int i,j,k,l,judge=0;
		char ch;
		use m;m.x=0;m.a=0;m.b=0;m.c=0;
		double area;
		Pnt A;
		vector<Pnt> set;
		for(i=0;i!=N;i++)
		{
			cin>>ch>>A.x>>A.y;
			set.push_back(A);
		}
		for(i=0;i!=set.size();i++){
		for(j=i+1;j!=set.size();j++){
		for(k=j+1;k!=set.size();k++){
		for(l=0;l!=set.size();l++){
		if(l!=i&&l!=j&&l!=k){
			if(Is_intri(set[i],set[j],set[k],set[l])){judge=1;break;}}}
		if(judge==0){
			area=fabs(((set[j]-set[i])^(set[k]-set[i]))/2.0);
			if(area>m.x){m.x=area;m.a=i;m.b=j;m.c=k;}}judge=0;
		
		}}}
		printf("%c%c%c\n",'A'+m.a,'A'+m.b,'A'+m.c);
	}
	
return 0;	
}