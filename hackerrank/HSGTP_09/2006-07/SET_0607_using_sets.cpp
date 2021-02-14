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

void setIO(string name = "") {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
    else{
        #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("error.txt", "w", stderr);
        #endif
    }
}

//constant initialization
const string yes="YES",no="NO";
const int MOD=1e9+7; //998244353
const int maxn=2e6+10;
const ll INF = 1e18; //Not too close to LLONG_MAX

//variables used for the current problem
int n,cnt[maxn]; set<int> st;

void solve(){
    cin >> n;
    F0R(i,n) {
        int x; cin >> x;
        ++cnt[x+(int)1e6]; st.insert(x);
    }
    if (sz(st)<3) {
        cout << 0; return;
    }
    for (auto it = ++st.begin(); it != --st.end(); ++it) {
        auto it1 = it; --it1; int cnt1 = 0;
        auto it2 = it; ++it2; int cnt2 = 0;
        for(;it1!=it;++it1) {
            cnt1 += cnt[*it1+(int)1e6];
        }
        for(;it2!=st.end();++it2) {
            cnt2 += cnt[*it2+(int)1e6];
        }
        if (cnt1 == cnt2) {
            cout << 1; return;
        }
    }
    cout << 0;
    return;
}

int main() {
    setIO();
    solve();
    return 0;
}
