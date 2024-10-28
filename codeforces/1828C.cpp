#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for(int& x : a) cin >> x;
		for(int& x : b) cin >> x;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		ll ans = 1;
		int c = 0;
		for(int i = n - 1; i >= 0; --i){
			int r = a.end() - upper_bound(a.begin(), a.end(), b[i]);
			ans = (ans * (r - c)) % mod;
			++c;
		}
		cout << ans << '\n';
	}
	return 0;
}
