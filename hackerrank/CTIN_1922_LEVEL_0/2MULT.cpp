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

int a,b;

int s(int n){
    int ans=0;
    while (n){
        ans+=n%10;
        n/=10;
    }
    return ans;
}

void solve(){ //Write your code here.
    cin >> a >> b;
    cout << s(a)*s(b);
    return;
}

int main(){
    //Read input from STDIN, then print the output to STDOUT.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("2MULT.INP","r",stdin);
    //freopen("2MULT.OUT","w",stdout);
    //cin >> t; 
    //while (t--) 
        solve();
    return 0;
}
