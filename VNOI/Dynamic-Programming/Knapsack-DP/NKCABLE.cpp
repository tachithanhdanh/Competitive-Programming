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

//for printing variables when debugging
#ifdef LOCAL
#define debug(x) cout << (#x) << " is " << (x) << endl
#else
#define debug(x)
#endif // LOCAL

//Set min-max value.
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; } // set a = min(a,b)
template<class T> bool ckmax(T& a, const T& b) { return b > a ? a = b, 1 : 0; } // set a = max(a,b)

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
const int MX = 3e4+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
ll dp[2][MX];
int N, dist[MX];

int main() {
	setIO();
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N;
	for (int i = 0; i < N - 1; ++i) cin >> dist[i];
	for (int i = 0; i < 2; ++i) for (int j = 0; j <= N; ++j) dp[i][j] = INF;
	dp[1][1] = dist[0];
	for (int i = 2; i <= N - 1; ++i) {
		ckmin(dp[1][i],min(dp[0][i-1],dp[1][i-1])+dist[i-1]);
		dp[0][i] = dp[1][i-1];
	}
	cout << dp[1][N-1];
	return 0;
}
/* Gọi dp[2][N] là độ dài cáp ít nhất cần nối với định nghĩa từng mảng như sau:
-dp[0][N] nghĩa là tại vị trí thứ N, KHÔNG NỐI CÁP VỚI N+1
-dp[1][N] nghĩa là tại vị trí thứ N, CÓ NỐI CÁP VỚI N+1
*Ta có một số nhận xét như sau:
Nhận xét 1: dp[0][1] = không tồn tại vì nếu không nối cáp cho máy số 1 với máy số 2 thì coi như máy đó sẽ không bao giờ được nối cáp
(giải thích: trước máy số 1 không có máy nào để nối cáp cả)
Vì thế ở dp[0][1] ta có thể gán giá trị nào đó cực lớn (i.e: +INF) để biểu thị là dp[0][1] không tồn tại (đáp án yêu cầu lấy min thì gán số +INF là phù hợp nhất)
Nhận xét 2: đáp án cuối cùng là dp[1][N-1], không thể dp[0][N-1] vì nếu không gắn cáp cho N-1 với N thì N sẽ không bao giờ được kết nối
Nhận xét 3: nếu tại vị trí i nào đó (i khác 1 và N-1 do đã giải thích ở trên) mà ta không gắn cáp, ta bắt buộc phải gắn cáp cho vị trí i-1 để nó nối với i
(giải thích: nếu ở i không gắn cáp thì trước đó nó phải được kết nối với i-1 chứ không là i sẽ không bao giờ được kết nối)

Sau 2 nhận xét trên, ta rút ra công thức truy hồi như sau:
Gọi i là vị trí bất kỳ nào đó với (1 < i < N-1), ta có:

dp[1][i] = dist[i-1] + min(dp[0][i-2],dp[1][i-2])
dp[0][i] = dp[1][i-1]

TH đặc biệt (base case):
dp[1][1] = dist[0]
dp[0][1] = INF
dp[0][N-1] = INF
dp[1][N-1] là đáp án
INF biểu thị ở đó không tồn tại cách nối dây

*/
