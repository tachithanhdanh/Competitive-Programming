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
const char dc[4] = {'r', 'u', 'l', 'd'};

//variables used for the current problem
int N, K, A[MX], maxnum[3], pos[3];
vi zero;
bool used[3];

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N;
	zero.pb(-1);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		if (!A[i]) zero.pb(i);
	}
	zero.pb(N);
	for (int i = 0; i < sz(zero)-1; ++i) {
		memset(maxnum,-1,sizeof(maxnum));
		memset(pos,-1,sizeof(pos));
		for (int j = zero[i]+1; j < zero[i+1]; ++j) {
			if (A[j] > maxnum[0]) {
				maxnum[2] = maxnum[1];
				pos[2] = pos[1];
				maxnum[1] = maxnum[0];
				pos[1] = pos[0];
				maxnum[0] = A[j];
				pos[0] = j;
			}
			else if (A[j] > maxnum[1]) {
				maxnum[2] = maxnum[1];
				pos[2] = pos[1];
				maxnum[1] = A[j];
				pos[1] = j;
			}
			else if (A[j] > maxnum[2]) {
				maxnum[2] = A[j];
				pos[2] = j;
			}
		}
		for (int j = zero[i]+1; j < zero[i+1]; ++j) {
			int p = -1;
			for (int k = 0; k < 3; ++k) if (j == pos[k]) p = k;
			if (p == -1) {
				cout << "pushBack";
			}
			else if (p == 0) {
				cout << "pushStack";
			}
			else if (p == 1) {
				cout << "pushQueue";
			}
			else {
				cout << "pushFront";
			}
			cout << endl;
		}
		if (zero[i+1] < N) {
			//cout << i << endl;
			K = 3-count(all(pos),-1);
			cout << K;
			if (K >= 1) {
				cout << " popStack";
			}
			if (K >= 2) {
				cout << " popQueue";
			}
			if (K == 3) {
				cout << " popFront";
			}
			cout << endl;
		}
	}
	return 0;
}
