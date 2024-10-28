#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n, k;
		cin >> n >> k;
		ll a[n+1];
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; ++i){
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; ++i){
			a[i] += a[i-1];	
		}
		ll ans = 0;
		for(int j = 0; j <= k; ++j){
			ans = max(ans, a[n - j] - a[2 * (k - j)]);
		}
		cout << ans << endl;
	}
	return 0;
}
