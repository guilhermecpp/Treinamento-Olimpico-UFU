#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
#define N 100010
#define K 100000
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

bool dp[K+2][102];
bool marc[K+2][102];

bool test(ll x,ll r)
{
    if(x>K)
        return true;
    if(marc[x][r])
        return dp[x][r];
    marc[x][r]=true;
    ll L=r*x/100,R=L+((r*x)%100),mid,val;
    R=min(R,x);    
    while(L<=R)
    {
        mid=((L+R)>>1);
        val=100*mid/x;
        if(val==r)
            return dp[x][r]=true;
        if(val<r)
            L=mid+1;
        else
            R=mid-1;
    }
    return dp[x][r]=false;
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    ll t,l,r,pct;
    long long a1,a2;

    cin >> t;
    while(t)
    {
        t--;
        a1=a2=-1;
        cin >> l >> r >> pct;
        while(l<=r)
        {
            if(test(l,pct))
            {
                a1=l;
                break;
            }
            l++;
        }
        while(l<=r)
        {
            if(test(r,pct))
            {
                a2=r;
                break;
            }
            r--;
        }
        cout << a1 << " " << a2 << endl;
    }

	return 0;
}
