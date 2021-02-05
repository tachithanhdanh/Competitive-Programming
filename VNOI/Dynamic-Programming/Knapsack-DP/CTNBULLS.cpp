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
#define each(a,x) for (auto& a: x)

//constant initialization
const string yes="YES\n",no="NO\n";
const int MOD=1e9+7; //998244353
const ll INF = 1e18; //Not too close to LLONG_MAX

int dp[100005];
//http://vnoi.info/problems/list_solutions/CTNBULLS/
int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif // LOCAL
	int N, K; cin >> N >> K;
	dp[0] = 1;
	FOR(i,1,N+1) {
		//Nếu i - K - 1 >= 0 thì có 2 trường hợp xảy ra:
		//TH1: Nhét B vào, như vậy thì có dp[i-K-1] cách xếp 
		//vì khi ta nhét B và thì từ i-K đến i-1 phải xếp TOÀN BỘ CHỮ C VÀO (do nhét chữ B vào sẽ không thỏa YCBT)
		//nên ở phân đoạn từ i-K đén i-1 chỉ có một cách xếp và số cách xếp ở TH này phụ thuộc vào dp[i-K-1]
		//@param
		//TH2: Nhét C vào, thì ở đây ta có số cách xếp ở i = số cách xếp ở i-1 vì không bị ràng buộc gì cả.
		if (i-K-1>=0) dp[i] += dp[i-K-1] + dp[i-1];

		//Đây là tình huống cái gap chưa đủ lớn và ở đây cũng có 2 trường hợp nhỏ hơn để xét:
		//TH1: Đặt con cái (C) vô thì số cách xếp ở i = số cách xếp ở i-1 vì không bị ràng buộc gì cả.
		//TH2: Đặt con đực (chữ B) vô thì chỉ có một cách vì trước nó hiển nhiên toàn chữ C và KHÔNG CÓ CHỮ B NÀO (cái gap không đủ lớn để đặt chữ B trước đó)
		else dp[i] += dp[i-1] + 1;
		dp[i] %= 2111992;
	}
	cout << dp[N];
	return 0;
}
