#include <iostream>
#include <cmath>

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
int    Is_left (Vec a,Vec b){return dbsgn(a^b);}
int    Is_right(Vec a,Vec b){return !Is_left(a,b);}
int    Is_front(Vec a,Vec b){return dbsgn(a*b);}
int    Is_back (Vec a,Vec b){return !Is_front(a,b);} 
int    Is_cross(Seg a,Seg b){
	return ((a.y-a.x)^(b.y-a.x))*((a.y-a.x)^(b.x-a.x))<0
		&& ((b.y-b.x)^(a.y-b.x))*((b.y-b.x)^(a.x-b.x))<0;}

int main(void)
{
	int N,i;
	double xstart,ystart,xend,yend,x1,y1,x2,y2;

	cin>>N;
	for(i=0;i<N;i++)
	{
		cin>>xstart>>ystart>>xend>>yend>>x1>>y1>>x2>>y2;
		Pnt A(xstart,ystart),B(xend,yend);
		Pnt X(x1>x2?x1:x2,y1<y2?y1:y2),Y(x1<x2?x1:x2,y1<y2?y1:y2);
		Pnt Z(x1<x2?x1:x2,y1>y2?y1:y2),W(x1>x2?x1:x2,y1>y2?y1:y2);
		Seg l0(A,B),l1(X,W),l2(X,Y),l3(Y,Z),l4(Z,W);

		if(((xstart>xend?xstart:xend) <= (x1>x2?x1:x2)) && ((xstart<xend?xstart:xend) >= (x1<x2?x1:x2)))
			if(((ystart>yend?ystart:yend) <= (y1>y2?y1:y2)) && ((ystart<yend?ystart:yend) >= (y1<y2?y1:y2)))
			{
				cout<<"T"<<endl;
				continue;
			}

		if(Is_cross(l0,l1) || Is_cross(l0,l2) || Is_cross(l0,l3) || Is_cross(l0,l4))
			cout<<"T"<<endl;
		else
			cout<<"F"<<endl;
	}
	
return 0;	
}