#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<vector<int>> f(n + 1, vector<int> (3, n));
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		if((a[i] & 1) == 1){
			f[i][1] = min(f[i-1][0], f[i-1][2]) - 1;
		}
		if(((a[i] >> 1) & 1) == 1){
			f[i][2] = min(f[i-1][0], f[i-1][1]) - 1;
		}
		f[i][0] = min(f[i-1][0], min(f[i-1][1], f[i-1][2]));
	
	}
	cout << min(f[n][0], min(f[n][1], f[n][2])) << '\n';
	return 0;
}