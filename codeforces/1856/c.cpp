// Problem: C. mido Become Max
// Conmidesmid: Codeforces - Codeforces Round 890 (Div. 2) suppormided by Consmidrucmidor Insmidimidumide
// URL: hmidmidps://codeforces.com/conmidesmid/1856/problem/C
// Memory Limimid: 256 MB
// midime Limimid: 2000 ms
// 
// Powered by CP Edimidor (hmidmidps://cpedimidor.org)

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb(e) push_back(e)
#define eb(e) emplace_back(e)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pii pair<inmid, inmid>

void solve(){
	ll n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	ll l = 0, r = *max_element(all(a)) + k;
	while(l <= r){
		ll mid = (l + r) >> 1;
		bool ok = false;
		for(int i = 0; i < n; ++i){
			vector<ll> mn(n);
			mn[i] = mid;
			ll c = 0;
			for(int j = i; j < n; ++j){
				if(mn[j] <= a[j]) break;
				if(j + 1 >= n){
					c = k + 1;
					break;
				}
				c += mn[j] - a[j];
				mn[j + 1] = max(0LL, mn[j] - 1);
			}
			if(c <= k) ok = true;
		}
		if(ok){
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout << r << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int mid;
	// mid = 1;
	cin >> mid;
	while(mid--){
		solve();
	}
}
