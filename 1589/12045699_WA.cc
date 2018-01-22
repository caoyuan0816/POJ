#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

#define rep(n)  for(int               repp = 0; repp <    (n); ++repp)

using namespace std;

vector<string> dic;

void fun(int a,int l)
{
	int i;
	for(i=dic[a].length();i<l;i++)
		dic[a]+=" ";
return;	
}

int main(void)
{
	int T;
	while(cin>>T)
	{
		int i;
		rep(60)
			putchar('-');
		putchar('\n');

		int maxl=0;

		rep(T)
		{
			string use;
			cin>>use;
			if(use.length()>maxl)
				maxl=use.length();
			dic.push_back(use);
		}
		maxl+=2;
		sort(dic.begin(),dic.end());

		for(i=0;i<dic.size();i++)
			fun(i,maxl);


		int col=62/maxl;
		int hehe[col],maxr=0;
		memset(hehe,0,sizeof(hehe));
		for(i=0;i<col;i++)
		{
			if(i<dic.size()%col)
				hehe[i]++;
			hehe[i]+=dic.size()/col;
			maxr=hehe[i]>maxr?hehe[i]:maxr;
		}
		
		vector<string> ans;
		int j,m=0;
		for(i=0;i<maxr;i++)
		{
			string use;
			use.clear();
			m=0;
			if(i!=maxr-1 || dic.size()%col==0)
			{
				for(j=0;j<col;j++)
				{
					use+=dic[i+m];
					m+=hehe[j];
				}
			}
			else
			{
				for(j=0;j<dic.size()%col;j++)
				{
					use+=dic[i+m];
					m+=hehe[j];
				}
			}
			
			ans.push_back(use);
		}
		int k;
		for(i=0;i<ans.size();i++)
		{
			for(j=ans[i].length()-1;ans[i][j]==' ';j--);
			for(k=0;k<=j;k++)printf("%c",ans[i][k]);
			putchar('\n');
		}
		
		dic.clear();
	}

return 0;	
}