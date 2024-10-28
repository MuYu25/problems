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
		vector<int> a(n);
		for(int& x : a){
			cin >> x;
		}
		bool ok = 0;
		int ans = -1;
		for(int i = 0; i < n; ++i){
			if(a[i] < 0){
				ok = 1;
				ans = a[i];
				break;
			}
			ans = max(ans, a[i]);
		}
		cout << ans << "\n";
	}

	return 0;
}