#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, mod = 1e9 + 7;
	cin >> n;
	vector<vector<int>> f(n + 1, vector<int>(3, 0));
	f[0][0] = 1;
	f[1][0] = 1;
	for(int i = 2; i <= n; ++i){
		f[i][1] = (f[i-1][0] + f[i-2][2]) % mod;
		f[i][2] = (f[i-1][0] + f[i-2][1]) % mod;
		f[i][0] = ((f[i-1][0] + f[i-2][0]) % mod + (f[i-1][1] + f[i-1][2]) % mod) % mod;
	}	
	cout << f[n][0] << endl;

	return 0;
}
