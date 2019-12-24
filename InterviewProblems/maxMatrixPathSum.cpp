#include <bits/stdc++.h>
using namespace std;

int maxPathSum(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &dp, vector<vector<int>> &moves) {
	if (j < 0 || i >= mat.size() || j >= mat[i].size()) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	int maxAns = -(1 << 30);
	for (auto &move : moves) {
		maxAns = max(maxAns, mat[i][j] + maxPathSum(mat, i + move[0], j + move[1], dp, moves));
	}
	return dp[i][j] = maxAns;
}

int main() {
	int t, n;
	vector<vector<int>> moves = {
		{1, 0},
		{1, 1},
		{1, -1}
	};
	cin >> t ;
	while (t--) {
		cin >> n;
		vector<vector<int>> mat(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mat[i][j];
			}
		}
		vector<vector<int>> dp(n, vector<int>(n, -1));
		int ans = -(1 << 30);
		for (int j = 0; j < mat[0].size(); j++) {
			ans = max(ans, maxPathSum(mat, 0, j, dp, moves));
		}
		cout << ans << endl;
	}
	return 0;
}