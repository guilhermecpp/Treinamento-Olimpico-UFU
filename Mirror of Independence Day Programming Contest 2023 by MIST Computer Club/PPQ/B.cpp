#include <bits/stdc++.h>
using namespace std;
 
#define N 200010
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

ll x[N],y[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    ll t,n,k,l,r,mid,i,ans,need;

    cin >> t;
    while(t)
    {
        t--;
        cin >> n >> k;
        i=0;
        while(i<n)
        {
            cin >> y[i];
            i++;
        }
        i=0;
        while(i<n)
        {
            cin >> x[i];
            i++;
        }
        l=ans=0;
        r=3LL*INF;
        while(l<=r)
        {
            mid=((l+r)>>1);
            need=0;
            for(i=0;i<n;i++)
            {
                need+=max(0LL,y[i]*mid-x[i]);
                if(need>k)
                    break;
            }
            if(need<=k)
            {
                l=mid+1;
                ans=max(ans,mid);
            }else
            {
                r=mid-1;
            }
        }
        cout << ans << endl;
    }

	return 0;
}
