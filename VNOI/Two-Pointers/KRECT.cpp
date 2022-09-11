/**
 *    author:    tachithanhdanh
 *    created:   2022-09-11    07:35:28
**/

#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

#ifdef LOCAL
#include "debugging.h"
#endif

#define endl "\n"

using ll = long long;
using str = string;

// vectors
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using vs = vector<str>;
#define all(x) begin(x), end(x)
#define sz(x) int(size(x))
#define pb push_back

// pairs
using pi = pair<int, int>;
using vpi = vector<pi>;
#define f first
#define s second
#define mp make_pair

// set min-max value.
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; } // set a = min(a,b)
template<typename T> bool ckmax(T& a, const T& b) { return b > a ? a = b, 1 : 0; } // set a = max(a,b)

// constant initialization
const str yes="YES\n", no="NO\n";
const int MOD = 1e9 + 7; // 998244353
const int MX = 2e5 + 10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
const char dc[4] = {'r', 'u', 'l', 'd'};
const bool multitest = false;

// Ý tưởng: chọn cố định 2 hàng r1 r2 rồi sau đó chạy 2 con trỏ c1, c2 trên cột
// r1 <= r2, c1 <= c2
// dùng mảng đếm cnt để đếm số kí tự khác nhau trong bảng 
// Độ phức tạp: O(M^3 * N)

void solve() {
	int M, N, K;
	cin >> M >> N >> K;
	int a[105][105];
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			char c;
			cin >> c;
			a[i][j] = int(c - 'A');
		}
	}
	function<int(const int&)> countRects = [&] (const int& maxDifAllowed) -> int {
		int numRects = 0;
		for (int r2 = 0; r2 < M; ++r2) {
			for (int r1 = 0; r1 <= r2; ++r1) {
				int countCharacters[26]{};
				int countDifferentCharacters = 0;
				for (int c1 = 0, c2 = 0; c2 < N; ++c2) {
					for (int r = r1; r <= r2; ++r) {
						countDifferentCharacters += (++countCharacters[a[r][c2]] == 1);
					}
					while (c1 <= c2 && countDifferentCharacters > maxDifAllowed) {
						for (int r = r1; r <= r2; ++r) {
							countDifferentCharacters -= (--countCharacters[a[r][c1]] == 0);
						}
						++c1;
						// bug ở dòng 75
						// cập nhật chỉ số cột c1 ở sai lúc, sửa lại bằng cách cho ++c1 ra ngoài vòng lặp
						// đang cập nhật lại số kí tự khác nhau thì đừng cập nhật chỉ số cột
						// vì ta đang xét tại cột c1 mà vô tình cập nhật chỉ số cột trong lúc xét
						// dẫn đến việc ở hàng tiếp theo xét theo cột mới chứ không theo cột c1 cũ
						// rút kinh nghiệm
						// thao tác nào thì ghi rõ ở đó
						// đừng lồng nhau như bản 1D (bài SOPENP - Khai bút đầu xuân)
						// lồng nhau là rip
					}
					numRects += c2 - c1 + 1;
				}
			}
		}
		return numRects;
	};
	int countRectsLessThanOrEqualK = countRects(K);
	int countRectsLessThanK = countRects(K - 1);
	cout << countRectsLessThanOrEqualK - countRectsLessThanK;
}

int main() {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	int tt = 1;
	if (multitest) cin >> tt;
	for (int t = 0; t < tt; ++t) {
		solve();
	}
	return 0;
}
