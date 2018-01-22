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
#define INF 999999;

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

static int arcs[1005][1005];
static int dist[2000];
static int S[2000];

int main(void)
{
	int N,K,i,j;
	scanf("%d%d",&N,&K);

	forle(i,1,K)
	{
		forle(j,1,K)
		{
			arcs[i][j]=INF;
		}
	}

	rep(N)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		arcs[a][b]=1;
	}

	dist[1]=0;S[1]=1;
	forle(i,2,K)
	{
		dist[i]=arcs[1][i];
		S[i]=0;
	}

	int pre[2000];
	rep(K-1)
	{
		int Vs=1,use=INF;

		forle(i,2,K)
		{
			if(S[i]!=1 && dist[i]<use)
			{
				use=dist[i];
				Vs=i;
			}
		}

		S[Vs]=1;

		forle(i,2,K)
		{
			if(S[i]!=1)
			{
				if(dist[i]>dist[Vs]+arcs[Vs][i])
				{
					dist[i]=dist[Vs]+arcs[Vs][i];
					pre[i]=Vs;
				}
			}
		}

	}

	if(dist[K]==999999)
	{
		cout<<"-1"<<endl;
		return 0;
	}

	cout<<dist[K]+1<<endl<<"1"<<endl;

	int tmp=pre[K],L=0,ans[2000];

	while(tmp!=0)
	{
		ans[L++]=tmp;
		tmp=pre[tmp];
	}

	forge(i,L-1,0)
	{
		printf("%d\n",ans[i]);
	}
	printf("%d\n",K);

return 0;	
}