#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n, k;
		cin >> n >> k;
		int ans = 2;
		ans += (n - 2) / k; 
		cout << ans << "\n";
	}

	return 0;
}