#include<bits/stdc++.h>

using namespace std;


typedef long long ll;


void solve(){
	int n;
	cin >> n;
	// 如果需要继承之前的状态,还是滚动数组好一点.
	vector<vector<int>> f(26, vector<int> (26, 0));
	for(int i = 1; i <= n; ++i){
		string s;
		cin >> s;
		int start = s[0] - 'a', m = s.size(), end = s[m-1] - 'a';
		for(int j = 0; j < 26; ++j){
			f[j][end] = max(f[j][end], f[j][start] + m);
		}
		f[start][end] = max(f[start][end], m);
	}
	int ans = 0;
	for(int i = 0; i < 26; ++i){
		ans = max(ans, f[i][i]);
	}
	cout << ans << '\n';
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr);
	int T;
	// cin >> T;
	T = 1;
	while(T--){
		solve();
	}
	return 0;
}