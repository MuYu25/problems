#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		map<int, int> m;
		for(int& x : a) cin >> x;
		for(int& x : b) cin >> x;
		int ans = 1;
		for(int i = 0, j = 0; i < n; ++i){
			j = i;
			while(j < n && a[j] == a[i]){
				++j;
			}
			if(m.count(a[i])){
				m[a[i]] = max(m[a[i]], j - i);
			}else{
				m[a[i]] = j - i;
			}
			ans = max(ans, m[a[i]]);
			i = j - 1;
		}
		for(int i = 0, j = 0; i < n; ++i){
			j = i;
			while(j < n && b[j] == b[i]){
				++j;
			}
			if(m.count(b[i])){
				ans = max(ans, j - i + m[b[i]]);
			}else{
				ans = max(ans, j - i);
			}
			i = j - 1;
		}
		// for(auto it = m.begin(); it != m.end(); ++it){
		//	cout << it->first << ' ' << it->second << "\n";
		// }
		// cout << "\n" << "\n";
		cout << ans << "\n";
	}

	return 0;
}
