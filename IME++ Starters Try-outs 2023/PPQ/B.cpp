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

ll vet[N];

string a[N];
string b[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll tt;

	double x1, y1, x2, y2, a, b, x;

	cin >> tt;

	cout << setprecision(8) << fixed;

	while(tt--)
	{

		cin >> x1 >> y1;
		cin >> x2 >> y2;

		a = (x2 * y1 - x1 * y2) / (x1 * x1 * x2 - x2 * x2 * x1);
		b = (y1 - a * x1 * x1) / x1;
		x = -b / a;

		cout << x << endl;

	}

	return 0;
}
