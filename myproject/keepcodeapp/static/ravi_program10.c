#include<bits/stdc++.h>
using namespace std;
#define SI(x) scanf("%d",&x);
#define SLL(x) scanf("%lld",&x)
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define ll  long long int 
#define F first
#define S second
#define REP(a,b,c) for(int i=a;i<b;i+=c)
#define boost ios_base::sync_with_stdio(false),cin.tie(NULL);
#define ALL(x) (x).begin(),(x).end()
const int MOD = 1000000007;

set<ll> divisor(ll n)
{
    set<ll> v;
    for (ll i=1; i<=sqrt(n); i++)
    {
        if (n%i==0)
        {
            if (n/i == i) 
                v.insert(i);
            else
            {
                v.insert(i);
                v.insert(n/i);
            }
        }
    }
  return v;   
}

int main()
{	
	ll t; cin>>t;
	while(t--)
	{
		
	}
	return 0;
} 
