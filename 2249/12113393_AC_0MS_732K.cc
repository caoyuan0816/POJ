#include <iostream>

using namespace std;

int main(void){

    long long n,k;

    while(true){

        cin>>n>>k;
        if(n==0 && k==0) break;

        long long i,ans=1;

        if(k>n/2) k=n-k;

        for(i=n;i>n-k;i--)
            ans=ans*i/(n-i+1);

        cout<<ans<<endl;
    }

return 0;
}
