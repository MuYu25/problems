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
		vector<int> b(n-1), a;
		for(int& x : b){
			cin >> x;
		}
		a.emplace_back(b[0]);
		for(int i = 0; i < n - 2; ++i){
			a.emplace_back(min(b[i], b[i+1]));
		}
		a.emplace_back(b[n-2]);
		for(int x : a) cout << x << " ";
		cout << endl;
	}
	return 0;
}
