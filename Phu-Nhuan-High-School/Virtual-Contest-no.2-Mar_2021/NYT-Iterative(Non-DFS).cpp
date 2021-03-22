#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

#define endl "\n"

using ll = long long;

//vectors
using vi = vector<int>;
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define pb push_back

//pairs
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (sz(name)) {
        freopen((name+".INP").c_str(), "r", stdin); // see /general/io
        freopen((name+".OUT").c_str(), "w", stdout);
    }
}

int n, t, a[30005], pos=1; 

int main(){
    setIO("NYT");
    cin >> n >> t;
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        a[i] += i;
    }
    if (pos == t) {
        cout << "YES"; return 0;
    }
    while (pos != n) {
        pos = a[pos];
        if (pos == t) {
            cout << "YES"; return 0;
        }
    }
    cout << "NO";
    return 0;
}

