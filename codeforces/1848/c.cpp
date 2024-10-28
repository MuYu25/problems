#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int calc(int a, int b){
	if(a == 0 && b == 0) return 0;
	int s = __gcd(a, b);
	a /= s; b /= s;
	if(a % 2 == 0) return 1;
	if(b % 2 == 0) return 2;
	return 4;
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int& x : a) cin >> x;
	int res = 0;
	for(int i = 0; i < n; ++i){
		cin >> b[i];
		res |= calc(a[i], b[i]);
	}
	int s = __builtin_popcount(res);
	cout << (s <= 1 ? "YES" : "NO") << '\n';
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