#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

using ll = long long;

//vector
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
const int maxn=5e3+10;
const ll INF = 1e18; //Not too close to LLONG_MAX

//variables used for the current problem
int X[maxn], Y[maxn], N;
int max_dist, dist;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	cin >> N;
	auto square = [](const int &a) {
		return a*a;
	};
	F0R(i,N) cin >> X[i];
	F0R(i,N) cin >> Y[i];
	F0R(i,N) FOR(j,i,N) {
		dist = square(X[j]-X[i]) + square(Y[j]-Y[i]);
		max_dist = max(max_dist, dist);
	}
	cout << max_dist;
	return 0;
}

//https://usaco.guide/bronze/intro-complete?lang=cpp
//https://codeforces.com/gym/102951/submission/106865190
//https://codeforces.com/gym/102951/problem/A