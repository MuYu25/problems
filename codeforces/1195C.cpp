#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	int n;
	cin >> n;
	vector<vector<ll>> a(n, vector<ll> (2));
	for(auto& x : a) cin >> x[0];
	for(auto& x : a) cin >> x[1];
	for(int i = 1; i < n; ++i){
		if(i == 1){
			a[i][0] += a[i-1][1];
			a[i][1] += a[i-1][0];
			continue;
		}
		a[i][0] += max(a[i-1][1], a[i-2][1]);
		a[i][1] += max(a[i-1][0], a[i-2][0]);
	}
	cout << max(a[n-1][0], a[n-1][1]) << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	// cin >> T;
	T = 1;
	while(T--){
		solve();
	}
	return 0;
}