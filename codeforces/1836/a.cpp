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
		bool ok = 1;
		vector<int> cnt(101, 0);
		for(int& x : a){
			cin >> x;
			++cnt[x];
		}
		for(int i = 1; i <= 100; ++i){
			if(cnt[i] == 0) break;
			if(cnt[i] <= cnt[i-1]){
				ok = 0;
			}else{
				ok = 1;
			}
		}
		if(ok) {
			cout << "NO" << '\n';
		}else
		cout << "YES" << '\n';
	}


	return 0;
}
