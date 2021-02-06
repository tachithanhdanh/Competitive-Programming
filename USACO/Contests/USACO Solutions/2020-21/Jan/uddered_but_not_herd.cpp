#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

using ll = long long;

//vectors
using vi = vector<int>;
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define rsz resize
#define pb push_back()

//pairs
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

//loops
#define trav(a,x) for(auto& a : x)

void setIO(){
    cin.tie(0)->ios::sync_with_stdio(0);
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif // LOCAL
}

//constant initialization
const int maxn = 1e5+10;

//variables used for the current problem
string alphabet,s; int cnt,pos,i;

void solve(){
    cin >> alphabet >> s;
    while (i<sz(s)){
        for (pos=0;pos<26;++pos){
            if (alphabet[pos]==s[i]){
                ++i;
            }
        }
        ++cnt;
    }
    cout << cnt;
    return;
}

int main(){
    setIO();
    solve();
    return 0;
}
