#include <bits/stdc++.h>
using namespace std;
 
#define NMAX 100010
#define PMAX 1000010
#define INF 8000000000000000000
#define fi first
#define se second
#define pb push_back
//#define endl '\n'
 
typedef long long ll;
typedef pair< ll, ll > pll;
typedef vector< ll > vl;
typedef vector< pll > vll;

typedef struct Constraints
{

	ll t, i, j, x;

}Co;

vll grafo[NMAX];
vl forb[NMAX];

ll tempo = 0;
ll passed[NMAX];

ll ans[NMAX];

set< ll > non;

vector< Co > cons;

void Solv(ll u, ll x)
{

	passed[u] = tempo;
	ans[u] = x;

	for(auto cur : forb[u])
		non.insert(cur ^ x);

	for(auto [v, w] : grafo[u])
		if(passed[v] != tempo)
			Solv(v, x ^ w);

	return;

}
 
int main()
{
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll tt, n, m, t, u, v, x, i;

	cin >> tt;

	while(tt--)
	{

		cin >> n >> m;

		for(i = 0;i < m;i++)
		{

			cin >> t;

			if(t == 1) 
			{
				
				cin >> u >> x;

				forb[u].pb(x);
			
			}
			else
			{
				
				cin >> u >> v >> x;

				grafo[u].pb({v, x});
				grafo[v].pb({u, x});

			}

			cons.pb({t, u, v, x});

		}

		for(i = 1;i <= n;i++) ans[i] = -1;

		for(i = 1;i <= n;i++)
		{
			
			if(ans[i] != -1) continue;

			tempo++;
			Solv(i, 0);

			x = 0;
			while(non.find(x) != non.end()) x++;

			tempo++;
			Solv(i, x);

			non.clear();

		}

		bool possible = true;

		for(auto [t, u, v, x] : cons)
		{

			if(t == 1)
			{

				if(ans[u] == x) 
					possible = false;
				
			}else
			{

				if((ans[u] ^ ans[v]) != x)
					possible = false;

			}

		}

		if(possible == true)
		{

			cout << "YES" << endl;

			for(i = 1;i <= n;i++) cout << ans[i] << " ";
			cout << endl;

		}else
		{

			cout << "NO" << endl;

		}

		cons.clear();
		for(i = 1;i <= n;i++) forb[i].clear();
		for(i = 1;i <= n;i++) grafo[i].clear();

	}
	
    return 0;
    
}
