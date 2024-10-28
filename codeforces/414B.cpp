#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int mod = 1e9 + 7;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int u, n;
	cin >> u >> n;
	vector<ll> f(u + 1);
	f[1] = 1;
	for(int i = 0; i < n; ++i){
		for(int j = u; j > 0; --j){
			for(int k = j + j; k <= u; k += j){
				f[k] = (f[k] + f[j]) % mod;
			}
		}
	}
	ll ans = 0;
	for(auto c : f){
 		ans = (ans + c) % mod;
	}
	cout << ans << "\n";
	return 0;
}
