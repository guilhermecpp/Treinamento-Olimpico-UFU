#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
#define N 100010
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

typedef unsigned long long ll; 
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef vector< ll > vl;
typedef vector< pll > vll;
typedef tuple< int, int, int> tiii;
typedef tuple< ll, ll, ll> tlll;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    ll tt, n, i;

    vl ans;

    cin >> tt;

    while(tt--)
    {

        ans.clear();

        cin >> n;

        if(n % 2 != 0)
        {

            cout << -1 << endl;

            continue;

        }

        n = (n >> 1LL);

        i = 1;

        while(i <= n)
        {

            if((n & i) != 0)  ans.pb(1);
            else              ans.pb(2);

            i *= 2LL;

        }

        reverse(ans.begin(), ans.end());

        cout << ans.size() << endl;
        for(auto cur : ans) cout << cur << " ";
        cout << endl;
        
    }



	return 0;
}
