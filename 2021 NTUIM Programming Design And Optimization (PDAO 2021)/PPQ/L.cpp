#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
#define N 100010
#define K 110
#define INF 1000000020
#define INFLL 1000000000000000020
#define fi first
#define se second
#define pb push_back
#define LOG 18
#define SQRT 32000
#define MOD1 1000000007
#define MOD2 1000000009
//#define ordered_set tree<pair<int,int>,null_type,less< pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update>

typedef long long ll; 
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef vector< ll > vl;
typedef vector< pll > vll;
typedef tuple< int, int, int> tiii;
typedef tuple< ll, ll, ll> tlll;

ll ra1[N];
ll ra2[N];

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    srand(time(NULL));

    ll sum1, sum2, ans = 0, i;

    for(i = 'B';i <= 'Z';i++) ra1[i] = rand() % MOD1;
    ra1['A'] = (3LL * MOD1 - ra1['D'] - ra1['O'] - ra1['P']) % MOD1;

    for(i = 'B';i <= 'Z';i++) ra2[i] = rand() % MOD2;
    ra2['A'] = (3LL * MOD2 - ra2['D'] - ra2['O'] - ra2['P']) % MOD2;

    string s;

    map< pll, ll > menor;

    cin >> s;

    menor[{0, 0}] = 0;

    sum1 = 0;
    sum2 = 0;
    i = 1;

    for(auto ch : s)
    {

        sum1 = (sum1 + ra1[ch]) % MOD1;
        sum2 = (sum2 + ra2[ch]) % MOD2;

        ll x1 = (MOD1 - sum1) % MOD1;
        ll x2 = (MOD2 - sum2) % MOD2;

        if(menor.find({x1, x2}) != menor.end())
            ans = max(ans, i - menor[{x1, x2}]);

        if(menor.find({x1, x2}) == menor.end())
            menor[{x1, x2}] = i;

        i++;

    }

    cout << ans << endl;

	return 0;
}
