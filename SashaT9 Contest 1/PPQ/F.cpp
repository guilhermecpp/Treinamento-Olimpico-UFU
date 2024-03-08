#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
#define N 200010
#define K 30
#define INF 1000000020
#define INFLL 1000000000000000020
#define fi first
#define se second
#define pb push_back
#define LOG 18
#define SQRT 32000
#define MOD 1000000007
//#define ordered_set tree<pair<int,int>,null_type,less< pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update>

typedef long long ll; 
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef vector< ll > vl;
typedef vector< pll > vll;
typedef tuple< int, int, int> tiii;
typedef tuple< ll, ll, ll> tlll;

vl grafo[N];

pll best;

void DFS(ll u, ll pai, ll d)
{

	best = max(best, {d, u});

	for(auto v : grafo[u])
	{

		if(v == pai) continue;

		DFS(v, u, d + 1);

	}

	return;

}

ll Diameter()
{

	ll u;

	u = 1;
	best = {-1, -1};
	DFS(u, u, 0);

	u = best.se;
	best = {-1, -1};
	DFS(u, u, 0);

	return best.fi;

}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, u, v, i, j;

	vl ans;

	for(j = 0;j < 2;j++)
	{

		cin >> n;

		for(i = 1;i < n;i++)
		{

			cin >> u >> v;

			grafo[u].pb(v);
			grafo[v].pb(u);

		}

		ans.pb(Diameter());

		for(i = 1;i <= n;i++) grafo[i].clear();

	}

	ll a = ans[0];
	ll b = ans[1];
	ll resp = -INF;

	resp = max(resp, a);
	resp = max(resp, b);

	a = (a + 1) / 2; // Ceil
	b = (b + 1) / 2; // Ceil

	resp = max(resp, a + b + 1);

	cout << resp << endl;

	return 0;
}
