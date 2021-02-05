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
const int maxN = 1005;
const int maxT = 1005;

ll dp[maxT][maxN];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif //LOCAL
	freopen("time.in","r",stdin);
	freopen("time.out","w",stdout);
	ll N, M, C;
	cin >> N >> M >> C;
	vector<pi> edges(M); vector<ll> moonies(N+1);
	FOR(i,1,N+1) cin >> moonies[i];
	each(E,edges) cin >> E.f >> E.s;
	memset(dp, -1, sizeof(dp));
	dp[0][1] = 0;
	ll max_profit = 0;
	FOR(T,1,maxT) {
		each(E,edges) {
			int a = E.f;
			int b = E.s;
			if (dp[T-1][a] >= 0) {
				dp[T][b] = max(dp[T][b], dp[T-1][a] + moonies[b]);
			}
		}
		max_profit = max(max_profit, dp[T][1] - C * T * T);
	}
	cout << max_profit;
	return 0; //You should actually read the stuff at the bottom
}

/*	Official analysis: http://www.usaco.org/current/data/sol_time_gold_jan20.html
	Giải thích thuật
	Gọi dp[T][N] là mảng dp cho biết được số tiền NHIỀU NHẤT có thể kiếm được vào ngày thứ T ở thành phố N
	Đầu tiên ta gán giá trị của toàn bộ mảng dp này là -1 (nghĩa là chưa có kiếm được đồng nào cả lmao).
	According to the problem statement
	"Note that it may be optimal for Bessie to visit no cities aside from city 1, in which case the answer would be zero."
	Có nghĩa là Bessie có thể KHÔNG ĐI THĂM BẤT KỲ THÀNH PHỐ NÀO ngoài thành phố 1 (nói cách khác, Bessie ở yên ở thành phố 1)
	Thì trong trường hợp trên, số tiền tối đa mà Bessie có thể kiếm được là 0 moonies. (vì m1 = 0)
	Therefore, in the base case, dp[0][1] = 0. (Không đi ngày nào cả nên nó là ngày 0)
	Đề bài yêu cầu ta tìm số tiền nhiều nhất có thể kiếm sau khi đi một số ngày nào đó nhưng cuối cùng PHẢI TRỞ VỀ THÀNH PHỐ 1
	Nghĩa là ta phải in max(dp[i][1]) với i là ngày thứ i (theo official editorial thì ta chỉ cần tính từ ngày 1 đến hết ngày 1000 là đủ)
	Vậy thì làm sao để tính được dp[i][1], câu trả lời thật ra rất đơn giản:
	Ta chỉ việc duyệt từ ngày 1 đến ngày 1000 và ở ngày thứ i,
	ta sẽ duyệt qua danh sách cạnh (edges list) và kiểm tra xem trong ngày đó thì ta có thể thăm được Thành phố nào không rồi tính ra số tiền có thể tạo ra được khi thăm thành phố đó
	(Để biết được ta có thăm được thành phố b vào ngày T hay không ta kiểm tra thử xem ta có thể thăm thành phố a vào ngày T-1 hay không rồi mới tìm max moonies cho ngày đó)
	Sau khi duyệt xong danh sách cạnh ở ngày thứ T, ta sẽ kiểm tra xem vào ngày thứ T thì ta có về được thành phố 1 với tiền không, sẽ có 2 TH:
	TH 1: Ngày thứ T thì không về TP 1 được, lúc này số tiền kiếm được là -1 nên ta skip.
	TH 2: Về được, lúc này ta kiểm tra xem so với max profit thì lời hơn hay lỗ rồi gán giá trị cho max profit nếu ta thu được nhiều tiền hơn max_profit
	Đơn giản vậy thôi
	Some more clarifications: https://discord.com/channels/516125324711297024/516128259415736320/806855936101842945
*/
