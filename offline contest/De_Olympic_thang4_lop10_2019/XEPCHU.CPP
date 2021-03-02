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

int n,m; string s; vector <string> s1; //,s2;

void solve(){ //Write your code here.
    while (cin >> s){
        m+=s.size();
        //if (s[0]>='A' && s[0]<='Z') 
        s1.push_back(s);
        //else s2.push_back(s);
        ++n;
    }

    cout << n << " " << m+n-1 << endl;
    sort(s1.begin(),s1.end());
    //sort(s2.begin(),s2.end());
    for (int i=0;i<s1.size();++i) cout << s1[i] << " ";
    //for (int i=0;i<s2.size();++i) cout << s2[i] << " ";
    return;
}

int main(){
    //Read input from STDIN, then print the output to STDOUT.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("XEPCHU.INP","r",stdin);
    freopen("XEPCHU.OUT","w",stdout);
    //cin >> t; 
    //while (t--) 
        solve();
    return 0;
}
