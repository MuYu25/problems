#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int solve(vector<int>& a){
	vector<int> b;
	for(int i = 1; i < a.size(); ++i){
		b.push_back(a[i] - a[i-1]);
	}
	sort(b.rbegin(), b.rend());
	if(b.size() == 1) return b[0] - 1;
	return max((b[0] - 1) / 2, b[1] - 1);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n, k;
		cin >> n >> k;
		vector<vector<int>> a(k + 1, vector<int> {0});
		for(int i = 1; i <= n; ++i){
			int x; 
			cin >> x;
			a[x].push_back(i);
		}
		int ans = 0x3f3f3f;
		for(int i = 1; i <= k; ++i){
			a[i].push_back(n + 1);
			ans = min(ans, solve(a[i]));
		}
		cout << ans << '\n';
	}
	return 0;
}