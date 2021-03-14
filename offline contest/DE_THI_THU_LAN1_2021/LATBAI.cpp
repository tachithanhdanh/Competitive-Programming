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
const int MX = 100;

//variables used for this problem.
ll N, M;
//bool grid[MX][MX];

int main() {
	setIO("LATBAI");
	cin >> N >> M;
	cout << abs((N-2)*(M-2));
	return 0;
}
