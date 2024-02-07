#include <bits/stdc++.h>
using namespace std;
 
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

typedef long long ll; 
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef vector< ll > vl;
typedef vector< pll > vll;
typedef tuple< int, int, int> tiii;
typedef tuple< ll, ll, ll> tlll;

vl grafo[N];

ll tempo;
ll pre[N];
ll low[N];

ll qtd;
ll tam[N];

bool onStack[N];
stack< ll > pilha;

void Tarjan(ll u)
{

    pre[u] = low[u] = tempo++;

    pilha.push(u);
    onStack[u] = true;

    for(auto v : grafo[u])
    {

        if(pre[v] == -1)
        {

            Tarjan(v);

            low[u] = min(low[u], low[v]); 

        }else if(onStack[v] == true)
        {

            low[u] = min(low[u], pre[v]);

        }

    }

    if(pre[u] == low[u])
    {

        ll v = -1;

        tam[qtd] = 0;

        while(v != u)
        {

            v = pilha.top();
            pilha.pop();

            onStack[v] = false;

            tam[qtd]++;

        }
        
        qtd++;

    }

}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    ll tt, n, m, u, v, i;

    cin >> tt;

    while(tt--)
    {

        cin >> n >> m;

        while(m--)
        {

            cin >> u >> v;

            grafo[u].pb(v);

        }

        tempo = 0;
        for(i = 1;i <= n;i++) pre[i] = low[i] = -1;

        qtd = 0;
        for(i = 1;i <= n;i++)
            if(pre[i] == -1)
                Tarjan(i);

        tam[qtd] = 0; // zero extra
        sort(tam, tam + qtd + 1, greater< ll >());

        cout << tam[0] + tam[1] << endl;

        for(i = 1;i <= n;i++)
            grafo[i].clear();

    }

	return 0;
}
