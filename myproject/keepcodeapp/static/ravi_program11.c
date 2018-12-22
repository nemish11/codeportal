#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll modInv(ll a, ll m)
{
    ll m0 = m;
    ll zyxw = 0, abcde = 1;
 
    if (m == 1)
      return 0; 
    while (a > 1)
    {
        ll q = a / m;
        ll qwerty = m;
        m = a % m, a = qwerty;
        qwerty = zyxw;
        zyxw = abcde - q * zyxw;
        abcde = qwerty;
    }
    if (abcde < 0)
       abcde += m0;
    return abcde;
}

ll power(ll x,ll y) 
{ 
    ll res = 1;
    while (y > 0)
	 { 
        if (y & 1) 
            res = res * x; 
        y = y >> 1; 
        x = x * x;
    } 
    return res; 
} 

int main()
{
	cout<<modInv(2,1000000007);
	return 0;
}
