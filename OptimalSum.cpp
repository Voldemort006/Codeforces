/*siddharth goyal*/
//WARNING : DANGER AHEAD
//NOBODY CAN UNDERSTAND THIS CODE
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
LL n,i,j,ans = 0,k;
LL sumpos = 0,sumneg = 0 ;
LL WMpos,WMneg,total_sum_pos = 0,total_sum_neg = 0 ;
LL cWMpos = 0,cWMneg = 0 ;
multiset <LL> Mpos,Mneg ;
LL a[1000000] ;
void add(LL x,LL y)
{  if(y==1)
   {  total_sum_pos += x;
      Mpos.insert(x) ;
      if(Mpos.size()<=k) sumpos += x,WMpos = *Mpos.begin(),cWMpos = Mpos.count(WMpos);
      else
      {  if(x>WMpos)
         {  sumpos += x - WMpos ;
            if(cWMpos==1) WMpos = *Mpos.lb(WMpos+1),cWMpos = Mpos.count(WMpos) ;
            else cWMpos-- ;
          }
      }
    }
    else
    {  total_sum_neg += x ;
       Mneg.insert(x) ;
       if(Mneg.size()<=k)  sumneg += x,WMneg = *Mneg.begin(),cWMneg = Mneg.count(WMneg) ;
       else
       {  if(x>WMneg)
          {  sumneg += x - WMneg ;
             if(cWMneg==1) WMneg = *Mneg.lb(WMneg+1),cWMneg = Mneg.count(WMneg) ;
             else cWMneg-- ;
          }
       }
    }
}
void rem(LL val,LL y)
{  if(y==1)
   {  total_sum_pos -= val ;
      if(val<WMpos) Mpos.erase(Mpos.find(val));
      else if(val==WMpos)
      {  LL x = Mpos.count(val) ;
         if(x>cWMpos) Mpos.erase(Mpos.find(val)) ;
         else
         { if(*Mpos.begin()==val)
           {  Mpos.erase(Mpos.begin()),sumpos -= val ;
              cWMpos-- ;
              if(cWMpos==0)  WMpos = *Mpos.begin(),cWMpos = Mpos.count(WMpos) ;
           }
           else
           {  auto it = Mpos.find(val) ;
              sumpos -= val ;
              it-- ;
              WMpos = *it,cWMpos = 1,sumpos += WMpos,Mpos.erase(Mpos.find(val)) ;
           }
         }//end of else
      }//end of else if
      else
      {  Mpos.erase(Mpos.find(val)),sumpos -= val ;
         LL x = Mpos.count(WMpos) ;
         if(x>cWMpos)
         {  cWMpos++ ;
            sumpos += WMpos ;
         }
         else
         {  if(*Mpos.begin()!=WMpos)
            {  auto it = Mpos.find(WMpos) ;
               it-- ;
               sumpos += *it ;
               WMpos = *it ;
               cWMpos = 1 ;
            }
         }
      }
      return ;
   }//end of  y==1
   //---------------------------------------------------------------------------------------------------------------
   total_sum_neg -= val ;
   if(val<WMneg) Mneg.erase(Mneg.find(val));
   else if(val==WMneg)
   {  LL x = Mneg.count(val) ;
      if(x>cWMneg) Mneg.erase(Mneg.find(val)) ;
      else
      { if(*Mneg.begin()==val)
        {  Mneg.erase(Mneg.begin()),sumneg -= val ;
           cWMneg-- ;
           if(cWMneg==0)  WMneg = *Mneg.begin(),cWMneg = Mneg.count(WMneg) ;
         }
         else
         {  auto it = Mneg.find(val) ;
            sumneg -= val ;
            it-- ;
            WMneg = *it,sumneg += WMneg,cWMneg = 1,Mneg.erase(Mneg.find(val)) ;
         }
       }//end of else
    }//end of else if
    else
    {  Mneg.erase(Mneg.find(val)),sumneg -= val ;
       LL x = Mneg.count(WMneg) ;
       if(x>cWMneg)
       {  cWMneg++ ;
          sumneg += WMneg ;
       }
       else
       {  if(*Mneg.begin()!=WMneg)
          {  auto it = Mneg.find(WMneg) ;
             it-- ;
             sumneg += *it ;
             WMneg = *it ;
             cWMneg = 1 ;
           }
        }
    }
}
int main()
{   // Read the constraints,highlights,Time Limit,Test Cases
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL len ;
    cin>>n>>len ;
    LL pos = 0,neg = 0 ;
    REP(i,n)
    { cin>>a[i] ;
      if(a[i]>0) pos++ ;
      else if(a[i]<0) neg++ ;
    }
    cin>>k ;
    if(!k)
    {  j = len ;
       partial_sum(a+1,a+1+n,a+1) ;
       REP(i,n)
       { if(j>n)  break;
         ans = max(ans,abs(a[j]-a[i-1])) ;
         j++;
       }
       cout<<ans ;
       exit(0) ;
    }
    else if(k==n or k>=pos or k>=neg)
    {  j = len ;
       REP(i,n) a[i] = abs(a[i]) ;
       partial_sum(a+1,a+1+n,a+1)  ;
       REP(i,n)
       {  if(j>n)  break ;
          ans = max(ans,a[j]-a[i-1]) ;
          j++ ;
       }
       return cout<<ans,0 ;
    }
    else
    {  for(i=1;i<=len;i++)
       {  if(a[i]>0)
           add(a[i],1);
          else if(a[i]<0)
           add(-a[i],-1) ;
       }
       j = len ;

       for(i=1;i<=n;i++)
       {  if(j>n)  break;
          //cout<<total_sum_neg<<" "<<sumneg<<endl;
          ans = max(ans,max(total_sum_pos+2*sumneg - total_sum_neg,total_sum_neg+2*sumpos-total_sum_pos)) ;
          //remove a[i] ;
          if(a[i]>0) rem(a[i],1) ;
          if(a[i]<0) rem(-a[i],-1) ;
          j++ ;
          //add a[j]
          if(a[j]>0) add(a[j],1) ;
          else if(a[j]<0) add(-a[j],-1) ;
       }//end of for
       cout<<ans;
    }
}
// Check for 1,0, and other corner cases.
