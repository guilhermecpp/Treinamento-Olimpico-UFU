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
#define MOD 1000000009
//#define ordered_set tree<pair<int,int>,null_type,less< pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update>

typedef long long ll; 
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef vector< ll > vl;
typedef vector< pll > vll;
typedef tuple< int, int, int> tiii;
typedef tuple< ll, ll, ll> tlll;

ll ans[N];
vector<ll>vet[N];
ll grau[N];

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    memset(ans,-1,sizeof ans);

    ll n,m,u,i=0,k,x,aux;

    cin >> n >> m;
    aux=m;
    while(m)
    {
        m--;
        cin >> u >> k;
        ans[u]=k;
        if(!k)
        {
            cin >> u;
            continue;
        }
        while(k)
        {
            k--;
            cin >> x;
            vet[u].pb(x);
            grau[x]++;
        }
    }
    m=aux;
    for(i=1;i<=n;i++)
    {
        if(ans[i]==-1 || grau[i]!=m-1 || !grau[i])
            continue;
        k=false;
        for(auto x : vet[i])
        {
            if(ans[x]!=-1)
                k=true;
        }
        if(k)
            continue;
        cout << i << endl;
        return 0;
    }
    cout << -1 << endl;

	return 0;
}
