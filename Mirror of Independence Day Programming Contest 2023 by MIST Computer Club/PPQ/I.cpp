#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define N 200010
#define K 510
#define INF 1000000020
#define INFLL 1000000000000000020
#define fi first
#define se second
#define pb push_back
#define LOG 18
#define SQRT 25
#define MOD 1000000007
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>

typedef long long ll; 
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef vector< ll > vl;
typedef vector< pll > vll;
typedef tuple< int, int, int> tiii;
typedef tuple< ll, ll, ll> tlll;

ordered_set vet;
bool marc[N];
ll where[N];

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    ll t,n,q,i,x,cur,cnt;

    cin >> t;
    while(t)
    {
        t--;
        cin >> n >> q;
        for(i=1;i<=n;i++)
        {
            marc[i]=false;
            where[i]=0;
        }
        i=0;
        vet.clear();
        while(i<n)
        {
            cin >> x;
            vet.insert(i);
            if(!marc[x])
            {
                where[x]=i;
                marc[x]=true;
            }
            i++;
        }
        cnt=-1;
        while(q)
        {
            q--;
            cin >> x;
            cout << vet.order_of_key(where[x])+1 << endl;
            vet.erase(where[x]);
            vet.insert(cnt);
            where[x]=cnt;
            cnt--;
        }
    }

	return 0;
}
