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

double dist[N];
priority_queue<pdl , vector<pdl> , greater<pdl> >fila;
vector<pdl>grafo[N];

void Dijkstra(ll pos)
{
	dist[pos]=0;
	fila.push({dist[pos],pos});
	ll u,v;
	double d,w;
	while(!fila.empty())
	{
		d=fila.top().first;
		u=fila.top().second;
		fila.pop();
		if(dist[u]!=d)
			continue;
		for(auto arr : grafo[u])
		{
			w=arr.first;
			v=arr.second;
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				fila.push({dist[v],v});
			}
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n,m,u,v;
	double w;

	cin >> n >> m;
	while(m)
	{
		m--;
		cin >> u >> v >> w;
		w=log(w)/log(7);
		grafo[u].pb({w,v});
		grafo[v].pb({w,u});
	}
	for(u=1;u<=n;u++)
	{
		dist[u]=INF;
	}
	Dijkstra(1);
	cout << setprecision(8) << fixed;
	cout << dist[n] << endl;

	return 0;
}
