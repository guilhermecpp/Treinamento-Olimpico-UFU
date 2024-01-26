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



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, h, x, i;

	string ans = "SIM";

	cin >> n >> h;

	for(i = 0;i < n;i++)
	{

		cin >> x;

		if(h < x) ans = "NAO";

		h += x;

	}

	cout << ans << endl;

	return 0;
}
