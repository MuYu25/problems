#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	ll ans = 1;
	ans *= k;
	for(int i = 1; i < n; ++i){
		ans *= (k - 1);
	}
	cout << ans << '\n';
	return 0;
}