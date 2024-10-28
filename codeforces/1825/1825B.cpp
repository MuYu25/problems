#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int T;
	cin >> T;
	while(T--){
		int N, M, n;
		cin >> N >> M;
		n = N * M;
		int a[n];
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		sort(a, a + n);
		ll ans = 0;
		ans = (ll)1 * (a[n-1] - a[0]) * (max(N, M) - 1) * min(N, M) + (a[n-2] - a[0]) * (min(N, M) - 1);
		ans = max(ans, (ll)1 * (a[n-1] - a[0]) * (max(N, M) - 1) * min(N, M) + (a[n-1] - a[1]) * (min(N, M) - 1));
		cout << ans << endl;
	}
	return 0;
}
