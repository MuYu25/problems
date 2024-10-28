#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<unordered_map<int, int>> fa(m);
	function<int(int, int)> find = [&](int c, int x) -> int{
		if(!fa[c].count(x)){
			fa[c][x] = x;
		}
		if(fa[c][x] != x){
			fa[c][x] = find(c, fa[c][x]);
			return fa[c][x];
		}
		return x;
	};
	for(int i = 0; i < m; ++i){
		int v, w, c;
		cin >> v >> w >> c;
		--c;
		v = find(c, v);
		w = find(c, w);
		fa[c][v] = w;
	}
	int q;
	cin >> q;
	while(q--){
		int x, y;
		cin >> x >> y;
		int cnt = 0;
		for(int j = 0; j < m; ++j){
			if(find(j, x) == find(j, y)){
				++cnt;
			}
		}
		cout << cnt << "\n";	
	}
	return 0;
}
