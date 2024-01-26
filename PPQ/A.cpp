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

	ll t,n,imp,und,x,m;
	bool hasi,hasp;

	cin >> t;
	while(t)
	{
		t--;
		cin >> n;
		imp=und=0;
		while(n)
		{
			n--;
			cin >> m;
			hasi=hasp=false;
			while(m)
			{
				m--;
				cin >> x;
				hasi|=(x%2);
				hasp|=(!(x%2));
			}
			if(hasi && hasp)
			{
				und++;
			}else if(hasi)
			{
				imp++;
			}
		}
		imp%=2;
		cout << ((imp<=und) ? "SIM" : "NAO") << endl;
	}

	return 0;
}
