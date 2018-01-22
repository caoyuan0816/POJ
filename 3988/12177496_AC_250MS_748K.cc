/**
 *author@Yuan
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>

#define forl(i, a, b) for(int i = (a); i <  (b); ++i)
#define forle(i, a, b) for(int i = (a); i <= (b); ++i)
#define rep(n)  for(int repp = 0; repp < (n); ++repp)
#define rst(a, v) memset(a, v, sizeof a)

using namespace std;

static int line[1010];

struct couse{
    double L;
    double R;
    bool flag;
    bool operator < (const couse& x) const {
        return R<x.R;
    }
};
couse Cou[305];

int main(void){
    //freopen("in.txt","r+",stdin);
    //ios::sync_with_stdio(false);

    int N;
    while(cin>>N && N!=0){
        rst(Cou,0);
        forl(i,0,N){
            int a,b;
            cin>>a>>b;
            Cou[i].L=a;Cou[i].R=b;Cou[i].flag=false;
        }
        sort(Cou,Cou+N);    //根据结束时间从小到大排序

        int tot,maxt=0;
        double i;
        for(i=0.0;i<5;i+=0.5){
            tot=0;
            double use=i;
            while(use<1000.0){
                forl(j,0,N){  //优先选择结束时间早的
                    if((!Cou[j].flag) && use<Cou[j].R && use>Cou[j].L){
                        tot++;Cou[j].flag=true;break;
                    }
                }
                use+=5.0;
            }
            maxt=max(maxt,tot);
            forl(j,0,N) Cou[j].flag=false;
        }
        cout<<maxt<<endl;
    }

return 0;
}
