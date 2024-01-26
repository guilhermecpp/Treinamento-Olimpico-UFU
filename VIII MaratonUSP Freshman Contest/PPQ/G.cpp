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

ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, 1, 0, -1};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, m, a, b, i;
	ll x, y, nx, ny;

	queue< pll > fila;

	cin >> n >> m >> a >> b;

	memset(dist, -1, sizeof dist);

	dist[1][1] = 0;
	qtd[1][1] = 1;
	fila.push({1, 1});

	while(fila.empty() == false)
	{

		x = fila.front().fi;
		y = fila.front().se;
		fila.pop();

		if(x == a && y == b) continue;

		for(i = 0;i < 4;i++)
		{

			nx = x + dx[i];
			ny = y + dy[i];

			if(nx < 1 || n < nx) continue;
			if(ny < 1 || m < ny) continue;

			if(dist[nx][ny] == -1)
			{

				dist[nx][ny] = dist[x][y] + 1;
				qtd[nx][ny] = qtd[x][y];
				fila.push({nx, ny});

			}else if(dist[nx][ny] == dist[x][y] + 1)
			{
				
				qtd[nx][ny] += qtd[x][y];

			}

		}

	}

	qtd[a][b] = 0;

	cout << qtd[n][m] << endl; 

	return 0;
}
