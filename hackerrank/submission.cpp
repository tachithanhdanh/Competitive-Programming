#include <bits/stdc++.h>

#define endl "\n"
#define pub push_back
#define pob pop_back
//#define rep(i, n) for (int i = 0; i < (int)n; ++i)
//#define rep(i, j, n) for (int j=(int)i;j < (int)n; ++j)

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef float fl;
typedef short int si;
typedef long double ld;
typedef double db;
typedef unsigned int ui;
typedef unsigned short int usi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

string t,ans; int h;

void solve(){  //Write your code here.
    cin >> t; h=stoi(t.substr(0,2));
    cout << h;
    cout << t.substr(t.size()-3);
    if (t.substr(t.size()-3)=="AM"){
        cout << boolalpha << (h==12? true : false );
        if (h==12) {
            t[0]='0';t[1]='0';
        }
        t.pob(); t.pob();
        cout << t << endl;
    }
    else { string hour;
        if (h!=12) {
            h+=12;
        }
        t.pob(); t.pob();
        hour=to_string(h);
        ans+=hour; ans+=t.substr(2);
        cout << ans << endl;
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //int t; cin >> t;
    //while (t--){
    solve();
    //}
    return 0;
}
