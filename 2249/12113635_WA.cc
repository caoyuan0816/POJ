#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;


int lnchoose(int n, int m) { ///求组合数C(n,m)(注意:n>=m);
    if (m < n/2.0) {
        m = n-m;
    }
    double s1 = 0;
    for (int i=m+1; i<=n; i++) {
        s1 += log((double)i);
    }
    double s2 = 0;
    int ub = n-m;
    for (int i=2; i<=ub; i++) {
        s2 += log((double)i);
    }
    return exp(s1-s2);
}
int main() {
    while(1) {
        int n,m;
        if(n==0 && m==0) break;
        double sum=0;
        scanf("%d%d",&n,&m);
        if(n>=m) {
            sum=lnchoose(n, m);
        }
        printf("%.lf\n",sum);
    }
    return 0;
}
