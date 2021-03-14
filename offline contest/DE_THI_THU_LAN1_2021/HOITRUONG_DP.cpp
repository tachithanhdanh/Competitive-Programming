#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

using ll = long long;

//vectors
using vi = vector<int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define pb push_back

//pairs
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

//loops
#define FOR(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
#define F0R(i,a) FOR(i,0,a)

//setIO
void setIO(string name = "") {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	if (sz(name)) {
		freopen((name+".INP").c_str(),"r",stdin);
		freopen((name+".OUT").c_str(),"w",stdout);
	}
	#ifdef DANHDEBUG
	freopen("input.txt","r",stdin);
	#endif // DANHDEBUG
}

//constant declarations
const int MX = 1e4 + 10;

//variables used for this problem.
int dp[2][MX], End[2][MX];

int main() {
	setIO("HOITRUONG");
	// ĐCM cay bài này vãi lồn
	// Bài dễ chetme mà đéo chịu nghĩ cách là DP
	// Mày ngu quá Danh ơi
	// ĐCMM
	int N;
	cin >> N;
	vector<pi> req(N);
	for (pi& task : req) cin >> task.f >> task.s;

	//Ending first
	sort(all(req),[](const pi& t1, const pi& t2){
		if (t1.s == t2.s) return t1.f < t2.f;
		return t1.s < t2.s;
	});

	for (int i = 1; i <= N; ++i) {
		dp[0][i] = max(dp[0][i-1],dp[1][i-1]);
		End[0][i] = (dp[0][i-1] > dp[1][i-1] ? End[0][i-1] : End[1][i-1]);
		for (int j = i - 1; j >= 0; --j) {
			if (req[i-1].f >= End[1][j]) {
				if (dp[1][j] > dp[1][i]) {
					dp[1][i] = dp[1][j];
				}
			}
		}
		dp[1][i] += req[i-1].s - req[i-1].f;
		End[1][i] = req[i-1].s;
		//cout << "end[" << 0 << "][" << i << "] = "  << End[0][i] << endl;
		//cout << "end[" << 1 << "][" << i << "] = "  << End[1][i] << endl;
		//cout << "dp[" << 0 << "][" << i << "] = "  << dp[0][i] << endl;
		//cout << "dp[" << 1 << "][" << i << "] = "  << dp[1][i] << endl;
		//cout << endl;
	}
	cout << max(dp[1][N],dp[0][N]);
	return 0;
}
