/*siddharth goyal*/
#include<bits/stdc++.h>
using namespace std;
#define   pb              push_back
#define   REP(i,n)        for(i=1;i<=n;i++)
#define   FOR(i,a,b)      for(i=a;i<=b;i++)
#define   all(v)          v.begin(),v.end()
#define   F               first
#define   S               second
#define   vl              vector<LL>
#define   itr             ::iterator it
#define   lb              lower_bound
#define   ub              upper_bound
#define   LL              long long
#define   ULL             unsigned long long
LL n,i,j;
int ans ;
char c[200][200] ;
int main()
{   // Read the constraints,highlights,Time Limit,Test Cases
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ;
    LL n,m ;
    cin>>n>>m ;
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  cin>>c[i][j] ;
    for(i=1;i<=n;i++)
    {   for(j=1;j<=m;j++)
        {  if(c[i][j]=='B')
           {  for(int k=j;k<m;k++)
              { if(c[i][k]=='B')  ans++ ;
                else break ;
              }
               cout<<i+ans/2<<" "<<j+ans/2<<endl ;
               return 0 ;
           }

        }
    }

}
// Check for 1,0, and other corner cases.
