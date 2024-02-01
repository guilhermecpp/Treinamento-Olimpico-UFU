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

	ll n, m, k, i;

	string s;

	map< string, ll > menor;

	cin >> n >> m;

	for(i = 0;i < n;i++) cin >> a[i];
	
	for(i = 0;i < m;i++) 
	{
	
		cin >> b[i];

		menor[b[i]] = INF;

	}
	
	for(i = 0;i < n;i++)
	{

		s = "";
		k = a[i].size();

		for(auto ch : a[i])
		{

			s.pb(ch);
			k--;

			if(menor.find(s) == menor.end()) continue;

			menor[s] = min(menor[s], k);

		}

	}

	for(i = 0;i < m;i++)
	{

		if(menor[b[i]] == INF) 		
			k = -1;
		else								
			k = menor[b[i]];

		cout << k << endl;

	}

	return 0;
}
