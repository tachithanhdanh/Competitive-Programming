#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("feast.in","r",stdin);
    freopen("feast.out","w",stdout);
    int T,A,B;
    cin >> T >> A >> B;
    bool dp[2][T+1];
    memset(dp,false,sizeof(dp));
    dp[0][0] = true;
    dp[1][0] = true;
    for (int i = 0; i < T + 1; ++i) {
        if (i-A>=0) dp[0][i] |= dp[0][i-A];
        if (i-B>=0) dp[0][i] |= dp[0][i-B];
        dp[1][i/2] |= dp[0][i];
    }
    for (int i = 0; i < T + 1; ++i) {
        if (i-A>=0) dp[1][i] |= dp[1][i-A];
        if (i-B>=0) dp[1][i] |= dp[1][i-B];
    }
    for (int i = T; i >= 0; --i) if (dp[0][i] || dp[1][i]) {
        cout << i;
        break;
    }
    return 0;
}