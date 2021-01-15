#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

using ll = long long;

//vector
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

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a : x)

void setIO(string name = "") { 
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
	else{
		#ifdef LOCAL
		freopen("input.txt", "r", stdin);  
		freopen("output.txt", "w", stdout); 
		freopen("error.txt", "w", stderr);
		#endif 
	}
}

//constant initialization
const string yes="YES",no="NO";
const int mod=1e9+7;
const int maxn=1e5+10;
const ll INF = 1e18;

//variables used for the current problem
int n; ll a[maxn],ans=-INF,cur=INF,f,s,temp_f;
//https://www.geeksforgeeks.org/maximum-subarray-sum-using-prefix-sum/
void solve(){
	cin >> n;
	FOR(i,1,n+1) {
		cin >> a[i]; a[i]+=a[i-1]; //Calculate the prefix sum of array a
	}
	FOR(i,0,n+1) {
		if (ans<a[i]-cur){ 
			//If the sum of the current subarray
			//is greater than maximum subarray sum so far
			ans = a[i]-cur; //Store the new value of the maximum subarray
			s = i; //Update the position for the last element
			f = temp_f; //And the first element of that subarray
		}
		if (cur>a[i]){
			cur = a[i]; //Calculate the min prefix sum in the array
			temp_f = i+1; //Temporarily store the position of the min prefix sum in the array
		}
	}
	cout << f << " " << s << endl << ans;
	return;
}

int main() {
	setIO();
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl;
	return 0;
}
