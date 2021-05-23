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
        int N, K; cin >> N >> K;
        vi a(N); each(b,a) cin >> b;
        vi cnt((int)1e6+10);
        int l = 0, r, cost = 0, ans = 0;
        for (r = 0; r < N; ++r) {
            ++cnt[a[r]];
            if (cnt[a[r]] == 1) cost += a[r]; //If it is bought for the first time.
            while (cost > K) {
                if (cnt[a[l]] == 1) //If it is the first item with rate a[l]
                    cost -= a[l];
                --cnt[a[l]]; ++l;
            }
            ans = max(ans, r - l +1);
        }
        cout << ans << endl;
    }
    return 0;
}