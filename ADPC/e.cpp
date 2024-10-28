#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	vector<int> a;
	for(int i = 1; i < n; ++i){
		if(s[i] == s[0]){
			a.push_back(i);
		}
	}
	ll ans = n;
	for(int i = 0; i < a.size(); ++i){
		int j = a[i];
		while(j < n && s[j - a[i]] == s[j]){
			++j;
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}