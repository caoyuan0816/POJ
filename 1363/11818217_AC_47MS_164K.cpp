#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

static int num[1020];
static int kk=0,ll=0;

int main(void)
{
while(1){
	
	int N,i,j,k;

	vector<int> sta;

	scanf("%d",&N);

	if(N==0)
		return 0;

	while(1){
		

	scanf("%d",&num[0]);

	if(num[0]==0)
		break;
			

	for(i=1;i<N;i++)
	{
		scanf("%d",&num[i]);
	}
	
	i=1;k=0,j=0;
	while(i<=N)
	{
		sta.push_back(i++);
		
		while(sta[k]==num[j])
		{
			sta.pop_back();
			j++;
			k--;
		}k++;
	}
	//if(ll!=0)
		//putchar('\n');
	if(sta.size()==0)
		printf("Yes\n");
	else
		printf("No\n");
	sta.clear();
	}ll++;putchar('\n');

}



return 0;	
}