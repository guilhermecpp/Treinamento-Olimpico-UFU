#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
#define N 1000010
#define K 100
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
ll me[N];
ll ma[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, x, ans, i;

	cin >> n;

	for(i = 1;i <= n;i++) cin >> vet[i];


	ma[0] = -INF;
	for(i = 1;i <= n;i++) 
		ma[i] = max(ma[i - 1], vet[i]);

	me[n + 1] = INF;
	for(i = n;i >= 1;i--) 
		me[i] = min(me[i + 1], vet[i]);

	ans = 0;

	for(i = 1;i <= n;i++)
	{

		ans += vet[i];

		if(vet[i] != i) continue;
		if(ma[i] != i) continue;
		if(me[i] != i) continue;

		ans -= vet[i];

	}

	cout << ans << endl;

	return 0;
}
