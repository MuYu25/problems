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
		string ans = "";
		for(int i = 0; i < n; ++i){
			int j = i + 1;
			while(j < n && s[j] != s[i]){
				++j;
			}
			ans += s[i];
			i = j;
		}
		cout << ans << '\n';
	}
	return 0;
}