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

ll a[N];
ll b[N];

ll LIS(vl vet)
{

	vl ans;

	for(auto cur : vet)
	{

		auto it = lower_bound(ans.begin(), ans.end(), cur);

		if(it == ans.end()) ans.pb(cur);
		else				*it = cur;

	}

	return ans.size();

}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, i;

	vl c;
	
	cin >> n;

	for(i = 0;i < n;i++) cin >> a[i];
	for(i = 0;i < n;i++) cin >> b[i];

	for(i = 0;i < n;i++)
	{

		c.pb(max(a[i], b[i]));
		c.pb(min(a[i], b[i]));

	}

	cout << LIS(c) << endl;

	return 0;
}
