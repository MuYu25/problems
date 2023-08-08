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
		vector<ll> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		vector<ll> f{-0x3f3f3f3f, -0x3f3f3f3f};
		ll ans = -0x3f3f3f3f;
		for(int i = 0; i < n; ++i){
			f[i % 2] = max(a[i], f[i % 2] + a[i]);
			ans = max(ans, f[i]);
		}
		return ans;
	}
	return 0;
}
