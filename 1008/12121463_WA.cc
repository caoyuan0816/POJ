#include <iostream>
#include <stdio.h>

using namespace std;

string map[20]={"","pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
string map2[21]={"","imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int getMonth(string month){
    int i;
    for(i=1;i<=20;i++)
        if(map[i]==month)
            return i;
}

int main(void){
    int T;
    cin>>T;
    while(T--){
        int day;string month;int year;
        cin>>day;getchar();cin>>month>>year;
        int sum=0;
        sum=day+1+((getMonth(month)-1)*20)+year*365;
        int a,b,c;
        a=sum%13;b=sum%20;c=sum/260;
        if(a==0) a=13;
        if(b==0) b=20;
        if(sum%260==0) c--;

        cout<<a<<" "<<map2[b]<<" "<<c<<endl;

    }

return 0;
}
