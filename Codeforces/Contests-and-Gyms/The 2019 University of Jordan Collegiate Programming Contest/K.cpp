// Author: Unknown
#include <bits/stdc++.h>

using namespace std;

int n, a[21];
long long ans;
vector<int> b;

void Try(int i) {
    if (i == n) {
        long sum{};
        for (auto& x : b) sum |= x;
        ans += sum;
        return;
    }
    b.push_back(a[i]); Try(i + 1);
    b.pop_back(); Try(i + 1);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    Try(0);
    cout << ans;
}
