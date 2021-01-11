//Source: https://usaco.guide/general/code-con?lang=cpp#c
//Implementation: https://github.com/bqi343/USACO/blob/master/Implementations/content/contest/TemplateVeryShort.cpp
#include <bits/stdc++.h> // see C++ Tips & Tricks
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