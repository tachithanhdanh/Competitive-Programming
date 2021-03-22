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

#define debug(x) cout << #x << " = " << (x) << endl;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (sz(name)) {
		freopen((name+".INP").c_str(),"r",stdin);
		freopen((name+".OUT").c_str(),"w",stdout);
	}
	#ifdef DANHDEBUG
	freopen("input.txt","r",stdin);
	#endif // DANHDEBUG
}

//constant initialization
const int MX = 1E5 + 10;
const int MOD = 1E9 + 7; // INF for int_32t
const ll INF = 1e18; // Not too close to LLONG_MAX

//variables for current problem
int maxX, minX;

int main() {
	setIO("LINETRIP");
	int N;
	cin >> N;
	vi X(N);
	for (int i = 0; i < N; ++i) cin >> X[i];
	//X.pb(0); unnecessary
	// 4 cases
	// all positives : ans = maxX;
	// all negatives : ans = minX;
	// pos, neg => ans = maxX + minX;
	// all 0 => 0
	// Must multiply by 2 (go back and forth)
	// O(N)
	for (int i = 0; i < N; ++i) {
		maxX = max(maxX, X[i]);
		minX = min(minX, X[i]);
	}
	cout << (maxX + (-minX)) * 2;
	return 0;
}
