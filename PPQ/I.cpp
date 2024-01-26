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

int n;
string correct[N];
string word[N];
string cript="$$$$$$$$$$$$$$$$$$$$$$$$$$";
map<char,bool>putted;

bool test()
{
	int i,j,sz,pos;
	for(i=0;i<n;i++)
	{
		sz=(int)(word[i].size());
		for(j=0;j<sz;j++)
		{
			pos=(int)(correct[i][j]-'A');
			if(cript[pos]=='$' && !putted[word[i][j]])
			{
				cript[pos]=word[i][j];
				putted[word[i][j]]=true;
			}
			if(cript[pos]!=word[i][j])
				return false;
		}

	}
	return true;
}

map<char,bool>has;

vector<char>letras;

bool build(string a,string b)
{
	if(a.size()!=b.size())
		return false;
	int sz=(int)(a.size());
	int i=0;
	map<char,int>aa,bb;
	int cnt=0;
	for(i=0;i<sz;i++)
	{
		if(aa.find(a[i])==aa.end())
		{
			aa[a[i]]=cnt;
			cnt++;
		}
		a[i]=(char)(aa[a[i]]+'A');
	}
	cnt=0;
	for(i=0;i<sz;i++)
	{
		if(bb.find(b[i])==bb.end())
		{
			bb[b[i]]=cnt;
			cnt++;
		}
		b[i]=(char)(bb[b[i]]+'A');
	}
	return (a==b);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int i=0,sz;
	bool ans=true;

	cin >> n;
	while(i<n)
	{
		cin >> word[i];
		sz=(int)(word[i].size());
		if(build(word[i],"AC"))
			correct[i]="AC";
		else if(build(word[i],"OVO"))
			correct[i]="OVO";
		else if(build(word[i],"VOO"))
			correct[i]="VOO";
		else if(build(word[i],"TLE"))
			correct[i]="TLE";
		else if(build(word[i],"OSSO"))
			correct[i]="OSSO";
		else if(build(word[i],"PATA"))
			correct[i]="PATA";
		else if(build(word[i],"AMOR"))
			correct[i]="AMOR";
		else if(build(word[i],"CAVALO"))
			correct[i]="CAVALO";
		else if(build(word[i],"RARADA"))
			correct[i]="RARADA";
		else if(build(word[i],"MARATONUSP"))
			correct[i]="MARATONUSP";
		else if(build(word[i],"BRASILEIRO"))
			correct[i]="BRASILEIRO";
		else
			ans=false;
		i++;
	}
	if(!ans)
	{
		cout << "N" << endl;
		return 0;
	}
	if(!test())
	{
		cout << "N" << endl;
		return 0;
	}
	cout << "Y" << endl;
	for(i=0;i<26;i++)
	{
		has[cript[i]]=true;
	}
	for(i=0;i<26;i++)
	{
		if(has[(char)(i+'A')])
			continue;
		letras.pb((char)(i+'A'));
	}
	reverse(letras.begin(),letras.end());
	for(i=0;i<26;i++)
	{
		if(cript[i]=='$')
		{
			cript[i]=letras.back();
			letras.pop_back();
		}
	}
	cout << cript << endl;

	return 0;
}
