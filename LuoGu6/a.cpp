#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll s1, s2;
	cin >> s1 >> s2;
	if(s2 / (ll)1e11 == 0){
		cout << ((ll)1e11 + s1 - s2) << '\n';
	}else{
		s2 %= (ll)1e6;
		ll ans = abs(s2 - s1);
		ans = min(ans, abs(s2 + (ll)1e6 - s1));
		cout << ans << '\n';
	}
	return 0;
}