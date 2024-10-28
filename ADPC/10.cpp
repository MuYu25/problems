#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


ll solution(string S, string T) {
        int n = S.size(), m = T.size();
        vector<vector<ll>> dp(n+1, vector<ll>(m+1, 1)); // 初始化 dp 数组
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (S[i-1] == T[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string s1, s2;
	cin >> s1 >> s2;
	cout << solution(s1, s2) << "\n";
	return 0;
}