#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		int n = s.length();
		vector<int> suf(n);
		suf[n-1] = s[n-1] - 'A';
		for(int i = n - 2; i >= 0; --i){
			suf[i] = max(s[i] - 'A', suf[i+1]);
		}
		ll ans = 0;
		ll tmp = 0, mx = 0;
		for(int i = 0; i < n; ++i){
			int t = s[i] - 'A';
			if(t < suf[i]){
				ans -= pow(10, t);
			}else{
				ans += pow(10, t);
			}
		}
		for(int i = 0; i < n; ++i){
			int t = s[i] - 'A';
			if(t < 4){
				mx = max(mx, (ll)(pow(10, 4) - (t >= suf[i] ? -pow(10, t) : pow(10, t))) - tmp);
				if(t >= suf[i]){
					tmp += pow(10, t);	
				}
			}
		}
		cout << ans + mx << '\n';
	}
	return 0;
}