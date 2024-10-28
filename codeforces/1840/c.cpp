#include<bits/stdc++.h>

using namespace std;

// #define int long long
typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n, k ,q;
		cin >> n >> k >> q;
		vector<int> a(n);
		int cnt = 0;
		for(int& x : a){
			cin >> x;
		}
		ll ans = 0;
		for(int i = 0; i < n; ++i){
			if(a[i] <= q){
				int j = i;
				while(j < n && a[j] <= q){
					j += 1;
				}
				if(j - i >= k){
					ans += (ll)1 * (j - i - k + 1) * (j - i - k + 2) / 2;
				}
				i = j - 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}