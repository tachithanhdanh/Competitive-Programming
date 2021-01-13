#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <climits>
#include <cfloat>
#include <cstring>
#include <fstream>
#include <vector>
#include <iterator>
#include <typeinfo>
#include <set>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <string>
#include <sstream>

#define endl "\n"
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

ll n,m,a,b;
 
void solve(){ //Your solution starts here.
    cin >> n >> m >> a >> b;
    cout << min(n*a,min((n+m-1)/m*b,(n/m)*b+(n%m)*a));
    return;
}

int main(){
    //Read input from STDIN, then print the output to STDOUT.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("BTICK.INP","r",stdin);
    //freopen("BTICK.OUT","w",stdout);
    //cin >> t; 
    //while (t--) 
        solve();
    return 0;
}