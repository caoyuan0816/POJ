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
#define pb push_back
#define INF 5;

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

static int arcs[200][200];
static int dist[500];
static int S[500];

int main(void)
{
	int N,A,B,i,j;

	scanf("%d%d%d",&N,&A,&B);

	forle(i,1,N)
	{
		forle(j,1,N)
		{
			arcs[i][j]=INF;
		}
	}

	forle(i,1,N)
	{
		int M,a;
		scanf("%d",&M);
		scanf("%d",&a);
			arcs[i][a]=0;
		rep(M-1)
		{
			scanf("%d",&a);
			arcs[i][a]=1;
		}
	}

	forle(i,1,N)
	{
		if(i!=A)
		{
			dist[i]=arcs[A][i];
			S[i]=0;
		}
		else
		{
			dist[i]=0;
			S[i]=1;
		}
	}

	rep(N-1)
	{
		int Vu,use=INF;
		forle(i,1,N)
		{
			if(dist[i]<use && S[i]!=1)
			{
				use=dist[i];
				Vu=i;
			}
		}

		S[Vu]=1;
		
		forle(i,1,N)
		{
			if(S[i]!=1)
			{
				dist[i]=min(dist[i],dist[Vu]+arcs[Vu][i]);
			}
		}
	}

	cout<<dist[B]<<endl;


	/*forle(i,1,N)
	{
		forle(j,1,N)
		{
			cout<<arcs[i][j]<<"  ";
		}cout<<endl;
	}*/
return 0;	
}