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
int n,ans; vector<vi> grid; vector<vector<bool>> used;

bool checkvalid1(){
    bool flag = true;
    F0R(i,n-1) F0R(j,n-1){
        int num = used[i][j] + used[i][j+1] + used[i+1][j] + used[i+1][j+1];
        flag = flag && num == 2;
    }
    return flag;
}

bool checkvalid2(const int &k){
    bool flag = true;
    if (k==0 || k==1) return true;
    F0R(i,k-2) F0R(j,n-1){
        int num = used[i][j] + used[i][j+1] + used[i+1][j] + used[i+1][j+1];
        flag = flag && num == 2;
    }
    //cout << boolalpha << flag << endl;
    return flag;
}

void dfs1(int k){
    if (k==n){
        int value = 0;
        if (checkvalid1()){
            F0R(i,n) F0R(j,n) if (used[i][j]) value += grid[i][j];
        }
        ans = max(ans,value); return;
    }
    F0R(i,n) FOR(j,i+1,n){
        used[k][i] = used[k][j] = true;
        dfs1(k+1);
        used[k][i] = used[k][j] = false;
    }
}

void dfs2(const int row,const int col){
    if (row==n){
        int value = 0;
        if (checkvalid1()){
            F0R(i,n) F0R(j,n) if (used[i][j]) value += grid[i][j];
        }
        ans = max(ans,value); return;
    }
    if (col >= n) {
        dfs2(row+1,0); return;
    }
    if (col == 0) if (!checkvalid2(row)) return;
    used[row][col] = true;
    dfs2(row,col+1);
    used[row][col] = false;
    dfs2(row,col+1);
    return;
}

void solve(){
    cin >> n;
    grid.rsz(n);
    trav(a,grid) a.rsz(n);
    F0R(i,n) F0R(j,n) cin >> grid[i][j];
    if (n<=4){
        used.rsz(n);
        trav(a,used) a.rsz(n,false);
        dfs1(0);
        cout << ans;
    }
    else if (n<=10){
        used.rsz(n);
        trav(a,used) a.rsz(n,false);
        dfs2(0,0);
        cout << ans;
    }
    return;
}

int main(){
    setIO();
    solve();
    return 0;
}
