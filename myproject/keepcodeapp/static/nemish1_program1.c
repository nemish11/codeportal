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

void SieveOfEratosthenes(ll n)
{
    ll prime[n+1];
    memset(prime, 1, sizeof(prime));
    for (ll p=2; p*p<=n; p++)
    {
        if (prime[p] == 1)
        {
              for (ll i=p*2; i<=n; i += p)
                prime[i] = 0;
        }
    }
    /*for (int p=2; p<=n; p++)
       if (prime[p])
          cout << p << " ";*/
}

int main()
{	
	ll t; cin>>t;
	while(t--)
	{
		
	}
	return 0;
} 
