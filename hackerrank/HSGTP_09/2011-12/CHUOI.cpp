#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

using ll = long long;

//vectors
using vi = vector<int>;
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define rsz resize
#define pb push_back

//pairs
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)

//constant initialization
const string yes="YES",no="NO";
const int MOD=1e9+7; //998244353
const int maxn=2e6+10;
const ll INF = 1e18; //Not too close to LLONG_MAX

//variables used for the current problem
string vowel = "aeiouyAEIOUY", s;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	cin >> s;
	each(c,s) {
		if (vowel.find(c) == -1) {
			cout << '.' << char(tolower(c));
		}
	}
	return 0;
}
/*
https://codeforces.com/problemset/problem/118/A
https://www.hackerrank.com/contests/ctin-1922-level-0/challenges/chuoi-ki-tu
https://www.hackerrank.com/contests/sample-hsg-tp-09/challenges/chuoi-chuoi-2011-2012
*/