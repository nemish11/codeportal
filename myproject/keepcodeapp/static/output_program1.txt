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

void factorize(ll n) 
{ 
    ll count = 0;   
    while (!(n % 2)) { 
        n/=2;
        count++; 
    } 
    if (count) 
        cout << 2 << "  " << count << endl; 
    for (ll i = 3; i <= sqrt(n); i += 2) { 
        count = 0; 
        while (n % i == 0) { 
            count++; 
            n = n / i; 
        } 
        if (count) 
            cout << i << "  " << count << endl; 
    }  
    if (n > 2) 
        cout << n << "  " << 1 << endl; 
} 

int main()
{	
	ll t; cin>>t;
	while(t--)
	{
		
	}
	return 0;
} 
