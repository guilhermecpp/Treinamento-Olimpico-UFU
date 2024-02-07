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

string word[20];
ll where[300];

stack< ll > pos[20];

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    ll tt, n, ans, w, p, i;

    string s;

    cin >> tt;

    while(tt--)
    {

        memset(where, -1, sizeof where);
        ans = 1;

        cin >> n;
    
        for(i = 0;i < n;i++) 
        {
    
            cin >> word[i];

            for(auto ch : word[i])
                where[ch] = i;

        }

        cin >> s;

        for(auto ch : s)
        {

            if(where[ch] == -1) 
            {

                ans = -1;

                break;

            }

            w = where[ch];
            
            if(word[w][0] == ch) 
            {
                
                pos[w].push(0);

                ans++;

            }

            if(pos[w].empty() == true)
            {

                ans = -1;

                break;

            }

            p = pos[w].top();
            pos[w].pop();

            if(word[w][p] != ch)
            {

                ans = -1;

                break;

            }

            p++;
            if(p != word[w].size()) pos[w].push(p);

        }

        for(i = 0;i < n;i++)
            if(pos[i].empty() == false)
                ans = -1;

        if(ans == -1) 
        {
            
            cout << "No" << endl;
        
        }
        else
        {

            cout << "Yes" << endl;
            cout << ans << endl;

        } 

        for(i = 0;i < n;i++)
            while(pos[i].empty() == false)
                pos[i].pop();

    }

	return 0;
}
