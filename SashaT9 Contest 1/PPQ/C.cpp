#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
#define N 200010
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

vl di[N];

ll freq[N];
ll ans[N];

void Init()
{

	ll i, j;

	for(i = 1;i < N;i++)
		for(j = i;j < N;j += i)
			di[j].pb(i);

	return;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Init();
	
	ll n, x, i;

	cin >> n;

	for(i = 0;i < n;i++)
	{

		cin >> x;

		for(auto d : di[x])
			freq[d]++;

	}

	for(i = 1;i < N;i++)
		ans[freq[i]] = i;

	for(i = n - 1;i >= 1;i--)
		ans[i] = max(ans[i], ans[i + 1]);
		
	for(i = 1;i <= n;i++) cout << ans[i] << " ";
	cout << endl;

	return 0;
}
