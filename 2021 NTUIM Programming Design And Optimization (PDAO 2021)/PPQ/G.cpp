#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
#define N 110
#define K 510
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

ll n;
ll a[N];
ll b[N];
ll c[N];
ll accuV[N];
ll accuP[N];
ll dp[N][N][N];

double average(ll l, ll r)
{

    ll x = accuV[r] - accuV[l - 1];
    ll y = accuP[r] - accuP[l - 1];

    return (x * 1.0) / y;

}

ll GPA(double av)
{

    ll x = (ll)(av + 0.5);

    if(x <= 59)     return 00LL;
    if(x <= 62)     return 17LL;
    if(x <= 66)     return 20LL;
    if(x <= 69)     return 23LL;
    if(x <= 72)     return 27LL;
    if(x <= 76)     return 30LL;
    if(x <= 79)     return 33LL;
    if(x <= 84)     return 37LL;
    if(x <= 89)     return 40LL;
    if(x <= 100)    return 43LL;

    assert(false);

}

ll DP(ll l, ll r, ll k)
{

    if(r == n + 1)
    {

        if(l == n + 1 && k == 0) return 0;

        return -INF;

    }

    if(k < 0) return -INF;
    
    ll& ans = dp[l][r][k];

    if(ans != -1) return ans;

    ll a = DP(r + 1, r + 1, k - 1) + GPA(average(l, r));
    ll b = DP(l, r + 1, k);

    return ans = max(a, b);

}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    ll k, i;

    cin >> n;

    for(i = 1;i <= n;i++) cin >> a[i];
    for(i = 1;i <= n;i++) cin >> b[i];
    for(i = 1;i <= n;i++) c[i] = a[i] * b[i];

    for(i = 1;i <= n;i++) accuV[i] = accuV[i - 1] + c[i];
    for(i = 1;i <= n;i++) accuP[i] = accuP[i - 1] + b[i];

    cin >> k;

    memset(dp, -1, sizeof dp);

    cout << setprecision(8) << fixed;
    cout << (DP(1, 1, k) / (k * 10.0)) << endl;

	return 0;
}
