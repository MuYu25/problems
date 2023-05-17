#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		if(s[i] == '0'){
			++cnt;
			while(i + 1 < n && s[i+1] == '0')
				++i;	
		}
	}
	ll ans = 0;
	if(cnt == 0){
		cout << 0 << endl;
		return 0;
	}
	ans = (ll)1 * (cnt - 1) * a + b;
	ans = min(ans,(ll)1 *  b * cnt);
	cout << ans << endl;
	return 0;
}
