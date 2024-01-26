#include <bits/stdc++.h>
using namespace std;

#define N 500010
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

ll vet[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, l, r, mid, ans, z, votes, i;

	cin >> n;
	for(i = 0;i < n;i++) cin >> vet[i];

	l = 0;
	r = INF;

	while(l <= r)
	{

		mid = (l + r) / 2;

		z = vet[0] + mid;

		votes = 0;

		for(i = 1;i < n;i++)
			votes += max(vet[i] - z + 1, 0LL);

		if(votes <= mid)
		{

			ans = mid;

			r = mid - 1;

		}else
		{

			l = mid + 1;

		}

	}

	cout << ans << endl;

	return 0;
}
