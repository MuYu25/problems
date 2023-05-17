#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		// 必须去重
		a.resize(unique(a.begin(), a.end()) - a.begin());
		n = (int) a.size();
		int ans = 0;
		for(int i = 0; i < n; ++i){
			if(i == 0 || i == n - 1|| (a[i] > a[i-1]) == (a[i] > a[i+1])){
				ans += 1;
			}	
		}
		cout << ans << endl;
	}	
	return 0;
}
