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

pll ans[N],vet[N];
ll sum[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n,m,i=1,x,j;

	cin >> n;
	while(i<=n)
	{
		cin >> x;
		sum[i]=sum[i-1]+x;
		i++;
	}
	cin >> m;
	i=1;
	while(i<=m)
	{
		cin >> vet[i].first;
		vet[i].second=i;
		i++;
	}
	sort(vet+1,vet+m+1);
	i=1;
	for(j=1;j<=m;j++)
	{
		while(sum[i]<vet[j].first)
			i++;
		ans[vet[j].second]={sum[i],i};
	}
	for(i=1;i<=m;i++)
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}

	return 0;
}
