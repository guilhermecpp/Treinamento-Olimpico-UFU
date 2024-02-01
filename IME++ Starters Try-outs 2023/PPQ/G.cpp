#include <bits/stdc++.h>
using namespace std;
 
#define N 100010
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

typedef struct Edge
{

	ll u, v, w;

	bool operator < (Edge other) const
	{

		return w < other.w;

	}

}Ed;

vector< Ed > edges;
ll pai[N];
ll tam[N];

vector< ll > grafo[N];

ll findPai(ll u)
{

	if(u == pai[u]) return u;

	return pai[u] = findPai(pai[u]);

}

bool Join(ll u, ll v)
{

	u = findPai(u);
	v = findPai(v);

	if(u == v) return false;

	if(tam[u] < tam[v]) swap(u, v); // u eh maior
	
	pai[v] = u;
	tam[u] += tam[v];

	return true;

}

pll DFS(ll u, ll p, ll d)
{

	pll ans = {u, d};

	for(auto v : grafo[u])
	{

		if(v == p) continue;

		pll aux = DFS(v, u, d + 1);

		if(ans.second < aux.second)	ans = aux;

	}

	return ans;

}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, m, u, v, w, a, b, r1, r2, i;

	cin >> n >> m;

	for(i = 0;i < m;i++)
	{

		cin >> u >> v >> w;

		edges.pb({u, v, w});

	}

	sort(edges.begin(), edges.end());

	for(i = 1;i <= n;i++) pai[i] = i;
	for(i = 1;i <= n;i++) tam[i] = 1;

	r1 = 0;

	for(i = 0;i < m;i++)
	{

		u = edges[i].u;
		v = edges[i].v;
		w = edges[i].w;

		if(Join(u, v) == false) continue;

		grafo[u].pb(v);
		grafo[v].pb(u);
		r1 += w;
	
	}

	pll aux = DFS(1, 1, 0);

	r2 = DFS(aux.first, aux.first, 0).second;

	cout << r1 << endl;
	cout << r2 << endl;

	return 0;
}
