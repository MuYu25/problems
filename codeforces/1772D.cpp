// Problem: D. Absolute Sorting
// Contest: Codeforces - Codeforces Round 839 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1772/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb(e) push_back(e)
#define all(x) x.begin(),x.end()

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	int l = 0, r = 1e9;
	for(int i = 1; i < n; ++i){
		if(a[i] > a[i-1]) r = min(r, (a[i] + a[i-1]) / 2);
		else if(a[i] < a[i-1]) l = max(l, (a[i] + a[i-1] + 1) / 2);
	}
	cout << (l <= r ? l : -1) << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	// T = 1;
	cin >> T;
	while(T--){
		solve();
	}
}