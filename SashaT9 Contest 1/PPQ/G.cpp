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

ll vet[N];
 
vl di[N];

unordered_set< ll > has[N];
ll freq[N];
bool zero[N];
 
void Init()
{
 
	ll i, j;
 
	for(i = 1;i < N;i++)
		for(j = i;j < N;j += i)
			di[j].pb(i);
 
	return;
 
}

ll gcd(ll a, ll b)
{

	if(b == 0) return a;
	
	return gcd(b, a % b);

}

bool Solv(ll i, ll j)
{

	ll a = vet[i] + j;
	ll b = vet[j] + i;
	
	return (gcd(a, b) == i + j);

}

void add(ll i, ll x)
{

	freq[x]++;
	
	has[i].insert(x);
	
	return;

}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Init();

	ll n, x, y, i, j;

	ll ans = 0, q0 = 0;
	
	vll possible;

	cin >> n;

	for(i = 1;i <= n;i++)
	{

		cin >> vet[i];

		x = vet[i] - i;

		if(x < 0) continue;

		if(x == 0)
		{

			ans += q0;
			ans += freq[i];

			zero[i] = true;
			q0++;
			
			continue;

		}

		for(auto d : di[x])
		{

			y = d - i;

			if(y < 1) continue;
			if(n < y) continue;

			if(has[y].find(i) != has[y].end() || zero[y] == true) 
				possible.pb({y, i});

			add(i, y);

		}

	}
	
	for(auto cur : possible)
		ans += Solv(cur.fi, cur.se);

	cout << ans << endl;

	return 0;
}
