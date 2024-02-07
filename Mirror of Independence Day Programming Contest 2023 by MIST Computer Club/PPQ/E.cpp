#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
#define N 1000010
#define K 510
#define INF 1000000020
#define INFLL 1000000000000000020
#define fi first
#define se second
#define pb push_back
#define LOG 18
#define SQRT 32000
#define MOD 1000000007
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>

typedef long long ll; 
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef vector< ll > vl;
typedef vector< pll > vll;
typedef tuple< int, int, int> tiii;
typedef tuple< ll, ll, ll> tlll;

vl primes;
bool isPrime[SQRT + 5];
vector<ll>fatores;

void Sieve()
{

    ll i,j;

    memset(isPrime, true, sizeof isPrime);

    for(i = 2;i < SQRT;i++)
    {

        if(isPrime[i] == false) continue;

        primes.pb(i);

        for(j = i * i;j < SQRT;j += i) 
            isPrime[j] = false;

    }

    return;

}

ll GCD(ll x,ll y)
{
    if(!y)
        return x;
    return GCD(y,x%y);
}

ll qtd,cnt=1;
unordered_map<ll,ll> dp;

void DP(ll x)
{
    if(dp[x]==cnt)
        return;
    dp[x]=cnt;
    qtd++;
    for(auto f : fatores)
    {
        if(x%f)
            continue;
        DP(x/f);
    }
    return;
}

void FAT(ll x)
{
    fatores.clear();
    for(auto p : primes)
    {
        if(x%p)
            continue;
        fatores.pb(p);
        while(!(x%p))
            x/=p;
    }
    if(x>1)
        fatores.pb(x);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    Sieve();

    ll tt, n, m, i,x,ans;

    cin >> tt;
    while(tt--)
    {
        cin >> n >> m;
        qtd=0LL;
        FAT(m);
        cnt++;
        DP(m);
        ans=qtd;
        qtd=0LL;
        cnt++;
        for(i = 0;i < n;i++)
        {
            cin >> x;
            DP(GCD(m,x));
        }
        cout << ans-qtd << endl;
    }   

	return 0;
}
