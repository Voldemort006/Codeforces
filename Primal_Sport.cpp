#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
long long p[1000006];
int main()
{
	ios_base::sync_with_stdio(false);
	memset(p,-1,sizeof(p));
	long long i,j,X2,ans;
	for(i=2;i<=1000001;i++)
	{
		if(p[i]==-1)
		{
			for(j=2;j*i<=1000001;j++)
			{
				p[j*i]=i;
			}
		}
	}
	cin>>X2;
	ans=1000001;
	cout<<p[998677]<<endl;
	for(i=X2-p[X2]+1;i<=X2;i++)
	{   cout<<i<<" "<<i-p[i]+1<<endl;
		if(i-p[i]+1<ans)
			ans=i-p[i]+1;
	}
	cout<<ans<<"\n";
	return 0;
}
