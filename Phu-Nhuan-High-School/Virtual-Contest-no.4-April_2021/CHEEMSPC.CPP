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
#define debug(x) cout << (#x) << " is " << (x) << endl
#else
#define debug(x)
#endif // LOCAL

//Set min-max value.
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; } // set a = min(a,b)
template<class T> bool ckmax(T& a, const T& b) { return b > a ? a = b, 1 : 0; } // set a = max(a,b)

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name+".INP").c_str(), "r", stdin); // see /general/io
		freopen((name+".OUT").c_str(), "w", stdout);
	}
}

//constant initialization
const string yes="YES\n",no="NO\n";
const int MOD = 1e9+7; //998244353
const int MX = 1e2+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
int N, P1, P2, P3, T1, T2, L[MX], R[MX], P, dT, dT1, dT2, dT3, usedP1, usedP2, usedP3;

int main() {
	setIO("CHEEMSPC");
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N >> P1 >> P2 >> P3 >> T1 >> T2;
	for (int i = 0; i < N; ++i) cin >> L[i] >> R[i];
	P = (R[0]-L[0])*P1;
	for (int i = 1; i < N; ++i) {
		dT = L[i]-R[i-1];
		dT1 = max(0,dT-T1);
		dT2 = max(0,dT1-T2);
		usedP1 = (R[i]-L[i]+min(T1,dT))*P1;
		usedP2 = min(dT1,T2)*P2;
		usedP3 = dT2*P3;
		P += usedP1 + usedP2 + usedP3;
		//debug(usedP1);
		//debug(usedP2);
		//debug(usedP3);
		//debug(P);
	}
	cout << P;
	return 0;
}
