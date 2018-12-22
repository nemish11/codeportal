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
ll const N=100001;
vector<pair<ll,ll> >dsj;
void clear1()
{
	dsj.clear();
	for(ll i=0;i<N;i++)
	{
		dsj.PB(MP(i,0));
	}
}

ll find(ll i)
{
    if (dsj[i].F != i)
        dsj[i].F = find(dsj[i].F);
    return dsj[i].F;
}

void Union(ll x,ll y)
{
    ll xroot = find(x);
    ll yroot = find(y);
    if (dsj[xroot].S < dsj[yroot].S)
        dsj[xroot].F = yroot;
    else if (dsj[xroot].S > dsj[yroot].S)
        dsj[yroot].F = xroot;
    else
    {
        dsj[yroot].F = xroot;
        dsj[xroot].S++;
    }
}

void find_mst(ll n,ll m)
{
	priority_queue<pair<ll,pair<ll,ll> > ,vector<pair<ll,pair<ll,ll> > >,greater<pair<ll,pair<ll,ll> > > >pq;

	for(ll i=0;i<m;i++)
	{
		ll x,y,w; cin>>x>>y>>w;
		//ll x,y,w; cin>>x>>y; w=1;
		pq.push(MP(w,MP(x,y)));
	}
	ll count = 1,cost=0;
	while(count<n)
	{
		pair<ll,pair<ll,ll> >u = pq.top(); pq.pop();
		ll x = find(u.S.F);
        ll y = find(u.S.S);
        if (x != y)
        {
            cost+=u.F;
            Union(x, y);
            count++;
        }
	}
	cout<<cost<<endl;
}
int main()
{
	ll t; cin>>t;
	while(t--)
	{
		clear1();
		ll n; cin>>n;
		ll m; cin>>m;
		find_mst(n,m);
	}
	return 0;
}
