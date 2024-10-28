#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	int n, m, k, a, b, ok = 0;
	cin >> n >> m >> k >> a >> b;
	int s = (a + b) % 2;
	for(int i = 0; i < k; ++i){
		cin >> a >> b;
		if((a + b) % 2 == s) ok = 1;
	}
	cout << (ok ? "NO" : "YES") << '\n';
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}