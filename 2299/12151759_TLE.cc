/**
 *author@Yuan
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
long long arr[500005];
int main(void){
  
  //freopen("in.txt","r+",stdin);

  int N;
  while(cin>>N && N!=0){
    int i;
    for(i=0;i<N;i++){
      cin>>arr[i];
    }
    
    long long sum=0,use;int j;
    for(i=0;i<N-1;i++){
      for(j=0;j<N-1;j++){
	if(arr[j]>arr[j+1]){
	  use=arr[j];
	  arr[j]=arr[j+1];
	  arr[j+1]=use;
	  sum++;
	}
      }
    }
    // for(i=0;i<N;i++){
    //  cout<<arr[i]<<endl;
    // }
    
    cout<<sum<<endl;
    
  }
  return 0;
}
