#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
#define INF 999999;
#define pb push_back

#define DBG 0
#define sz(c) ((int)(c).size())
#define    forl(i, a, b) for(int i = (a); i <  (b); ++i)
#define   forle(i, a, b) for(int i = (a); i <= (b); ++i)
#define    forg(i, a, b) for(int i = (a); i >  (b); --i)
#define   forge(i, a, b) for(int i = (a); i >= (b); --i)
#define   forlc(i, a, b) for(int i##_b = (b), i = (a); i <  i##_b; ++i)
#define  forlec(i, a, b) for(int i##_b = (b), i = (a); i <= i##_b; ++i)
#define   forgc(i, a, b) for(int i##_b = (b), i = (a); i >  i##_b; --i)
#define  forgec(i, a, b) for(int i##_b = (b), i = (a); i >= i##_b; --i)
#define  forall(i, v   )  forl(i, 0, sz(v))
#define forallc(i, v   ) forlc(i, 0, sz(v))
#define  forlla(i, v   ) forge(i, sz(v)-1, 0)
#define   forls(i, n, a, b) for(int i = a; i != b; i = n[i])
#define rep(n)  for(int               repp = 0; repp <    (n); ++repp)
#define repc(n) for(int repp_b = (n), repp = 0; repp < repp_b; ++repp)
#define rst(a, v) memset(a, v, sizeof a)
#define cpy(a, b) memcpy(a, b, sizeof a)
#define rstn(a, v, n) memset(a, v, (n)*sizeof((a)[0]))
#define cpyn(a, b, n) memcpy(a, b, (n)*sizeof((a)[0]))
#define ast(b) if(DBG && !(b)) { printf("%d!!|\n", __LINE__); while(1) getchar(); }
#define dout DBG && cout << __LINE__ << ">>| "
#define pr(x) #x"=" << (x) << " | "
#define mk(x) DBG && cout << __LINE__ << "**| "#x << endl
#define pra(arr, a, b) if(DBG) { \
    dout<<#arr"[] | "; \
    forlec(i, a, b) cout<<"["<<i<<"]="<<arr[i]<<" |"<<((i-(a)+1)%13?" ":"\n"); \
    if(((b)-(a)+1)%13) puts(""); \
  }
#define rd(type, x) type x; cin >> x
inline int     rdi() { int d; scanf("%d", &d); return d; }
inline char    rdc() { scanf(" "); return getchar(); }
inline string  rds() { rd(string, s); return s; }
inline double rddb() { double d; scanf("%lf", &d); return d; }
template<class T> inline bool updateMin(T& a, T b) { return a>b? a=b, true: false; }
template<class T> inline bool updateMax(T& a, T b) { return a<b? a=b, true: false; }

static int arcs[1050][1050];
static int d[2000];
static int S[2000];

int main(void)
{
	int T,N,i,j;

	scanf("%d%d",&T,&N);

	forle(i,1,N)
	{
		forle(j,1,N)
		{
			arcs[i][j]=INF;
		}
	}

	int v1,v2,w;
	rep(T)
	{
		scanf("%d%d%d",&v1,&v2,&w);
		arcs[v1][v2]=min(arcs[v1][v2],w);
		arcs[v2][v1]=arcs[v1][v2];
	}

	//d[1]=0;
	forle(i,1,N)
	{
		d[i]=arcs[1][i];
		S[i]=0;
	}

	int Vu,use;
	S[1]=1;

	rep(N-1)						//dijkstra算法求最短路
	{
		use=INF;					//arcs[][]存储权值
									//d[]存储源节点(此题为1)到各结点最短路
									//S[]用于存储此在dijkstra过程中是否已被标记最短
		forle(j,2,N)				
		{
			if(S[j]!=1 && d[j]<use)
			{
				use=d[j];
				Vu=j;
			}
		}

		S[Vu]=1;

		forle(j,2,N) 
		{
			if(S[j]!=1)
			{
				d[j]=min(d[Vu]+arcs[Vu][j],d[j]);
			}
		}
	}

	cout<<d[N]<<endl;

	/*forle(i,1,N)
	{
		forle(j,1,N)
		{
			printf("%10d  ",arcs[i][j]);
		}
		cout<<endl<<endl;
	}
	forle(i,1,N)
		cout<<d[i]<<"  ";
	cout<<endl;*/
return 0;
}