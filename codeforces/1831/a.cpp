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
		vector<int> a(n);
		for(int& x : a){
			cin >> x;
			cout << n - x + 1 << ' ';
		}
		cout << "\n";
	}

	return 0;
}
