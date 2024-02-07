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

ll vet[N];
ll esq[N];
ll dir[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll tt;

    string s;

    cin >> tt;

    while(tt--)
    {

        cin >> s;

        for(auto ch : s)
        {

            if(ch == 'z') continue;
            if(ch == 'x') continue;
            if(ch == 'c') continue;
            if(ch == 'v') continue;
            if(ch == 'b') continue;
            if(ch == 'n') continue;
            if(ch == 'm') continue;

            cout << ch;

        }

        cout << endl;

    }

	return 0;
}
