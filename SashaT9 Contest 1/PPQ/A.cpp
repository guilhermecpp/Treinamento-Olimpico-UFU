#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
#define N 1000010
#define K 100
#define INF 1000000020
#define INFLL 1000000000000000020
#define fi first
#define se second
#define pb push_back
#define LOG 18
#define SQRT 32000
#define MOD 1000000007
//#define ordered_set tree<pair<int,int>,null_type,less< pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update>

typedef long long ll; 
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef vector< ll > vl;
typedef vector< pll > vll;
typedef tuple< int, int, int> tiii;
typedef tuple< ll, ll, ll> tlll;

map<ll,bool>has;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll i,cur=0,pot=1,x;

	for(i=0;i<32;i++)
	{
		cur+=pot;
		pot*=2;
		has[cur]=true;
	}
	cin >> x;
	if(has[x+1])
	
		cout << x+1 << endl;
	else
		cout << -1 << endl;

	return 0;
}
