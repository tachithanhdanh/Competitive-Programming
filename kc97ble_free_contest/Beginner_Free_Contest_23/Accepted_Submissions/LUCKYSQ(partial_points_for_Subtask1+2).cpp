#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cfloat>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <array>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <iterator>
#include <ctime>
#include <tuple>
#include <numeric>
 
using namespace std;

using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;

#define ar array
#define endl "\n" 
#define hash_set unordered_set 
#define hash_map unordered_map

//vector
#define all(x) begin(x), end(x) 
#define rall(x) (x).rbegin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define pf push_front
#define ft front()
#define bk back()

//pairs and tuples
#define f first
#define s second
#define mp make_pair
#define mtp make_tuple

void setIO(string name =""){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	if (name.size()){
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
	else {
		#ifdef LOCAL 
		freopen("input.txt", "r", stdin); 
		freopen("error.txt", "w", stderr); 
		freopen("output.txt", "w", stdout); 
		#endif 
	}
	return;
}

//int cnt,t;
int p[1005],a[1005][1005],sum,x,ans,n;
//ld t1,t2;

void solve(){
	//t1=(ld)clock()/CLOCKS_PER_SEC;
	cin >> n >> x;
	//ans=0;
	for (int i=0;i<n;++i){
		cin >> p[i];
	}
	//calculate the initial value of the input matrix
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			a[i][j]=p[i]+p[j];
			//cerr << a[i][j] << " ";
		}
		//cerr << endl;
	}
	//cerr << endl;
	// Filling first row and first column 
	for (int i=1;i<n;++i){
		//Filling the first row
		a[0][i]+=a[0][i-1];
	}
	for (int i=1;i<n;++i){
		//Filling the first column
		a[i][0]+=a[i-1][0];
	}
	// updating the values in the cells 
    // as per the general formula 
    for (int i = 1; i < n; i++) { 
        for (int j = 1; j < n; j++){
        	// values in the cells of new 
            // array are updated
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
        }  
    }
    /*
    for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			//a[i][j]=p[i]+p[j];
			cerr << a[i][j] << " ";
		}
		cerr << endl;
	}
	*/
	const int nn=(n/6<=10 ? n : n/6);
    for (int m=1;m<=nn;++m){
    	for (int i=0;i<=n-m;++i){
    		for (int j=0;j<=n-m;++j){
    			if (i==0 && j==0){
    				sum=a[m-1][m-1];
    			}
    			else if (i==0){
    				//cerr << i << " " << j << endl;
    				//sum=a[i][j+m-1]-a[i][j];
    				sum=a[i+m-1][j+m-1]-a[i+m-1][j-1];
    				//cerr << sum << endl;
    			}
    			else if (j==0){
    				//cerr << i << " " << j << endl;
    				//sum=a[i+m-1][m-1]-a[0][m-1];
    				sum=a[i+m-1][j+m-1]-a[i-1][j+m-1];
    				//cerr << sum << endl;
    			}
    			else {
    				sum=a[i+m-1][j+m-1]-a[i-1][j+m-1]-a[i+m-1][j-1]+a[i-1][j-1];
    			}
    			if (sum==x) {
    				//cerr << i+m-1 << " " << j+m-1 << endl;
    				++ans;
    			}
    		}
    	}
    }
    cout << ans << endl;
    //t2=(ld)clock()/CLOCKS_PER_SEC;
    //cerr << "Test " << ++cnt << " took " << t2-t1 << " secs." << endl;
	return;
}
// you should actually read the stuff below
// read!read!read!read!read!read!read!read!read!
// ll vs. int!
 
/* stuff you should look for
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
*/
int main(){
	//string name="socdist1";
	string name="";
	setIO(name);
	//cout.tie(NULL);
	//generate();
	//cin >> t;
	//while (t--)
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}