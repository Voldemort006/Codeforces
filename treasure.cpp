//////////////
/*Author - siddharth goyal
Date - 29-08-18*/
/////////////
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
vl ans ;
vector <pair<LL,LL> > v ;
int main()
{   // Read the constraints,highlights,Time Limit,Test Cases
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ;
    string s ;
    cin>>s ;
    LL c = 0 ;
    //if(s[0]=='#')  return cout<<-1,0 ;
    for(i=0;s[i];i++)
    {  if(s[i]=='(')  c++ ;
       else
       {  if(s[i]=='#')
          {  if(c!=0)
             { ans.pb(c) ;
               if(c>1) v.pb({c,(LL)ans.size()-1LL});
             }
             else
             {  if(v.size()==0)  return cout<<-1,0 ;
                pair<LL,LL> p = v[(LL)v.size()-1LL] ;
                p.F-- ;
                ans.pb(1LL) ;
                ans[p.S] = p.F ;
                v.pop_back() ;
                if(p.F>1)  v.pb({p.F,p.S}) ;

             }
             c = 0 ;
          }
          else
          {  if(c) c-- ;
             else
             {   if(v.size()==0) return cout<<-1,0 ;
                 pair<LL,LL> p = v[(LL)v.size()-1] ;
                 p.F-- ;
                 ans[p.S] = p.F ;
                 v.pop_back() ;
                 if(p.F>1)  v.pb({p.F,p.S}) ;
             }
          }
       }
    }
    if(c)  return cout<<-1,0 ;
    for(auto i:ans)  cout<<i<<endl;

}
// Check for 1,0, and other corner cases.
