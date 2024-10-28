#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, s;
	cin >> n >> m >> s;
	vector<vector<int>> g(n + 1);
	for(int i = 0; i < n - 1; ++i){
		int x, y;
		cin >> x >> y;
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	int ans = 0;
	int i, j;
	function<bool(int, int)> dfs = [&](int x, int fa) -> bool {
		bool res = true;
		for(auto y : g[x]){
			if(y != fa){
				res = res && dfs(y, x);	
			}
		}
		if(res || (x == i || x == j) && res){
			ans = x;
			return false;
		}
		return x == i || x == j;
	};
	while(m--){
		cin >> i >> j;
		ans = 0;
		dfs(s, 0);
		cout << ans << "\n";
	}

	return 0;
}