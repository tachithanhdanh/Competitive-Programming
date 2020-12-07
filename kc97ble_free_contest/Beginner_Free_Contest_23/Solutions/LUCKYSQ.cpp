#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x) {
    char c;
    while (!isdigit(c = getchar()));
    x = c - 48;
    while (isdigit(c = getchar()))
        x = (x << 3) + (x << 1) + c - 48;
}
const int N = 1e6 + 11;
int n, X, cnt[N], a[N], ok[N];
int64_t s[N];
int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    read(n);
    read(X);
    for (int i = 1; i <= n; i++) {
        read(s[i]);
        s[i] += s[i - 1];
    }
    int64_t res = 0;
    int lim = min(X, n);
    for (int x = 1; x <= lim; x++)
        if (X % x == 0) {
            int xx = X / x;
            for (int i = x; i <= n; i++) {
                if (xx >= s[i] - s[i - x]) {
                    cnt[s[i] - s[i - x]]++;
                    ok[i] = 1;
                }
            }
            for (int i = x; i <= n; i++)
                if (ok[i])
                    res += cnt[xx - s[i] + s[i - x]];
            for (int i = x; i <= n; i++)
                if (ok[i])
                    cnt[s[i] - s[i - x]] = 0,
                    ok[i] = 0;
        }
    cout << res << '\n';
}
