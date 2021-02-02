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
const string yes="YES",no="NO";
const int MOD=1e9+7; //998244353
const ll INF = 1e18; //Not too close to LLONG_MAX

int dp[100001][21][3];
int moves[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif // LOCAL
/*
    Problem Statement: http://www.usaco.org/index.php?page=viewproblem2&cpid=694
    Đầu tiên, hãy đọc official analysis ở đây: http://www.usaco.org/current/data/sol_hps_gold_jan17.html
    gọi dp[N][K][state] là mảng dp với:
    - N là số trận thắng
    - K là số lần đổi trạng thái Kéo - Búa - Bao
    - state ở đây là trạng thái Kéo - Búa - Bao
    Theo đề bài, ta có maxN = 100000, maxK = 20 và state = 3; vì thế ta tạo mảng
    dp[maxN][maxK][state] = dp[100001][21][3];
    Theo dạng knapsack kinh điển, ta có công thức truy hồi như sau:
    dp(n,k,state) = max(dp(n-1,k,state), dp(n-1,k-1,other_state1), dp(n-1,k-1,other_state2) + (state == moves[n-1]);
    giải thích:
    số trận thắng tối đa sau khi chơi n ván và đổi k lần bằng max 1 trong 3 TH sau
    - Số trận thắng tối đa sau khi chơi n-1 ván, đổi k lần (nghĩa là từ lượt n-1 sang n đ đổi gesture)
    - Số trận thắng tối đa sau khi chơi n-1 ván, đổi k lần (nghĩa là từ lượt n-1 sang n CÓ đổi gesture sang 1 trong 2 cái còn lại)
    - Lưu ý là có cộng thêm 1 cho số trận thắng nếu trạng thái hiện tại == lượt đi của ông John (nghĩa là cái state counter John's move)
    ...
    Không nói nhiều nữa, giải thôi
*/
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    int N,K;
    cin >> N >> K;
    F0R(i,N) {
        char c; cin >> c;
        if (c == 'H') moves[i] = 0;
        else if (c == 'P') moves[i] = 1;
        else moves[i] = 2;
    }
    //Dễ thấy dp[0][K][state] = 0 vì đ đánh trận nào thì sao win lmao
    //Ngoài ra, dp[N][0][state] = dp[N-1][0][state] + (state == moves[N-1])
    //(Vì đổi 0 lần nên số trận thắng hiện tại phụ thuộc HOÀN TOÀN vào số trận thắng N-1 game trước đó và việc lượt hiện tại
    // có chơi counter với John's move hay không
    FOR(n,1,N+1) F0R(k,K+1) F0R(state,3) {
        if (k == 0){ //Chưa đổi lần nào
            dp[n][k][state] = dp[n-1][k][state] + (state == moves[n-1]);
        }
        else{ //Kéo lên trên để đọc công thức truy hồi nếu quên.
            int other_state1 = (state + 1) % 3;
            int other_state2 = (state + 2) % 3;
            dp[n][k][state] = max(dp[n-1][k][state], max(dp[n-1][k-1][other_state1], dp[n-1][k-1][other_state2])) + (state == moves[n-1]);
        }
    }
    //Nên nhớ là đáp án của bài này có thể là 1 trong 3 trường hợp:
    //Hoặc là lần đổi cuối là state 1, hoặc state 2, hoặc state 3
    //Cho nên ta in max của 3 cái dp[N][K][state]
    //Nhớ nhé.
    cout << max(max(dp[N][K][0], dp[N][K][1]), dp[N][K][2]);
	return 0;
}
