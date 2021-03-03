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
		if (X[i] > 0) maxX = max(maxX, X[i]);
		if (X[i] < 0) minX = min(minX, X[i]);
	}
	cout << (maxX + (-minX)) * 2;
	return 0;
}

