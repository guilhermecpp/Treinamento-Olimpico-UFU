#include<bits/stdc++.h>
using namespace std;

#define NMAX 1000010
#define MMAX 30
#define INF 1000000000
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair< ll, ll > pll;

pll ran[NMAX];

ll dp[MMAX][MMAX];

pll invalid = {INF, -INF};

pll Range(ll l, ll r)
{

    pll ans = invalid;
    
    for(ll i = l;i <= r;i++)
    {
    
        ans.fi = min(ans.fi, ran[i].fi);
        ans.se = max(ans.se, ran[i].se);
    
    }
     
    return ans;

}

ll Cont(ll l, ll r, ll dest)
{

    pll aux = Range(l, r);
    
    if(aux == invalid) return 0LL;
    
    ll a = aux.fi;
    ll b = aux.se;
    
    return ((b - a) * (dest - r));

}

ll DP(ll l, ll r)
{

    if(l == r) return 0LL;
    
    ll& ans = dp[l][r];
    
    if(ans != -1) return ans;
    
    ans = INF;

    ll mid, a, b, c;

    for(mid = l;mid < r;mid++)
    {
    
        a = DP(l, mid);
        b = DP(mid + 1, r);    
        c = Cont(l, mid, r);
    
        ans = min(ans, a + b + c);
    
    }
    
    return ans;

}

int main()
{

    ll n, m, x, i, k;
    
    ll ans = INF;
    
    string s;

    cin >> n;
    cin >> s;
    
    m = 26;
    
    for(i = 0;i < m;i++)
        ran[i] = invalid;
    
    for(i = 0;i < n;i++)
    {
    
        x = (ll)(s[i] - 'a');
        
        ran[x].fi = min(ran[x].fi, i);
        ran[x].se = max(ran[x].se, i);  
    
    }
    
    for(k = 0;k < m;k++)
    {
        
        memset(dp, -1, sizeof dp);
        ans = min(ans, DP(0, m - 1));
        
        for(i = m - 2;i >= 0;i--)
            swap(ran[i], ran[i + 1]);  
   
    }
    
    cout << ans << endl;

    return 0;
    
}
