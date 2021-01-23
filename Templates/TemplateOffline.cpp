//Source: https://usaco.guide/general/code-con?lang=cpp#c
//Implementation: https://github.com/bqi343/USACO/blob/master/Implementations/content/contest/TemplateVeryShort.cpp
#include <bits/stdc++.h> // see C++ Tips & Tricks
using namespace std;

#define endl "\n"
////Make sure to define this 
//in case you accidentally use endl instead of "\n" to make a new line
//https://usaco.guide/general/fast-io/#fast-output
//https://codelearn.io/sharing/thu-thuat-cpp-hay-trong-lap-trinh-thi-dau-cho-nguoi-moi-bat-dau

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
#define trav(a,x) for (auto& a: x)

void setIO(string name = "") { // name is nonempty for Offline Contest file I/O
	ios_base::sync_with_stdio(false); cin.tie(nullptr); // see Fast Input & Output
	// alternatively, cin.tie(0)->sync_with_stdio(0);
	if (sz(name)) {
		freopen((name+".INP").c_str(), "r", stdin); // see Input & Output
		freopen((name+".OUT").c_str(), "w", stdout);
	}
	else{
		freopen(input.txt,"r",stdin);
	}
}

//constant initialization
const string yes="YES",no="NO";
const int mod=1e9+7;
const int maxn=2e5+10;

//variables used for the current problem
int n;

void solve(){
	cin >> n;
	cout << n;
	return;
}

int main() {
	setIO();
	solve();
	return 0;
}
