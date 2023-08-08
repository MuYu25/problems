#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int a, b, k;
	cin >> a >> b >> k;
	vector<int> arr{a - 1};
	vector<bool> vis(b + 1, 0);
	for(ll i = 2; i <= b; ++i){
		if(!vis[i]){
			if(i >= a){
				arr.emplace_back(i);
			}
			for(ll j = i * i; j <= b; j += i){
				vis[j] = 1;
			}
		}
	}
	arr.emplace_back(b + 1);
	int m = arr.size();
	if(m - 2 < k){
		cout << -1 << "\n";
		return 0;
	}
	int ans = 0;
	for(int i = k; i < m; ++i){
		ans = max(ans, arr[i] - arr[i-k]);
	}
	cout << ans << "\n";
	return 0;
}
