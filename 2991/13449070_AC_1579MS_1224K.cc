#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define lson i<<1
#define rson i<<1|1
#define lc l,mid,i<<1
#define rc mid+1,r,i<<1|1
const int L = 100000+10;
const double pi = acos(-1.0);

struct node
{
    double x,y;
    int deg;
    int flag;
} a[L<<2];

double set(int x)
{
    return x*pi/180;
}

void work(int i,int deg)//求新坐标公式
{
    double r = set(deg);
    double x = a[i].x;
    double y = a[i].y;
    a[i].x = x*cos(r)-y*sin(r);
    a[i].y = x*sin(r)+y*cos(r);
    a[i].deg = (a[i].deg+deg)%360;
}

void pushup(int i)
{
    a[i].x = a[lson].x+a[rson].x;
    a[i].y = a[lson].y+a[rson].y;
}

void pushdown(int i)
{
    if(a[i].flag)
    {
        work(lson,a[i].flag);
        work(rson,a[i].flag);
        a[lson].flag+=a[i].flag;
        a[rson].flag+=a[i].flag;
        a[i].flag = 0;
    }
}

void init(int l,int r,int i)
{
    a[i].x = a[i].y = 0;
    a[i].flag = a[i].deg = 0;
    if(l == r)
    {
        scanf("%lf",&a[i].y);
        return;
    }
    int mid = (l+r)>>1;
    init(lc);
    init(rc);
    pushup(i);
}

void insert(int l,int r,int i,int L,int R,int z)
{
    if(L<=l && r<=R)
    {
        work(i,z);
        a[i].flag+=z;
        return ;
    }
    pushdown(i);
    int mid = (l+r)>>1;
    if(L<=mid)
        insert(lc,L,R,z);
    if(R>mid)
        insert(rc,L,R,z);
    pushup(i);
}

int query(int l,int r,int i,int x)
{
    if(l == r)
        return a[i].deg;
    pushdown(i);
    int mid = (l+r)>>1;
    if(x<=mid)
        return query(lc,x);
    else
        return query(rc,x);
}
int main()
{
    int n,m,x,y,flag = 1,i,j;
    while(~scanf("%d%d",&n,&m))
    {
        init(0,n-1,1);
        if(!flag)
            printf("\n");
        flag = 0;
        while(m--)
        {
            scanf("%d%d",&x,&y);
            int deg;
            deg  = query(0,n-1,1,x-1)+180+y-query(0,n-1,1,x);//由于题目是逆时针转的，我的计算是顺时针，要加上180度,将后面的棒看成依然在Y轴，所以要减去后一个的角度
            insert(0,n-1,1,x,n-1,deg);
            printf("%.2f %.2f\n",a[1].x,a[1].y);
        }
    }

    return 0;
}
