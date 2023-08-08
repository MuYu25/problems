#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = n - 1; i >= 0; --i){
		cin >> a[i];
	}
	if(a[0] > 0){
		cout << "NO" << '\n';
	}else{
		cout << "YES" << '\n';
		for(int i = 0; i < n; ){
			int st = i;
			while(i < n && a[i] == 0){
				++i;
			}
			int st2 = i;
			while(i < n && a[i] == 1){
				++i;
			}
			for(int j = 1; j < i - st; ++j)
				cout << 0 << ' ';
			cout << i - st2 << ' ';
		}
		cout << "\n";
	}
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