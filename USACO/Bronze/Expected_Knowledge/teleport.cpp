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
#include <unordered_set>
#include <unordered_map>
#include <utility>

#define endl "\n"
#define pub push_back
#define pob pop_back
#define ins insert
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef short int si;

si a,b,x,y,ans1,ans2,ans3;

void solve(){ http://www.usaco.org/index.php?page=viewproblem2&cpid=807
    cin >> a >> b >> x >> y;
    ans1=abs(a-b); 
    ans2=abs(a-x)+abs(b-y);
    ans3=abs(a-y)+abs(b-x);
    cout << min(ans1,min(ans2,ans3));
    return;
}

int main(){
    //Read input from STDIN, then print the output to STDOUT.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    freopen("teleport.in","r",stdin);
    freopen("teleport.out","w",stdout);
    //cin >> t; 
    //while (t--) {
        //cout << "Case #" << ++cnt << ": "; 
        solve();
    //}
    return 0;
}

