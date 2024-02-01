#include <bits/stdc++.h>
using namespace std;
 
#define N 200010
#define K 510
#define INF 1000000020
#define INFLL 1000000000000000020
#define fi first
#define se second
#define pb push_back
#define LOG 18
#define SQRT 25
#define MOD 1000000007

typedef long long ll; 
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef vector< ll > vl;
typedef vector< pll > vll;
typedef tuple< int, int, int> tiii;
typedef tuple< ll, ll, ll> tlll;
typedef pair<double,ll> pdl;

vector<ll>grafo[N];
pll vet[N];
ll tam[N];
ll sz[N];
ll comp[N];

ll Find(ll u)
{
	if(u==comp[u])
		return u;
	return comp[u]=Find(comp[u]);
}

void Join(ll u,ll v)
{
	u=Find(u);
	v=Find(v);
	if(u==v)
		return;
	if(sz[u]>sz[v])
		swap(u,v);
	comp[u]=v;
	sz[v]+=sz[u];
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n,m,i=1,u,v,ans=1,val;

	cin >> n >> m;
	while(i<=n)
	{
		cin >> vet[i].first;
		vet[i].second=i;
		tam[i]=vet[i].first;
		comp[i]=i;
		sz[i]=1;
		i++;
	}
	while(m)
	{
		m--;
		cin >> u >> v;
		grafo[u].pb(v);
		grafo[v].pb(u);
	}
	sort(vet+1,vet+1+n);
	i=1;
	while(i<=n)
	{
		val=vet[i].first;
		u=vet[i].second;
		for(auto v : grafo[u])
		{
			if(tam[v]<val)
			{
				Join(u,v);
			}
		}
		if(sz[Find(u)]==val)
			ans=val;
		i++;
	}
	cout << ans << endl;

	return 0;
}
