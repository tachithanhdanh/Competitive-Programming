#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
 
using namespace std;

using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
 
#define endl "\n" 
#define hash_set unordered_set 
#define hash_map unordered_map
#define all(x) begin(x), end(x) 
#define rall(x) (x).rbegin(), (x).end()
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mtp make_tuple

void setIO(string name =""){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	if (name.size()){
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
	else {
		#ifndef ONLINE_JUDGE 
		freopen("input.txt", "r", stdin); 
		freopen("error.txt", "w", stderr); 
		freopen("output.txt", "w", stdout); 
		#endif 
	}
	return;
}

struct rectangle
{
	int x1,x2,y1,y2;
};

int intersect(rectangle a, rectangle b){
	int xOverlap=max(0,min(a.x2,b.x2)-max(a.x1,b.x1));
	int yOverlap=max(0,min(a.y2,b.y2)-max(a.y1,b.y1));
	return xOverlap*yOverlap;
}

int area(rectangle a){
	return (a.x2-a.x1)*(a.y2-a.y1);
}

rectangle a[3]; int maxX,maxY;

void solve(){ //Your solution starts here.
	//http://www.usaco.org/current/data/sol_billboard_bronze_dec17.html
	//http://www.usaco.org/index.php?page=viewproblem2&cpid=759
	for (int i=0;i<3;++i){
		cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
	}
	cout << area(a[0])+area(a[1])-intersect(a[0],a[2])-intersect(a[1],a[2]);
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
	string name="billboard";
	setIO(name);
	//cout.tie(NULL);
	//cin >> t;
	//while (t--)
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}
 
