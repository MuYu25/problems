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
		string s;
		cin >> s;
		int ans = 1;
		int cnt = 1;
		for(int i = 1; i < n; ++i){
			if(s[i] == s[i-1]){
				++cnt;
				ans = max(ans, cnt);
			}else{
				cnt = 1;
			}
		}
		cout << ans + 1 << "\n";
	}
	return 0;
}
