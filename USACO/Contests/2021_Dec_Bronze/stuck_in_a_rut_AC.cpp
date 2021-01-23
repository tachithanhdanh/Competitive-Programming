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
#define trav(a,x) for (auto& a: x)

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
const int MOD=1e9+7;
const int maxn=1e6+10;
const ll INF = 1e18; //Not too close to LLONG_MAX

//variables used for the current problem
int n,current;

struct COW{
	int x,y,timestop; char dir;
} cows[51];

struct Intersection{
	int i,j; //store the number of i-th and j-th cows intersect.
	int time_i; //Time when i-th cow is blocked by the rut created by the j-th cow.
	int time_j; //store the time when j-th cow reaches to the position needed to block the i-th cow.
	bool used; //store the state of the intersection (whether they have been taken to process or not)
} I[51*51];

void find_all_intersection(){
	F0R(i,n) F0R(j,n){
		if (cows[i].dir == cows[j].dir) continue; //Both cows have the same direction so they will never meet.
		// Possibly flip coordinates so that for simpllicity, we can
    	// assume without loss of generality that cow i is moving north, and cow j east
    	int xi = cows[i].x, yi = cows[i].y, xj = cows[j].x, yj = cows[j].y;
    	if (cows[i].dir == 'E') { swap(xi,yi); swap(xj,yj); }
    	if (yi > yj) continue; // cow i already north of cow j?
		if (xi < xj) continue; // cow i already west of cow j?
		if (yj - yi <= xi - xj) continue; // cow i passes before cow j can cut her off
		Intersection Inew = { i, j, yj-yi, xi-xj, false };
		I[current] = Inew; ++current;
	}
	return;
}

//http://www.usaco.org/index.php?page=viewproblem2&cpid=1061
//http://www.usaco.org/current/data/sol_prob3_bronze_dec20.html (I used the second solution)

void solve(){ //Your solution starts here.
	cin >> n;
	F0R(i,n){
		cin >> cows[i].dir >> cows[i].x >> cows[i].y; 
	}
	find_all_intersection();
	while (true){
		int earliest = -1;
		F0R(i,current) if (!I[i].used && (earliest == -1 || I[i].time_i < I[earliest].time_i)) earliest = i;
		if (earliest == -1) break;
		Intersection &E = I[earliest];
		if (cows[E.i].timestop == 0 && (cows[E.j].timestop == 0 || cows[E.j].timestop > E.time_j)) cows[E.i].timestop = E.time_i;
		E.used = true;
	}
	F0R(i,n){
		if (cows[i].timestop) cout << cows[i].timestop;
		else cout << "Infinity";
		cout << endl;
	}
	return;
}

int main() {
	setIO();
	solve();
	//brute_force();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl;
	return 0;
}