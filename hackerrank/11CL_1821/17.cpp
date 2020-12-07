#include <bits/stdc++.h>
#define endl "\n"
typedef long long int ll;
typedef unsigned long long int ull;
typedef float fl;
typedef short int si;
typedef long double ld;
typedef double db;
typedef unsigned int ui;
typedef unsigned short int usi;
using namespace std;

void solve(){
    int a,b; cin >> a >> b;
    vector<int> c(a,0);
    for (int i=0;i<a;++i){
        cin >> c[i];
    }
    vector<int> d(c.begin(),c.end());
    sort(d.rbegin(),d.rend());
    for(int i=0;i<a;++i){
        if (c[i]==d[b-1]){
            cout << (i+1) << " " << c[i] << endl;
            break;
        }
    }   return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
