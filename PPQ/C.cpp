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

	ll n,m,i,j,x,y,ans=0LL,s;

	cin >> n >> m;

	ll mat[n+5][m+5],sum[n+5][m+5];

	memset(mat,0,sizeof mat);
	memset(sum,0,sizeof sum);

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin >> mat[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			sum[i][j]=sum[i][j-1]+
					  sum[i-1][j]-
					  sum[i-1][j-1]+
					  mat[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			for(x=i;x<=n;x++)
			{
				for(y=j;y<=m;y++)
				{
					s=sum[x][y]-
					  sum[x][j-1]-
					  sum[i-1][y]+
					  sum[i-1][j-1];
					if(s!=(x-i+1)*(y-j+1))
						s=0;
					ans=max(ans,s);
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}
