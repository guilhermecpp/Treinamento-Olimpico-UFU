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

ll low[N];
ll pre[N];
ll comp[N];
bool stacked[N];
stack<ll>pilha;
vector<ll>scc[N];
vector<ll>grafo[N];
ll qtd=0;
ll cnt=1;

void Tarjan(ll u)
{
    pre[u]=low[u]=cnt;
    stacked[u]=true;
    pilha.push(u);
    cnt++;
    for(auto v : grafo[u])
    {
        if(pre[v])
        {
            if(!stacked[v])
                continue;
            low[u]=min(low[u],pre[v]);
        }else
        {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
    }
    if(pre[u]==low[u])
    {
        ll x=-1;
        qtd++;
        while(x!=u)
        {
            x=pilha.top();
            stacked[x]=false;
            pilha.pop();
            scc[qtd].pb(x);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    ll n,m,u,v,i;
    bool f=true;

    cin >> n >> m;
    while(m)
    {
        m--;
        cin >> u >> v;
        grafo[u].pb(v);
    }
    for(i=1;i<=n;i++)
    {
        if(!pre[i])
            Tarjan(i);
    }
    cout << qtd << endl;
    for(i=1;i<=qtd;i++)
    {
        if(m<scc[i].size())
        {
            m=scc[i].size();
            u=i;
        }
    }
    for(auto x : scc[u])
    {
        if(!f)
            cout << " ";
        else
            f=false;
        cout << x;
    }
    cout << endl;

	return 0;
}
