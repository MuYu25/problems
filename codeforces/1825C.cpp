#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n, m;
		cin >> n >> m;
		vector<int> a;
		int x, cnt1 = 0, cnt2 = 0;
		for(int i = 0; i < n; ++i){
			cin >> x;
			if(x == -1)
				++cnt1;
			else if(x == -2)
				++cnt2;
			else
				a.push_back(x);
		}
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
		int ans = 0;
		ans = max(ans, cnt1 + int(a.size()));
		ans = max(ans, cnt2 + int(a.size()));
		ans = min(ans, m);
		
		for(int i = 0; i < a.size(); ++i){
			int l = min(a[i] - 1, i + cnt1);
			int r = min(m - a[i], int(a.size()) - 1 - i + cnt2);
			ans = max(ans, l + r + 1);
		}
		cout << ans << endl;
	}
	return 0;
}
