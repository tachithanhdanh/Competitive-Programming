#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

using ll = long long;

//vectors
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

//loops
#define FOR(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
#define F0R(i,a) FOR(i,0,a)
#define trav(a,x) for (auto& a : x)

void setIO(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif // LOCAL
}

//constant initialization
const int maxn = 2e5+10;

//variables used for the current problem
int n,k; vi cows; vector<pi> pos;

void solve(){
    cin >> n >> k;
    cows.rsz(n+1); pos.rsz(k);
    iota(all(cows),0);
    F0R(i,k) cin >> pos[i].f >> pos[i].s;
    if (n<=100 && k<=200){
        vector<set<int>> ans;
        ans.rsz(n+1); FOR(i,1,n+1) ans[i].insert(i);
        F0R(j,k) F0R(i,k){
            swap(cows[pos[i].f],cows[pos[i].s]);
            ans[cows[pos[i].f]].insert(pos[i].f);
            ans[cows[pos[i].s]].insert(pos[i].s);
        }
        FOR(i,1,n+1){
            cout << sz(ans[i]) << endl;
        }
    }
    else if (n<=2000 && k<=4000){
        vector<vector<bool>> check;
        check.rsz(n+1);
        FOR(i,1,n+1) check[i].rsz(n+1,false);
        FOR(i,1,n+1) check[i][i]=true;
        F0R(j,k+1) F0R(i,k){
            check[cows[pos[i].f]][pos[i].f] = true;
            check[cows[pos[i].s]][pos[i].s] = true;
            swap(cows[pos[i].f],cows[pos[i].s]);
        }
        FOR(i,1,n+1) {
            int cnt = 0;
            FOR(j,1,n+1) {
                cnt+=check[i][j];
            }
            cout << cnt << endl;
        }
    }
    else{

    }
    return;
}

int main(){
    setIO();
    solve();
    return 0;
}
