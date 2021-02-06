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
const string yes="YES\n",no="NO\n";
const int MOD=1e9+7; //998244353
const ll INF = 1e18; //Not too close to LLONG_MAX

int N, x[100], passto[100];   // passto[i] is # of cows passing to cow i
int target[101], answer;

int main() {
	//Read the problem statement here: http://www.usaco.org/index.php?page=viewproblem2&cpid=808
	//Wow the editorial was carefully and concisely written so I have to link this guys
	//http://www.usaco.org/current/data/sol_hoofball_bronze_feb18.html
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif // LOCAL
	freopen("hoofball.in","r",stdin);
	freopen("hoofball.out","w",stdout);
	cin >> N;
	F0R(i,N) cin >> x[i];
	auto target = [](const int &i) {
		int left_neighbour = -1, left_dist = 1000;
		int right_neighbour = -1, right_dist = 1000;
		F0R(j,N) if (x[j] < x[i] && x[i] - x[j] < left_dist) { left_neighbour = j; left_dist = x[i] - x[j]; }
		F0R(j,N) if (x[j] > x[i] && x[j] - x[i] < right_dist) { right_neighbour = j; right_dist = x[j] - x[i]; }
		if (left_dist <= right_dist) return left_neighbour;
		else return right_neighbour;
	};
	F0R(i,N) ++passto[target(i)];
	F0R(i,N) {
		if (passto[i] == 0) ++answer;
		if (passto[i] == 1 && passto[target(i)] == 1 && i < target(i) && target(target(i)) == i) ++answer;
	}
	cout << answer;
	return 0;
}
