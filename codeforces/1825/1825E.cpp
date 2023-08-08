#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	int a[n + 1];
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	vector<vector<int>> g(n + 1);
	int x, y;
	for(int i = 1; i < n; ++i){
		cin >> x >> y;
		g[x].push_back(y);
	}
	int ans = 0;
	function<int(int)> dfs = [&](int cur) -> int {
		if(g[cur].size() == 0)
			return a[cur];
		int res = 0, index = 0;
		map<int, int> m;
		for(int ne : g[cur]){
			int t = dfs(ne);
			m[t] += 1;
			if(m[t] > res){
				res = m[t];
				index = t;
			}
		}
		ans += g[cur].size() - res;
		return a[cur] ^ index;
	};
	for(int ne : g[1]){
        int t = dfs(ne);
        if(t != a[1])
            ++ans;
    }
	cout << ans << endl;
	return 0;	
}
