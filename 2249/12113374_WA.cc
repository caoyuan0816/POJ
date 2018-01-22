#include <iostream>

using namespace std;

int main(void){

    long long n,k;

    while(true){

        cin>>n>>k;
        if(n==0 && k==0) break;

        long long i,use1=1,use2=1;

        if(k>n/2) k=n-k;

        for(i=n;i>n-k;i--)
            use1*=i;

        for(i=k;i>1;i--)
            use2*=i;

        cout<<use1/use2<<endl;
    }

return 0;
}
