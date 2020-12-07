#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <sstream>
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
    //Write your code here.
    int n,t=1,m=0; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    set<int> b(a.begin(),a.end());
    cout << b.size() << endl;
    for(int i=0;i<n-1;++i){
        if(a[i]==a[i+1]){
            ++t;
        }
        else {
            cout << a[i] << " " << t << endl;t=1;
        }
    }   cout << a.back() << " " << t;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
