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
		sort(a.begin(), a.end());

		function<bool(int)> check = [&](int x) -> bool{
			int cnt = 1;
			int cur = a[0];
			for(int i = 0; i < n; ++i){
				if(a[i] - cur >  2 * x){
					cur = a[i];
					cnt += 1;
				}
			}
			return cnt <= 3;
		};
		
		int l = 0, r = a[n-1];
		while(l <= r){
			int mid = (l + r) >> 1;
			if(check(mid)) r = mid - 1;
			else l = mid + 1;
		}
		cout << l << '\n';
	}

	return 0;
}