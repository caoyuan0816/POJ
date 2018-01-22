#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct node{
    string str;
    int num;
    node(string s,int n){
        str=s;
        num=n;
    }
};

int fun(string s){
    int i,a=0,c=0,g=0,t=0,num=0;
    for(i=0;i<s.length();i++){
        switch(s[i]){
        case 'A':
            a++;
            num=num+c+g+t;
            break;
        case 'C':
            c++;
            num=num+g+t;
            break;
        case 'G':
            g++;
            num=num+t;
            break;
        case 'T':
            t++;
            break;
        }
    }
return num;
}

vector<node> strs;

int main(void){
    int n,m,T;
    string use;
    cin>>n>>m;
    T=m;

    while(T--){
        cin>>use;
        node temp = node(use,fun(use));
        strs.push_back(temp);
    }

    int i,j;
    for(i=0;i<m-1;i++){
        for(j=0;j<m-1;j++){
            if(strs[j].num>strs[j+1].num)
                swap(strs[j],strs[j+1]);
        }
    }

    for(i=0;i<m;i++) cout<<strs[i].str<<endl;

return 0;
}
