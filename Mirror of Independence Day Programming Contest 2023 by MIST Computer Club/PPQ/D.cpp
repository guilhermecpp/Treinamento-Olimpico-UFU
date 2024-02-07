#include <bits/stdc++.h>
using namespace std;
 
#define N 100010
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

vl di[N];
ll has[N];

void Init()
{

    ll i, j;

    for(i = 1;i < N;i++)
        for(j = i;j < N;j += i)
            di[j].pb(i);

    return;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    Init();

    ll tt, n, q, x, caso = 0, i, j;

    cin >> tt;

    while(tt--)
    {

        caso++;

        cin >> n >> q;

        for(i = 0;i < n;i++) 
        {
            
            cin >> x;

            has[x] = caso;

        }

        while(q--)
        {

            ll ans = 0;

            cin >> x;

            for(auto cur : di[x])
                if(has[cur] != caso)
                    ans++;

            cout << ans << endl;

        }



    }

	return 0;
}
