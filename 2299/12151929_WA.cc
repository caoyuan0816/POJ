/**
 *author@Yuan 归并排序求逆序数
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
long long arr[500005];
long long use[500005];
long long sum=0;

void merge(int a,int mid,int b){
  int i=a,j=mid+1,k=a;
  while(i<=mid && j<=b){
    if(arr[i]<=arr[j])
      use[k++]=arr[i++];
    else{
      sum+=(j-k);
      use[k++]=arr[j++];
    }
  }
  while(i<=mid)
    use[k++]=arr[i++];
  while(j<=b)
    use[k++]=arr[j++];
  for(i=a;i<=b;i++)
    arr[i]=use[i];
}

void mergeSort(int a,int b){
  if(a<b){
    int mid=(a+b)/2;
    mergeSort(a,mid);
    mergeSort(mid+1,b);
    merge(a,mid,b);
  }
}

int main(void){
  
  //freopen("in.txt","r+",stdin);

  int N;
  while(scanf("%d",&N) && N!=0){
    int i;
    for(i=0;i<N;i++){
      scanf("%d",&arr[i]);
    }
    sum=0;
    mergeSort(0,N-1);
    
    // for(i=0;i<N;i++){
    //   cout<<arr[i]<<endl;
    // }
    printf("%d\n",sum);
  }
  return 0;
}