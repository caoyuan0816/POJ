#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
#define pb push_back
#define INF 99999999;

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

struct Node{
	map<int,int> M;
};

static Node arcs[30001];
static int dist[30005];
static int S[30005];

int main(void)
{
	int N,M,i,j;

	scanf("%d%d",&N,&M);

	rep(M)
	{
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		arcs[a].M[b]=w;
	}

	int ha;
	forle(i,1,N)
	{
		if(arcs[1].M.find(i)==arcs[1].M.end())
			{ha=INF;}
		else
			{ha=arcs[1].M[i];}
		dist[i]=ha;
		S[i]=0;
	}
	dist[1]=0;S[1]=1;

	rep(N-1)
	{
		int Vu=1,use=INF;
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
				if(arcs[Vu].M.find(i)==arcs[Vu].M.end())
					{ha=INF;}
				else
					{ha=arcs[Vu].M[i];}
				dist[i]=min(dist[i],dist[Vu]+ha);
			}
		}
	}

	int maxx=-99999999,minn=99999999;
	forle(i,1,N)
	{
		maxx=max(dist[i],maxx);
		minn=min(dist[i],minn);
	}

	cout<<maxx-minn<<endl;

return 0;	
}