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

int    dbsgn(double a){return a<-eps?-1:a>+eps?+1:0;}
int    dbcmp(double a,double b){return dbsgn(a-b);}
double operator *(Vec a,Vec b){return a.x*b.x+a.y*b.y;}
double operator ^(Vec a,Vec b){return a.x*b.y-a.y*b.x;}
Vec    operator +(Vec a,Vec b){return Vec(a.x+b.x,a.y+b.y);}
Pnt    operator +(Pnt a,Vec b){return Pnt(a.x+b.x,a.y+b.y);}
Vec    operator -(Pnt a,Pnt b){return Vec(a.x-b.x,a.y-b.y);}
int    operator ==(Pnt a,Pnt b){return a.x==b.x && a.y==b.y;}
Vec    operator *(double a,Vec b){return Vec(a*b.x,a*b.y);}
ostream& operator << (ostream& cout, Pnt a){return cout<<"("<<a.x<<","<<a.y<<")";}
int    Is_left (Vec a,Vec b){return dbsgn(a^b);}
int    Is_right(Vec a,Vec b){return !Is_left(a,b);}
int    Is_front(Vec a,Vec b){return dbsgn(a*b);}
int    Is_back (Vec a,Vec b){return !Is_front(a,b);} 
int    Is_cross(Seg a,Seg b){
	if(((a.y-a.x)^(b.y-a.x))==0 && ((a.y-a.x)^(b.x-a.x))==0){
		return dbsgn((a.x-b.x)*(a.x-b.y))<=0;}
	return ((a.y-a.x)^(b.y-a.x))*((a.y-a.x)^(b.x-a.x))<=0
		&& ((b.y-b.x)^(a.y-b.x))*((b.y-b.x)^(a.x-b.x))<=0;}
int    Is_Line_cross(Seg a,Seg b){
	return ((a.y-a.x)^(b.y-a.x))*((a.y-a.x)^(b.x-a.x))<0;}
int    Is_Line_par(Seg a,Seg b){return ((a.y-a.x)^(b.y-a.x))==0 && ((a.y-a.x)^(b.x-a.x))==0;}
int    Is_Line_coi(Seg a,Seg b){Seg c(a.x,b.y),d(a.y,b.x);return Is_Line_par(c,d);}
Pnt    Get_intersec(Seg a,Seg b){Pnt P=a.x,Q=b.x;Vec v=a.y-a.x,w=b.y-b.x,u=P-Q;
	double t=(w^u)/(v^w);return P+t*v;}
int    Is_beside(Seg a,Seg b,Seg c){
	return ((a.y-a.x)^(b.y-b.x))*((a.y-a.x)^(c.y-c.x))<=0;}
int    Is_intri(Pnt a,Pnt b,Pnt c,Pnt d){
	Seg l1(a,c),l2(a,b),l3(c,a),l4(c,b),l5(b,a),l6(b,c),lx(a,d),ly(c,d),lz(b,d);
	return Is_beside(lx,l1,l2)&&Is_beside(ly,l3,l4)&&Is_beside(lz,l5,l6);}

int main(void)
{
	int N,i;
	cout<<"INTERSECTING LINES OUTPUT"<<endl;
	cin>>N;
	for(i=0;i<N;i++)
	{
		Pnt A,B,C,D,X;
		cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y>>D.x>>D.y;
		Seg l1(A,B),l2(C,D);
		
		
		if(Is_Line_coi(l1,l2))
			cout<<"LINE"<<endl;
		else if(Is_Line_cross(l1,l2))
		{
			cout<<"POINT";
			X=Get_intersec(l1,l2);
			printf(" %.2lf %.2lf\n",X.x,X.y);
		}
			
		else
			cout<<"NONE"<<endl;
	}
	cout<<"END OF OUTPUT"<<endl;
	
return 0;	
}

