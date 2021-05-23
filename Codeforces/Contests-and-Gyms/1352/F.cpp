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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif // LOCAL
    int T; cin >> T;
    while (T--) {
        int N1, N2, N3;
        cin >> N1 >> N2 >> N3;
        if (!N2) {
            if (N1) {
                F0R(i,N1+1) cout << 0;
                cout << endl;
            }
            else { //N1 = 0 and N3 != 0
                F0R(i,N3+1) cout << 1;
                cout << endl;
            }
        }
        else {
            F0R(i,N1) cout << 0;
            cout << 0 << 1;
            F0R(i,N3) cout << 1;
            F0R(i,N2-1) {
                cout << (i&1);
            }
            cout << endl;
        }
    }
	return 0;
}
