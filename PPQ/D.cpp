#include <bits/stdc++.h>
using namespace std;

#define N 1000010
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

ll n;
ll vet[N];
ll dp[N][3][3];

ll DP(ll i,ll a,ll b)
{
	if(i==n+1)
		return 1;
	if(dp[i][a][b]!=-1)
		return dp[i][a][b];
	ll ans=0LL,c;
	if(vet[i]==-1)
	{
		for(c=0;c<3;c++)
		{
			if(i<=2 || a+b+c==3)
				ans+=DP(i+1,b,c);
		}
	}else
	{
		c=vet[i];
		if(i<=2 || a+b+c==3)
			ans+=DP(i+1,b,c);
	}
	return dp[i][a][b]=ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(dp,-1,sizeof dp);

	ll i=1;

	cin >> n;
	while(i<=n)
	{
		cin >> vet[i];
		i++;
	}
	cout << DP(1,0,0) << endl;

	return 0;
}
