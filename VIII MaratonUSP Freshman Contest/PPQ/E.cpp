#include <bits/stdc++.h>
using namespace std;

#define N 40
#define M 1000000010
#define INF 1000000020
#define INFLL 1000000000000000020
#define fi first
#define se second
#define pb push_back
#define LOG 18
#define SQRT 25

typedef long long ll; 
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef vector< ll > vl;
typedef vector< pll > vll;
typedef tuple< int, int, int> tiii;
typedef tuple< ll, ll, ll> tlll;

ll dist[N][N];
ll qtd[N][N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll t,v,f,ans;

	cin >> t;
	while(t)
	{
		t--;
		cin >> v >> f;
		if(3*v>f)
		{
			ans=3*v-f;
		}else
		{
			if(f%3)
			{
				ans=(f/3+1)-v;
				v+=ans;
				ans+=3*v-f;
			}else
			{
				ans=(f/3)-v;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
