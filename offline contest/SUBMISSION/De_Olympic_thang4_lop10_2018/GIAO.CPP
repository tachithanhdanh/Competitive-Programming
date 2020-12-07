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

int n,x=INT_MIN,y=INT_MAX,tmpx,tmpy;

void solve(){ //Write your code here.
    cin >> n;
    while (n--) {
        cin >> tmpx >> tmpy;
        x=max(tmpx,x);
        y=min(tmpy,y);
    }
    cout << (x<y? y-x : 0);
    return;
}

int main(){
    //Read input from STDIN, then print the output to STDOUT.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("GIAO.INP","r",stdin);
    freopen("GIAO.OUT","w",stdout);
    //cin >> t; 
    //while (t--) 
        solve();
    return 0;
}
