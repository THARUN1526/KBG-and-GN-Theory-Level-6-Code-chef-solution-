#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b)
{
    if((a%b)==0){
        return b;
    }else{
        return gcd(b, a%b);
    }
}
ll count(ll a, ll p[])
{
    ll ans=0;
    while(a>1)
    {
        ans+=p[a];
        a=a/p[a];
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t, n, i, j, ans, q, u, v, lcm, a, b;
    ll p[100001];
    
    for(i=0; i<=100000; i++)
    {
        p[i]=i;
    }
    
    
    for(i=2; i<=100000; i++)
    {
        if(p[i]==i){
            for(j=i*i; j<=100000; j+=i)
            {
                if(p[j]==j){
                    p[j]=i;
                }
            }
        }
    }
    
    cin>>t;
    
    for(;t--;)
    {
        cin>>n>>q;
        
        for(;q--;)
        {
            cin>>a>>b;
            
            if(a>b){
                swap(a, b);
            }
            
            if((b%a)==0){
                ans=count(b/a, p);
                //cout<<b/a<<" ";
            }else{
                lcm=(a*b)/gcd(b, a);
                ans=count(lcm/a, p)+count(lcm/b, p);
                //cout<<lcm/a<<" "<<lcm/b<<" ";
            }
            
            cout<<ans<<"\n";
            
        }
    }
    
}