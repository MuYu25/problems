#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<vector<pair<int, int>>> a(n);
		vector<int> e(n), f(n);
		// e[0] = n;
		for(int i = 0; i < n - 1; ++i){
			int u, v;
			cin >> u >> v;
			--u; --v;
			a[u].emplace_back(v, i);
			a[v].emplace_back(u, i);
		}
		function<void(int, int)> dfs = [&](int x, int fa){
			for(auto [y, i] : a[x]){
				if(y == fa){
					continue;
				}
				e[y] = i;
				f[y] = f[x] + (e[y] < e[x]);
				dfs(y, x);
			}
		};
		dfs(0, -1);
		auto ans = *max_element(f.begin(), f.end());
		cout << ans + 1 << "\n";
	}

	return 0;
}
