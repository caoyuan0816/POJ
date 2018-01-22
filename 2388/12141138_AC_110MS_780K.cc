/**
 *author@Yuan
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[10000];

int main(void){

  //freopen("in.txt","r+",stdin);
  int N;

  cin>>N;
  int i;
  for(i=0;i<N;i++){
    cin>>arr[i];
  }
  sort(arr,arr+N);
  
  cout<<arr[N/2]<<endl;

  return 0;
}