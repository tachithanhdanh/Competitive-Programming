class Solution {
public:
	using vi = vector<int>;
	using vvi = vector<vi>;
	#define sz(x) int((x).size())
	vvi matrixBlockSum(vvi& mat, int k) {
		vvi pre(sz(mat)+10,vi(sz(mat[0])+10));
		for (int i = 1; i <= sz(mat); ++i)
			for (int j = 1; j <= sz(mat[0]); ++j) 
				pre[i][j] = mat[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
		vvi ans(sz(mat),vi(sz(mat[0])));
		for (int i = 1; i <= sz(mat); ++i) {
			for (int j = 1; j <= sz(mat[0]); ++j) {
				int U, D, L, R;
				U = max(1,i-k);
				D = min(sz(mat),i+k);
				L = max(1,j-k);
				R = min(sz(mat[0]),j+k);
				ans[i-1][j-1] = pre[D][R] - pre[D][L-1] - pre[U-1][R] + pre[U-1][L-1];
			}
		}
		return ans;
	}
};