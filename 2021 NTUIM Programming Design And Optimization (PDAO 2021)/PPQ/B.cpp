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

typedef long long ll; 
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef vector< ll > vl;
typedef vector< pll > vll;
typedef tuple< int, int, int> tiii;
typedef tuple< ll, ll, ll> tlll;

ll pot2[N];

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    ll t,n,x,y,s,cur;

    cin >> t;
    while(t)
    {
        t--;
        cin >> n >> x >> y >> s;
        if(y>s)
        {
            s=0;
        }else
        {
            s-=y;
            s/=(x+y);
            s++;
            cur=1;
        }
        while(n)
        {
            n--;
            cin >> x;
            if(!s)
                continue;
            if(cur>s)
                continue;
            if((INFLL/cur)<x)
            {
                cur=INFLL;
                continue;
            }
            cur*=x;
        }
        cout << min(s,cur) << endl;
    }

	return 0;
}
