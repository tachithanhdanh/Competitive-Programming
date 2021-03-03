#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

#define endl "\n"
//for k i j bruh
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
int N, LIS;
vi ans, A, B;
//bool used[MX];

bool check() {
	bool flag = true;
	for (int i = 1; i < sz(ans); ++i) {
		flag &= ans[i] > ans[i-1];
	}
	return flag;
}

void dfs(int k) {
	if (k == N) {
		if (check()) {
			LIS = max(LIS, sz(ans));
		}
		return;
	}
	//for (int i = 0; i < sz(ans); ++i) {
	//	cout << ans[i] << " ";
	//}
	//cout << endl;
	ans.pb(A[k]);
	dfs(k+1);
	ans.pop_back();
	dfs(k+1);
}

int main() {
	setIO("PERLIS");
	//setIO();
	//fuck, I don't know LIS DP
	//Let's get partial points for this
	//next_permutation O(N!)
	// 30 % test cases
	cin >> N;
	A.resize(N);
	B.resize(N);
	iota(all(A),1);
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	//what I need to do is
	//create a check function
	//and a DFS function
	//all set
	//A = {4, 2, 1, 3};
	do {
		bool flag = true;

		for (int i = 0; i < N; ++i) {
			LIS = 0;
			ans.pb(A[i]);
			dfs(i+1);
			//debug(LIS);
			ans.pop_back();
			//cout << sz(ans) << endl;
			if (LIS != B[i]) {
				flag = false;
				break;
			}
		}
		//cout << endl;
		if (flag) break;
	} while (next_permutation(all(A)));
	cout << *A.begin();
	for (int i = 1; i < N; ++i) cout << " " << A[i];
	return 0;
}

