#include <iostream>

using namespace std;

int main(void){

    long long a,b;

    while(true){

        cin>>a>>b;
        if(a==0 && b==0) break;

        long long i,use1=1,use2=1;

        for(i=a;i>a-b;i--)
            use1*=i;

        for(i=b;i>1;i--)
            use2*=i;

        cout<<use1/use2<<endl;
    }

return 0;
}
