#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	vector<bool> vis(100001, false);
	for(ll i = 2; i <= 100000; ++i){
		if(!vis[i]){
			for(ll j = i * i; j <= 1000000; j += i){
				vis[j] = true;
			}
		}
	}
	while(T--){
		int n;
		cin >> n;

	}
	return 0;
}
