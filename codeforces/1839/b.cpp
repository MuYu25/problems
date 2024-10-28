#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


void solution(){
	int n;
	cin >> n;
	vector<vector<int>> a(n + 1);
	for(int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		a[x].emplace_back(y);
	}
	for(int i = 0; i < n; ++i){
		sort(a[i].rbegin(), a[i].rend());
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++i){
		if(!a[i].empty()){
			for(int j = 0; j < min((int)a[i].size(), i); ++j){
				ans += a[i][j];
			}
		}
	}
	cout << ans << '\n';
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		solution();
	}
	return 0;
}