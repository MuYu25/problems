#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int a[n + 1];
		for(int i = 1; i <= n; ++i)
			cin >> a[i];
		int l = 1, r = n;
		int ans = a[n] - a[1];
		while(l < r){
			ans = __gcd(ans, abs(a[r] - a[l]));
			--r;
			++l;
		}
		cout << ans << endl;
	}	
	return 0;
}
