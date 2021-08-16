#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

#define endl "\n"

using ll = long long;
using str = string;

//vectors
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using vs = vector<str>;
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define pb push_back

//pairs
using pi = pair<int,int>;
using vpi = vector<pi>;
#define f first
#define s second
#define mp make_pair

//for printing variables when debugging
#ifdef LOCAL
#define db(x) cerr << (#x) << " is " << (x) << endl
#else
#define db(x)
#endif // LOCAL

//constant initialization
const str yes="YES\n",no="NO\n";
const int MOD = 1e9+7; //998244353
const int MX = 1e4+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
const char dc[4] = {'D', 'R', 'U', 'L'};

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

int N, K, mn, mx, ans = MOD, pos[10];
str A = "0000000000", preA;

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N >> K;
	vs S(N), preS;
	for (int i = 0; i < N; ++i) cin >> S[i];
	for (int i = 0; i < K; ++i) A[i] = i+48;
	preA = A, preS = S;
	do {
		mn = MOD, mx = 0;
		for (int i = 0; i < K; ++i) {
			for (int j = 0; j < K; ++j) {
				if (A[i] == preA[j]) pos[i] = j;
			}
		}
		preS = S;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < K; ++j) {
				S[i][j] = preS[i][pos[j]];
			}
			ckmin(mn,stoi(S[i]));
			ckmax(mx,stoi(S[i]));
			//cout << S[i] << " ";
		}
		preA = A;
		ckmin(ans,mx-mn);
	} while (next_permutation(A.begin(), A.begin()+K));
	//string T = "1234";
	//do {
	//	cout << T << endl;
	//} while (next_permutation(all(T)));
	cout << ans;
 	return 0;
}
