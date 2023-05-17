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
		vector<int> a(n + 1, 0);
		for(int i = 1; i <= n; ++i)
			cin >> a[i];
		vector<vector<int>> f(n + 1, vector<int> (3, 0));
		for(int i = 1; i <= n; ++i){
			f[i][2] = max(f[i-1][2], f[i-1][1] + a[i] - i);
			f[i][1] = max(f[i-1][1], f[i-1][0] + a[i]);
			f[i][0] = max(f[i-1][0], a[i] + i);
		}
		cout << f[n][2] << endl;
	}
	return 0;
}
