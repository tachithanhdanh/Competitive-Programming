#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

#define endl "\n"

using ll = long long;

//vectors
using vi = vector<int>;
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define pb push_back

//pairs
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin); // see /general/io
		freopen((name+".out").c_str(), "w", stdout);
	}
}

//constant initialization
const string yes="YES\n",no="NO\n";
const int MOD = 1e9+7; //998244353
const int MX = 1e3+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
const vector<string> zodiac = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
const string pre = "previous";

//variables used for the current problem
int N;
vector<string> vs;
string cow1, cow2, state, year;
struct COW{
	string name, yn;
	int y;
};

int main() {
	setIO();
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif //LOCAL
	cin >> N;
	vector<COW> cow(N+1);
	cow[0] = {"Bessie","Ox",0};
	for (int i = 1; i <= N; ++i) {
		string a;
		cin >> cow1 >> a >> a >> state >> year >> a >> a >> cow2;
		int y;
		for (int j = 0; j < i; ++j) {
			if (cow2 == cow[j].name) {
				int c1, c2, deltaY;
				for (int k = 0; k < 12; ++k) {
					if (cow[j].yn == zodiac[k]) c2 = k;
					if (year == zodiac[k]) c1 = k;
				}
				if (state == pre) {
					if (c1 < c2) y = cow[j].y - (c2 - c1);
					else y = cow[j].y - (12 - (c1 - c2));
				}
				else {
					 if (c1 > c2) y = cow[j].y + (c1 - c2);
					 else y = cow[j].y + (12 - (c2 - c1));
				}
				break;
			}
		}
		cow[i] = {cow1,year,y};
	}
	for (int i = 0; i <= N; ++i) {
		if (cow[i].name == "Elsie") {
			cout << abs(cow[i].y) << endl;
			break;
		}
	}
	return 0;
}
