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
        int N; cin >> N;
        string s; cin >> s;
        int pre = -1;
        bool flag = true;
        each(ch,s) {
            if (ch!='-') {
                if (pre == -1) pre = ch-'0';
                if (pre > ch-'0') {
                    cout << 0 << endl; flag = false;
                    break;
                }
                pre = ch-'0';
            }
        }
        if (!flag) continue;
        vector<vi> dp(N+1,vi(10));
        FOR(digit,1,10) dp[0][digit]=1;
        FOR(i,1,N+1) {
            if (s[i-1]!='-') dp[i][s[i-1]-'0'] = dp[i-1][s[i-1]-'0'];
            else FOR(digit,1,10) dp[i][digit] = dp[i-1][digit];
            FOR(digit,2,10) {
                dp[i][digit] += dp[i][digit-1];
                dp[i][digit] %= MOD;
            }
        }
        cout << dp[N][9] << endl;
    }
    return 0;
}