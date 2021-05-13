#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

#define endl "\n"

using ll = long long;

//vectors
using vi = vector<int>;
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define pb push_back

//pairs
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

//for printing variables when debugging
#ifdef LOCAL
#define db(x) cerr << (#x) << " is " << (x) << endl
#else
#define db(x)
#endif // LOCAL

//Set min-max value.
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; } // set a = min(a,b)
template<class T> bool ckmax(T& a, const T& b) { return b > a ? a = b, 1 : 0; } // set a = max(a,b)

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin); // see /general/io
		freopen((name+".out").c_str(), "w", stdout);
	}
}

//constant initialization
const string yes="YES\n",no="NO\n";
const int MOD = 1e9+7; //998244353
const int MX = 1e5+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
string S;
// Read the rule for number numbers divisible by 8
// Here: https://en.wikipedia.org/wiki/Divisibility_rule#Divisibility_rules_for_numbers_1%E2%80%9330
// > The last three digits are divisible by 8.
int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> S;
	for (int i = 0; i < sz(S); ++i)
		if (!((S[i]-'0')%8))
			return cout << yes << S[i], 0;
	for (int i = 0; i < sz(S); ++i)
		for (int j = i + 1; j < sz(S); ++j)
			if (!(((S[i]-'0')*10 + (S[j]-'0')) % 8))
				return cout << yes << S[i] << S[j], 0;
	for (int i = 0; i < sz(S); ++i)
		for (int j = i + 1; j < sz(S); ++j)
			for (int k = j + 1; k < sz(S); ++k)
				if (!(((S[i]-'0')*100 + (S[j]-'0')*10 + (S[k]-'0')) % 8))
					return cout << yes << S[i] << S[j] << S[k], 0;

	cout << no;
	return 0;
}
