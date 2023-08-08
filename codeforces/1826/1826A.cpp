#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int& x : a) cin >> x;
		sort(a.begin(), a.end());
		bool ok = 0;
		for(int i = 0; i < n; ++i){
			int c = a.end() - upper_bound(a.begin(), a.end(), i);
			if(i == c){
				cout << i << endl;
				ok = 1;
				break;
			}
		}
		if(!ok)
			cout << -1 << endl;
	}
	return 0;
}
