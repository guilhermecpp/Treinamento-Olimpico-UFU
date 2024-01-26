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

priority_queue<int>ord;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll x,n,i,k,ans=0LL,y;

	cin >> n >> k;
	k*=(-1);
	while(n)
	{
		n--;
		cin >> x;
		ord.push(x);
		k+=x;
	}
	while(k>0)
	{
		x=ord.top();
		y=x/2+(x%2);
		k-=y;
		ord.pop();
		ord.push(x-y);
		ans++;
	}
	cout << ans << endl;

	return 0;
}
